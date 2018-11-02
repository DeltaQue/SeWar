// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_SetRandomLocation.h"
#include "ZombieCharacter.h"
#include "ZombieAIController.h"
#include "Engine.h"


void UBTService_SetRandomLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	AZombieAIController* ZombieController = Cast<AZombieAIController>(OwnerComp.GetAIOwner());
	AZombieCharacter* ZombieCharacter = Cast<AZombieCharacter>(ZombieController->GetPawn());

	UNavigationSystem* NavSys = UNavigationSystem::GetCurrent(GetWorld());
	if (!NavSys)
	{

	}

	FNavLocation Result;


	bool bSuccess = NavSys->GetRandomPointInNavigableRadius(ZombieCharacter->GetActorLocation(), 1500.f, Result);
	
	if (bSuccess)
	{
		ZombieController->SetPatrolLocation(Result.Location);
	}
}