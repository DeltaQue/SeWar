// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_FindPatrolLocation.h"
#include "Waypoint.h"
#include "ZombieAIController.h"
#include "ZombieCharacter_2.h"
/* AI Module includes */
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"



EBTNodeResult::Type UBTTask_FindPatrolLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AZombieAIController* MyController = Cast<AZombieAIController>(OwnerComp.GetAIOwner());
	AZombieCharacter_2* MyCharacter = Cast<AZombieCharacter_2>(MyController->GetPawn());

	CharacterLocation = MyCharacter->GetActorLocation();

	if (MyController == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	AWaypoint* MyWaypoint = MyController->GetWaypoint();
	if (MyWaypoint)
	{
		const float SearchRadius = 200.0f;
		const FVector WaypointLocation = MyWaypoint->GetActorLocation();

	/*	Distance = FVector::Dist(CharacterLocation, WaypointLocation);
		Distance = Distance * FApp::GetDeltaTime();
		FVector ResultLocation = CharacterLocation * Distance;*/

		FNavLocation ResultLocation;
		UNavigationSystem* NavSystem = UNavigationSystem::GetNavigationSystem(MyController);
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








