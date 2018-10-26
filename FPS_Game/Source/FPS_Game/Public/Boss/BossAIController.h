// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "BossAIController.generated.h"


class UBehaviorTreeComponent;
class UBlackboardComponent;

UCLASS()
class FPS_GAME_API ABossAIController : public AAIController
{
	GENERATED_BODY()
	
	
private:

	UBlackboardComponent * BlackboardComp;
	UBehaviorTreeComponent* BehaviorTreeComp;


	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName TargetEnemyKeyName;


protected:

	UPROPERTY(EditAnywhere)
		UBehaviorTree* BehaviorTree;

	UPROPERTY(VisibleAnywhere)
		UAIPerceptionComponent* AIPerceptionComponent;

public:

	ABossAIController(const class FObjectInitializer& ObjectInitializer);

	virtual void Possess(APawn* InPawn) override;
	virtual void UnPossess() override;


	AActor* GetSeeingPawn();


	void SetTargetEnemy(APawn* NewTarget);



	/** Returns BehaviorComp subobject **/
	FORCEINLINE UBehaviorTreeComponent* GetBehaviorTreeComp() const { return BehaviorTreeComp; }

	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }
	
};
