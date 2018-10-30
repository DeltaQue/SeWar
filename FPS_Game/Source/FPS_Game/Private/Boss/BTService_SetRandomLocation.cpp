// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_SetRandomLocation.h"
#include "BossCharacter.h"
#include "BossAIController.h"
#include "Engine.h"


void UBTService_SetRandomLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	ABossAIController* BossController = Cast<ABossAIController>(OwnerComp.GetAIOwner());
	ABossCharacter* BossCharacter = Cast<ABossCharacter>(BossController->GetPawn());

	UNavigationSystem* NavSys = UNavigationSystem::GetCurrent(GetWorld());
	if (!NavSys)
	{

	}

	FNavLocation Result;


	bool bSuccess = NavSys->GetRandomPointInNavigableRadius(BossCharacter->GetActorLocation(), 1500.f, Result);
	
	if (bSuccess)
	{
		BossController->SetPatrolLocation(Result.Location);
	}
}