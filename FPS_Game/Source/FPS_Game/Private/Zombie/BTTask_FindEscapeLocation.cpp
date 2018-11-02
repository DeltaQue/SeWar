// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_FindEscapeLocation.h"
#include "ZombieAIController.h"
#include "ZombieCharacter.h"

/* AI Module includes */
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"


EBTNodeResult::Type UBTTask_FindEscapeLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AZombieAIController* ZombieController = Cast<AZombieAIController>(OwnerComp.GetAIOwner());
	AZombieCharacter* MyCharacter = Cast<AZombieCharacter>(ZombieController->GetPawn());

	if (ZombieController == nullptr)
	{
		return EBTNodeResult::Failed;
	}


	AEscapePoint* EscapePoint = ZombieController->GetEscapePoint();
	AActor* NewEscapePoint = nullptr;

	TArray<AActor*> AllEscapePoints;
	UGameplayStatics::GetAllActorsOfClass(ZombieController, AEscapePoint::StaticClass(), AllEscapePoints);

	if (AllEscapePoints.Num() == 0)
		return EBTNodeResult::Failed;

	NewEscapePoint = AllEscapePoints[FMath::RandRange(0, AllEscapePoints.Num() - 1)];

	if (NewEscapePoint)
	{
		OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(BlackboardKey.GetSelectedKeyID(), NewEscapePoint);

		if (EscapePoint)
		{
			const float SearchRadius = 100.0f;
			const FVector EscapepointLocation = EscapePoint->GetActorLocation();


			FNavLocation ResultLocation;
			UNavigationSystem* NavSystem = UNavigationSystem::GetNavigationSystem(ZombieController);
			if (NavSystem && NavSystem->GetRandomPointInNavigableRadius(EscapepointLocation, SearchRadius, ResultLocation))
			{

				OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Vector>(BlackboardKey.GetSelectedKeyID(), ResultLocation.Location);
				return EBTNodeResult::Succeeded;
			}
		}
	}
	
	return EBTNodeResult::Failed;
}