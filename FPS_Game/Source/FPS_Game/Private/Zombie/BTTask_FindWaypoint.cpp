// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_FindWaypoint.h"
#include "BTTask_FindPatrolLocation.h"
#include "ZombieAIController.h"
#include "NPCController.h"

/* AI Module includes */
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"



EBTNodeResult::Type UBTTask_FindWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AZombieAIController* ZombieController = Cast<AZombieAIController>(OwnerComp.GetAIOwner());

	if (ZombieController == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	AWaypoint* CurrentWaypoint = ZombieController->GetWaypoint();
	AActor* NewWaypoint = nullptr;

	TArray<AActor*> AllWaypoints;
	UGameplayStatics::GetAllActorsOfClass(ZombieController, AWaypoint::StaticClass(), AllWaypoints);

	if (AllWaypoints.Num() == 0)
		return EBTNodeResult::Failed;

	NewWaypoint = AllWaypoints[FMath::RandRange(0, AllWaypoints.Num() - 1)];

	if (NewWaypoint)
	{
		OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(BlackboardKey.GetSelectedKeyID(), NewWaypoint);
		return EBTNodeResult::Succeeded;
	}
	

	return EBTNodeResult::Failed;
}

