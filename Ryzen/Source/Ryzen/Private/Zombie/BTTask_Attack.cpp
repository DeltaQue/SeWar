// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_Attack.h"
#include "ZombieCharacter_2.h"
#include "ZombieAIController.h"

/* AI Module includes */
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"



EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AZombieAIController* MyController = Cast<AZombieAIController>(OwnerComp.GetAIOwner());
	AZombieCharacter_2* MyCharacter = Cast<AZombieCharacter_2>(MyController->GetPawn());
	
	
	if (MyCharacter == nullptr && MyController->GetIsAttackCollisionOverlap() == false)
	{
		return EBTNodeResult::Failed;
	}

	if (MyController->GetIsAttackCollisionOverlap()) 
	{
		MyCharacter->TimerHandleFunc();
	}

	return EBTNodeResult::Succeeded;
}