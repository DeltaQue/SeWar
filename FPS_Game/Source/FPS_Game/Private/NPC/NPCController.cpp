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
	TargetEnemyKeyName = "TargetEnemy";
	TargetPlayerKeyName = "TargetPlayer";
	NPCTypeKeyName = "NPCType";
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

			SetNPCType(NPCBot->NPCType);
		}

		SetSafetyZoneLocation(FVector(723.0f, -2297.0f, 247.837448f));
		BehaviorComp->StartTree(*NPCBot->BehaviorTree);
	}
}


void ANPCController::UnPossess()
{
	Super::UnPossess();

	BehaviorComp->StopTree();
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

void ANPCController::SetNPCType(ENPCType NPCType)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsEnum(NPCTypeKeyName, (uint8)NPCType);
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

FVector ANPCController::GetSafetyZoneLocation() const
{
	if (BlackboardComp)
	{
		return BlackboardComp->GetValueAsVector(SafetyZoneLocationKeyName);
	}

	return FVector(0, 0, 0);
}