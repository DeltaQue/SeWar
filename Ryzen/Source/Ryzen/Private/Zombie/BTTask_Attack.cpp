// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_Attack.h"


/* AI Module includes */
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"



EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	MyController = Cast<AZombieAIController>(OwnerComp.GetAIOwner());
	MyCharacter = Cast<AZombieCharacter_2>(MyController->GetPawn());
	
	AttackCooltime = 1.5f;
	
	if (MyCharacter == nullptr && MyController->GetIsAttackCollisionOverlap() == false)
	{
		return EBTNodeResult::Failed;
	}

	if (MyController->GetIsAttackCollisionOverlap())
	{
		TimerHandle_AttackTimer.Invalidate();

		GetWorld()->GetTimerManager().SetTimer(TimerHandle_AttackTimer, this, &UBTTask_Attack::ReTriggerAttack, AttackCooltime, true);

		return EBTNodeResult::InProgress;
	}
	else
		return EBTNodeResult::Failed;
}

void UBTTask_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	if (!MyController->GetIsAttackCollisionOverlap())
	{
		QuitTask();
	}
}

void UBTTask_Attack::ReTriggerAttack()
{
	TArray<AActor*> OverlapActor;
	//Attack Collision에 Timer가 ReTriggerAttack을 실행 할 때 마다, Overlap된 액터를 집어넣음
	MyCharacter->GetAttackCollisionComp()->GetOverlappingActors(OverlapActor, ARyzenBaseCharacter::StaticClass());
	for (int32 i = 0; i < OverlapActor.Num(); i++)
	{
		ARyzenBaseCharacter* OverlappingPawn = Cast<ARyzenBaseCharacter>(OverlapActor[i]);
		if (OverlappingPawn)
		{
			MyCharacter->ScratchAttack(OverlappingPawn);
		}
	}
	if (OverlapActor.Num() == 0)
	{
		TimerHandle_AttackTimer.Invalidate();
	}
}

EBTNodeResult::Type UBTTask_Attack::QuitTask()
{
	return EBTNodeResult::Failed;
}