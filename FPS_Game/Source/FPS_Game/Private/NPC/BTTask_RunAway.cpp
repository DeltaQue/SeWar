// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_RunAway.h"
#include "NPCCharacter.h"
#include "NPCController.h"

/* AI Module includes */
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"

EBTNodeResult::Type UBTTask_RunAway::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ANPCController* NPCController = Cast<ANPCController>(OwnerComp.GetAIOwner());
	ANPCCharacter* MyCharacter = Cast<ANPCCharacter>(NPCController->GetPawn());


	if (NPCController == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	if (NPCController->GetSafetyZoneLocation() != FVector(0,0,0))
	{
		const float SearchRadius = 200.0f;
		const FVector SafetyZoneLocation = NPCController->GetSafetyZoneLocation();

		OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Vector>(BlackboardKey.GetSelectedKeyID(), SafetyZoneLocation);
		return EBTNodeResult::Succeeded;

	}
	return EBTNodeResult::Failed;
}