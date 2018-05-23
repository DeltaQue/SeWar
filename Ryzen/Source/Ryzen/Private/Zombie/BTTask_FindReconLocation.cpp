// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_FindReconLocation.h"
#include "ZombieAIController.h"

/* AI Module includes */
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"


EBTNodeResult::Type UBTTask_FindReconLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AZombieAIController* MyController = Cast<AZombieAIController>(OwnerComp.GetAIOwner());
	if (MyController == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	
	//const FVector SearchOrigin = MyController->GetReconLocation();
	const FVector SearchOrigin = MyController->GetReconLocation();

	if (SearchOrigin != FVector(-1,-1,-1))
	{
		const float SearchRadius = 200.0f;
		

		FNavLocation ResultLocation;
		UNavigationSystem* NavSystem = UNavigationSystem::GetNavigationSystem(MyController);
		if (NavSystem && NavSystem->GetRandomPointInNavigableRadius(SearchOrigin, SearchRadius, ResultLocation))
		{
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Vector>(BlackboardKey.GetSelectedKeyID(), ResultLocation.Location);
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}