// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "ZombieAIController.h"
#include "ZombieCharacter_2.h"
#include "RyzenBaseCharacter.h"

/* AI Specific includes */
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"


AZombieAIController::AZombieAIController(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	BehaviorComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
	BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));

	/* Blackboard Å°°ª°ú ¸ÅÄª */
	PatrolLocationKeyName = "PatrolLocation";
	CurrentWaypointKeyName = "CurrentWaypoint";
	BotTypeKeyName = "BotType";
	TargetEnemyKeyName = "TargetEnemy";
	ReconLocationKeyName = "ReconLocation";
	IsArriveKeyName = "IsArrive";
}


void AZombieAIController::Possess(class APawn* InPawn)
{
	Super::Possess(InPawn);

	AZombieCharacter_2* ZombieBot = Cast<AZombieCharacter_2>(InPawn);
	if (ZombieBot)
	{
		if (ZombieBot->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*ZombieBot->BehaviorTree->BlackboardAsset);

			/* Make sure the Blackboard has the type of bot we possessed */
			//SetBlackboardBotType(ZombieBot->BotType);
		}

		BehaviorComp->StartTree(*ZombieBot->BehaviorTree);
		SetIsArrive(true);
	}
}


void AZombieAIController::UnPossess()
{
	Super::UnPossess();

	/* Stop any behavior running as we no longer have a pawn to control */
	BehaviorComp->StopTree();
}


void AZombieAIController::SetWaypoint(AWaypoint* NewWaypoint)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(CurrentWaypointKeyName, NewWaypoint);
	}
}


void AZombieAIController::SetTargetEnemy(APawn* NewTarget)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(TargetEnemyKeyName, NewTarget);
	}
}


AWaypoint* AZombieAIController::GetWaypoint() const
{
	if (BlackboardComp)
	{
		return Cast<AWaypoint>(BlackboardComp->GetValueAsObject(CurrentWaypointKeyName));
	}

	return nullptr;
}

FVector AZombieAIController::GetReconLocation() const
{
	if (BlackboardComp)
	{
		return FVector(BlackboardComp->GetValueAsVector(ReconLocationKeyName));
	}

	return FVector(-1,-1,-1);
}

ARyzenBaseCharacter* AZombieAIController::GetTargetEnemy() const
{
	if (BlackboardComp)
	{
		return Cast<ARyzenBaseCharacter>(BlackboardComp->GetValueAsObject(TargetEnemyKeyName));
	}

	return nullptr;
}

bool AZombieAIController::GetIsArrive() const
{
	if (BlackboardComp)
	{
		return BlackboardComp->GetValueAsBool(IsArriveKeyName);
	}

	return false;
}

bool AZombieAIController::GetIsAttackCollisionOverlap() const
{
	if (BlackboardComp)
	{
		return BlackboardComp->GetValueAsBool(IsAttackCollisionOverlapKeyName);
	}

	return false;
}



void AZombieAIController::SetBlackboardZombieType(EZombieType NewType)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsEnum(BotTypeKeyName, (uint8)NewType);
	}
}

void AZombieAIController::SetReconLocation(FVector vector) 
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsVector(ReconLocationKeyName, vector);
	}
}

void AZombieAIController::SetIsArrive(bool Arrive)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsBool(IsArriveKeyName, Arrive);
	}
}

void AZombieAIController::SetIsAttackCollisionOverlap(bool Overlaped)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsBool(IsAttackCollisionOverlapKeyName, Overlaped);
	}
}