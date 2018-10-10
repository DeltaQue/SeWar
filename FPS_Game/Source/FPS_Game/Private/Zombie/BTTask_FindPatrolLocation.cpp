// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_FindPatrolLocation.h"
#include "ZombieAIController.h"
#include "ZombieCharacter.h"

#include "NPCController.h"
#include "NPCCharacter.h"

/* AI Module includes */
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"



EBTNodeResult::Type UBTTask_FindPatrolLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AZombieAIController* ZombieController = Cast<AZombieAIController>(OwnerComp.GetAIOwner());
	AZombieCharacter* MyCharacter = Cast<AZombieCharacter>(ZombieController->GetPawn());


	CharacterLocation = MyCharacter->GetActorLocation();

	if (ZombieController == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	AWaypoint* MyWaypoint = ZombieController->GetWaypoint();
	if (MyWaypoint)
	{
		const float SearchRadius = 200.0f;
		const FVector WaypointLocation = MyWaypoint->GetActorLocation();

		/*	Distance = FVector::Dist(CharacterLocation, WaypointLocation);
		Distance = Distance * FApp::GetDeltaTime();
		FVector ResultLocation = CharacterLocation * Distance;*/

		FNavLocation ResultLocation;
		UNavigationSystem* NavSystem = UNavigationSystem::GetNavigationSystem(ZombieController);
		if (NavSystem && NavSystem->GetRandomPointInNavigableRadius(WaypointLocation, SearchRadius, ResultLocation))
		{

			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Vector>(BlackboardKey.GetSelectedKeyID(), ResultLocation.Location);
			return EBTNodeResult::Succeeded;
		}

		/*if (NavSystem && Distance > 10.0f)
		{
		MyController->SetIsArrive(false);

		OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Vector>(BlackboardKey.GetSelectedKeyID(), ResultLocation);
		return EBTNodeResult::Succeeded;
		}
		else if(Distance < 10.0f)
		{
		MyController->SetIsArrive(true);

		return EBTNodeResult::Succeeded;
		}*/

	}

	return EBTNodeResult::Failed;
}

void UBTTask_FindPatrolLocation::TickTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{

}






