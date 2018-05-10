// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_Attack.h"
#include "ZombieCharacter_2.h"

/* AI Module includes */
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"



EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AZombieCharacter_2* MyCharacter = Cast<AZombieCharacter_2>(OwnerComp.GetAIOwner());
	if (MyCharacter == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	//MyCharacter->execOnAttackCollisionCompBeginOverlap
	return EBTNodeResult::Failed;
}
