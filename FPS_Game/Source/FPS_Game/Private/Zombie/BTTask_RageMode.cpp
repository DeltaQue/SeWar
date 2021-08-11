// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_RageMode.h"
#include "ZombieAIController.h"
#include "ZombieCharacter.h"

/* AI Module includes */
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"


EBTNodeResult::Type UBTTask_RageMode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AZombieAIController* ZombieController = Cast<AZombieAIController>(OwnerComp.GetAIOwner());
	AZombieCharacter* ZombieCharacter = Cast<AZombieCharacter>(ZombieController->GetPawn());

	if (ZombieController == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	TArray<AActor*> AllZombieCharacter;
	UGameplayStatics::GetAllActorsOfClass(ZombieController, AZombieCharacter::StaticClass(), AllZombieCharacter);

	if (AllZombieCharacter.Num() == 0)
		return EBTNodeResult::Failed;

	ACharacter* Character = UGameplayStatics::GetPlayerCharacter(this, 0);
	APlayerCharacter* Player = Cast<APlayerCharacter>(Character);

	for (int i = 0; i < AllZombieCharacter.Num(); i++)
	{
		AZombieCharacter* OtherZombie = Cast<AZombieCharacter>(AllZombieCharacter[i]);
		AZombieAIController* OtherZombieController = Cast<AZombieAIController>(OtherZombie->GetController());

		//모든 좀비의 타겟을 플레이어로 바꿈
		OtherZombieController->SetTargetEnemy(Player);
	}

	Cast<UCharacterMovementComponent>(ZombieCharacter->GetMovementComponent())->MaxWalkSpeed *= 1.5;

	return EBTNodeResult::Succeeded;
}



