// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_FindWaypoint.h"
#include "Waypoint.h"
#include "ZombieAIController.h"

/* AI Module includes */
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"



EBTNodeResult::Type UBTTask_FindWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AZombieAIController* MyController = Cast<AZombieAIController>(OwnerComp.GetAIOwner());
	/*if (MyController == nullptr)
	{
		return EBTNodeResult::Failed;
	}*/

	AWaypoint* CurrentWaypoint = MyController->GetWaypoint();
	AActor* NewWaypoint = nullptr;

	TArray<AActor*> AllWaypoints;
	UGameplayStatics::GetAllActorsOfClass(MyController, AWaypoint::StaticClass(), AllWaypoints);

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