// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "PlayerCharacter.h"
#include "FPS_GameStruct.h"
#include "BossAIController.generated.h"


class UBehaviorTreeComponent;
class UBlackboardComponent;

UCLASS()
class FPS_GAME_API ABossAIController : public AAIController
{
	GENERATED_BODY()
	
	
private:

	UBlackboardComponent* BlackboardComp;
	UBehaviorTreeComponent* BehaviorTreeComp;


	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName TargetEnemyKeyName;
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName PatrolLocationKeyName;
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName BossTypeKeyName;
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName AttackAbleKeyName;
protected:

public:

	ABossAIController(const class FObjectInitializer& ObjectInitializer);

	virtual void Possess(APawn* InPawn) override;
	virtual void UnPossess() override;


	AActor* GetSeeingPawn();


	void SetTargetEnemy(APawn* NewTarget);
	void SetPatrolLocation(FVector NewLocation);
	void SetBossType(EBossType NewType);
	void SetAttackAble(bool IsValid);

	APlayerCharacter* GetTargetEnemy() const;
	bool GetAttackAble() const;

	/** Returns BehaviorComp subobject **/
	FORCEINLINE UBehaviorTreeComponent* GetBehaviorTreeComp() const { return BehaviorTreeComp; }

	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }
	
};
