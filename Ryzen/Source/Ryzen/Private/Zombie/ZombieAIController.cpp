// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "ZombieAIController.h"
#include "ZombieCharacter_2.h"

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


AWaypoint* AZombieAIController::GetWaypoint()
{
	if (BlackboardComp)
	{
		return Cast<AWaypoint>(BlackboardComp->GetValueAsObject(CurrentWaypointKeyName));
	}

	return nullptr;
}


ARyzenBaseCharacter* AZombieAIController::GetTargetEnemy()
{
	if (BlackboardComp)
	{
		return Cast<ARyzenBaseCharacter>(BlackboardComp->GetValueAsObject(TargetEnemyKeyName));
	}

	return nullptr;
}


//void AZombieAIController::SetBlackboardBotType(EBotBehaviorType NewType)
//{
//	if (BlackboardComp)
//	{
//		BlackboardComp->SetValueAsEnum(BotTypeKeyName, (uint8)NewType);
//	}
//}
