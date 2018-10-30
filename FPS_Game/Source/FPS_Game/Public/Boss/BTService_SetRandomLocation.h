// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_SetRandomLocation.generated.h"

/**
 * 
 */
UCLASS()
class FPS_GAME_API UBTService_SetRandomLocation : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = AI)
		float Radius = 1000.f;
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
