// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCController.h"
#include "NPCCharacter.h"




/* AI Specific includes */
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"

ANPCController::ANPCController(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	BehaviorComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
	BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));

	/* Blackboard Å°°ª°ú ¸ÅÄª */
	PatrolLocationKeyName = "PatrolLocation";
	CurrentWaypointKeyName = "CurrentWaypoint";
	TargetEnemyKeyName = "TargetEnemy";
	TargetPlayerKeyName = "TargetPlayer";
	NPCPersonalityKeyName = "NPCPersonality";
	SafetyZoneLocationKeyName = "SafetyZoneLocation";


}


void ANPCController::Possess(class APawn* InPawn)
{
	Super::Possess(InPawn);

	ANPCCharacter* NPCBot = Cast<ANPCCharacter>(InPawn);
	if (NPCBot)
	{
		if (NPCBot->BehaviorTree && NPCBot->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*NPCBot->BehaviorTree->BlackboardAsset);

			SetPersonality(NPCBot->Personality);
		}

		SetSafetyZoneLocation(FVector(2280.0f, 750.0f, 170.0f));
		BehaviorComp->StartTree(*NPCBot->BehaviorTree);
	}
}


void ANPCController::UnPossess()
{
	Super::UnPossess();

	BehaviorComp->StopTree();
}


void ANPCController::SetWaypoint(AWaypoint* NewWaypoint)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(CurrentWaypointKeyName, NewWaypoint);
	}
}



void ANPCController::SetTargetEnemy(APawn* NewTarget)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(TargetEnemyKeyName, NewTarget);
	}
}

void ANPCController::SetTargetPlayer(APawn* NewTarget)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(TargetPlayerKeyName, NewTarget);
	}
}

void ANPCController::SetPersonality(ENPCPersonality NPCPersonality)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsEnum(NPCPersonalityKeyName, (uint8)NPCPersonality);
	}
}

void ANPCController::SetSafetyZoneLocation(FVector location)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsVector(SafetyZoneLocationKeyName, location);
	}
}
///////////////////////////////


AWaypoint* ANPCController::GetWaypoint() const
{
	if (BlackboardComp)
	{
		return Cast<AWaypoint>(BlackboardComp->GetValueAsObject(CurrentWaypointKeyName));
	}

	return nullptr;
}

ANPCCharacter* ANPCController::GetTargetEnemy() const
{
	if (BlackboardComp)
	{
		return Cast<ANPCCharacter>(BlackboardComp->GetValueAsObject(TargetEnemyKeyName));
	}

	return nullptr;
}

APlayerCharacter* ANPCController::GetTargetPlayer() const
{
	if (BlackboardComp)
	{
		return Cast<APlayerCharacter>(BlackboardComp->GetValueAsObject(TargetPlayerKeyName));
	}

	return nullptr;
}