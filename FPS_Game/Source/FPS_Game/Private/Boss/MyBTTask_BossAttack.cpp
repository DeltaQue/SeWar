// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBTTask_BossAttack.h"
#include "BossCharacter.h"
#include "BossAIController.h"
#include "PlayerCharacter.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "Engine.h"

/* AI Module includes */
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"



EBTNodeResult::Type UMyBTTask_BossAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ABossAIController* BossController = Cast<ABossAIController>(OwnerComp.GetAIOwner());
	ABossCharacter* BossCharacter = Cast<ABossCharacter>(BossController->GetPawn());
	
	

	if (BossCharacter == nullptr && BossController->GetTargetEnemy() == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	int AttackType = FMath::FRandRange(0, 2);

	float Duration = BossCharacter->PlayAttackAnimMontage(AttackType);

	if (BossController->GetAttackAble() == true)
	{
		if (Duration != 0.0f
			&& BossController->GetTargetEnemy() != nullptr)
		{
			APlayerCharacter* Player = Cast<APlayerCharacter>(BossController->GetTargetEnemy());

			FPointDamageEvent DmgEvent;
			DmgEvent.DamageTypeClass = BossCharacter->GetAttackDamageType();
			DmgEvent.Damage = BossCharacter->GetAttackDamage(AttackType);

			FTimerHandle TimerHandle_AttackTimer;
			GetWorld()->GetTimerManager().SetTimer(TimerHandle_AttackTimer, this, &UMyBTTask_BossAttack::AttackFinish, Duration, true);
			
			if (IsFinish == true)
			{
				IsFinish = false;
				return EBTNodeResult::Succeeded;
			}

			//Player->TakeDamage(DmgEvent.Damage, DmgEvent, BossController, BossCharacter);
			
		}
	}

	return EBTNodeResult::Failed;
}


void UMyBTTask_BossAttack::AttackFinish()
{
	IsFinish = true;
}



