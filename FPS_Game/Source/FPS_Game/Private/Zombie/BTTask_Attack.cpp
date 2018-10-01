// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_Attack.h"
#include "ZombieCharacter.h"
#include "ZombieAIController.h"

/* AI Module includes */
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"



EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AZombieAIController* MyController = Cast<AZombieAIController>(OwnerComp.GetAIOwner());
	AZombieCharacter* MyCharacter = Cast<AZombieCharacter>(MyController->GetPawn());


	if (MyCharacter == nullptr && MyController->GetIsAttackCollisionOverlap() == false)
	{
		return EBTNodeResult::Failed;
	}

	if (MyController->GetIsAttackCollisionOverlap())
	{
		//MyCharacter->PlayAttackMotion();
	}

	return EBTNodeResult::Succeeded;
}



