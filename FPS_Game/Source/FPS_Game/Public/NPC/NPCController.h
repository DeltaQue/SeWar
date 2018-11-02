// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Waypoint.h"
#include "NPCCharacter.h"
#include "PlayerCharacter.h"
#include "FPS_GameStruct.h"
#include "NPCController.generated.h"

class UBehaviorTreeComponent;
class UBlackboardComponent;



UCLASS()
class FPS_GAME_API ANPCController : public AAIController
{
	GENERATED_BODY()
	
	
	ANPCController(const class FObjectInitializer& ObjectInitializer);

	/* Called whenever the controller possesses a character bot */
	virtual void Possess(class APawn* InPawn) override;

	virtual void UnPossess() override;


	UBehaviorTreeComponent* BehaviorComp;

	UBlackboardComponent* BlackboardComp;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName TargetEnemyKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName TargetPlayerKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName NPCTypeKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName SafetyZoneLocationKeyName;

public:
	ANPCCharacter* GetTargetEnemy() const;

	APlayerCharacter* GetTargetPlayer() const;

	FVector GetSafetyZoneLocation() const;


	void SetTargetEnemy(APawn* NewTarget);

	void SetTargetPlayer(APawn* NewTarget);

	void SetNPCType(ENPCType NPCPersonality);

	void SetSafetyZoneLocation(FVector location);

	/** Returns BehaviorComp subobject **/
	FORCEINLINE UBehaviorTreeComponent* GetBehaviorComp() const { return BehaviorComp; }

	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }
	
};
