// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseCharacter.h"
#include "ZombieCharacter.h"
#include "Waypoint.h"
#include "EscapePoint.h"
#include "FPS_GameStruct.h"
#include "ZombieAIController.generated.h"

/**
 * 
 */
class UBehaviorTreeComponent;
class UBlackboardComponent;

UCLASS()
class FPS_GAME_API AZombieAIController : public AAIController
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
		FName ZombieTypeKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName ReconLocationKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName IsAttackCollisionOverlapKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName EscapePointKeyName;
public:

	AWaypoint * GetWaypoint() const;

	ABaseCharacter* GetTargetEnemy() const;

	FVector GetReconLocation() const;

	bool GetIsAttackCollisionOverlap() const;

	AEscapePoint* GetEscapePoint() const;


	void SetWaypoint(AWaypoint* NewWaypoint);

	void SetTargetEnemy(APawn* NewTarget);

	void SetBlackboardZombieType(EZombieType NewType);

	void SetReconLocation(FVector vector);

	void SetIsAttackCollisionOverlap(bool Overlaped);

	void SetPatrolLocation(FVector Location);

	void SetEscapePoint(AEscapePoint* EscapeTarget);

	void StopBehaviorTree();
	void StartBehaviorTree();

	/** Returns BehaviorComp subobject **/
	FORCEINLINE UBehaviorTreeComponent* GetBehaviorComp() const { return BehaviorComp; }

	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }

	
	
};
