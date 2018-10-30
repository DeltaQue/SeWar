// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "MyBTTask_BossAttack.generated.h"

/**
 * 
 */
UCLASS()
class FPS_GAME_API UMyBTTask_BossAttack : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

	bool IsFinish = false;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	void AttackFinish();
};
