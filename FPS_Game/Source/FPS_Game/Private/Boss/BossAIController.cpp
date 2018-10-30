// Fill out your copyright notice in the Description page of Project Settings.

#include "BossAIController.h"
#include "FPS_Game.h"
#include "BossCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"



ABossAIController::ABossAIController(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	BehaviorTreeComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
	BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));

	TargetEnemyKeyName = "Enemy";
	PatrolLocationKeyName = "PatrolLocation";
	BossTypeKeyName = "BossType";
	AttackAbleKeyName = "AttackAble";
}

void ABossAIController::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);

	ABossCharacter* BossBot = Cast<ABossCharacter>(InPawn);
	if (BossBot)
	{
		if (BossBot->BehaviorTree && BossBot->BehaviorTree->BlackboardAsset)
		{
			if (BossBot->BehaviorTree->BlackboardAsset)
			{
				BlackboardComp->InitializeBlackboard(*BossBot->BehaviorTree->BlackboardAsset);

				SetBossType(BossBot->BossType);
			}

			BehaviorTreeComp->StartTree(*BossBot->BehaviorTree);
		}
	}

	BehaviorTreeComp->StartTree(*BossBot->BehaviorTree);
}

void ABossAIController::UnPossess()
{
	Super::UnPossess();

	BehaviorTreeComp->StopTree();
}

AActor* ABossAIController::GetSeeingPawn()
{
	//Return the seeing pawn
	UObject* object = BlackboardComp->GetValueAsObject(TargetEnemyKeyName);

	return object ? Cast<AActor>(object) : nullptr;
}



void ABossAIController::SetTargetEnemy(APawn* NewTarget)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(TargetEnemyKeyName, NewTarget);
	}
}

void ABossAIController::SetPatrolLocation(FVector NewLocation)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsVector(PatrolLocationKeyName, NewLocation);
	}
}

void ABossAIController::SetBossType(EBossType NewType)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsEnum(BossTypeKeyName, (uint8)NewType);
	}
}

void ABossAIController::SetAttackAble(bool IsValid)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsBool(AttackAbleKeyName, IsValid);
	}
}




APlayerCharacter* ABossAIController::GetTargetEnemy() const
{
	if (BlackboardComp)
	{
		return Cast<APlayerCharacter>(BlackboardComp->GetValueAsObject(TargetEnemyKeyName));
	}

	return nullptr;
}

bool ABossAIController::GetAttackAble() const
{
	return BlackboardComp->GetValueAsBool(AttackAbleKeyName);
}