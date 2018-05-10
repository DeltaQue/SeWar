// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "AIController.h"
#include "RyzenBaseCharacter.h"
#include "Waypoint.h"
#include "ZombieAIController.generated.h"

/**
*
*/
class UBehaviorTreeComponent;
class UBlackboardComponent;
UCLASS(config = Game)
class RYZEN_API AZombieAIController : public AAIController
{
	GENERATED_BODY()

	AZombieAIController(const class FObjectInitializer& ObjectInitializer);

	/* Called whenever the controller possesses a character bot */
	virtual void Possess(class APawn* InPawn) override;

	virtual void UnPossess() override;

	
	UBehaviorTreeComponent* BehaviorComp;
	
	UBlackboardComponent* BlackboardComp;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName TargetEnemyKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName PatrolLocationKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName CurrentWaypointKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName BotTypeKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName ReconnaissanceLocationKeyName;

public:

	AWaypoint* GetWaypoint();

	ARyzenBaseCharacter* GetTargetEnemy();

	void SetWaypoint(AWaypoint* NewWaypoint);

	void SetTargetEnemy(APawn* NewTarget);

	void SetBlackboardZombieType(EZombieType NewType);

	void SetReconnaissanceLocation(FVector vector);

	/** Returns BehaviorComp subobject **/
	FORCEINLINE UBehaviorTreeComponent* GetBehaviorComp() const { return BehaviorComp; }

	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }
};
