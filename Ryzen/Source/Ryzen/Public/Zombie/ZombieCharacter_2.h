// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/RyzenBaseCharacter.h"
#include "StructClass.h"
#include "ZombieCharacter_2.generated.h"


UCLASS()
class RYZEN_API AZombieCharacter_2 : public ARyzenBaseCharacter
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere, Category = "AI")
		class UPawnSensingComponent* PawnSensingComp;

	//타겟을 찾지 못하는데 걸리는 시간 2.5초
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		float SenseTimeOut;

	/* 타겟을 쫒다가 SenseTimeOut이 지나면 타겟을 리셋하는용 */
	bool bSensedTarget;
	//타겟을 발견 한 뒤 월드 시간을 받음
	float LastSeenTime;
public:
	// Sets default values for this character's properties
	AZombieCharacter_2(const class FObjectInitializer& ObjectInitializer);

private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
		void OnSeePlayer(APawn* pawn);
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		class UBehaviorTree* BehaviorTree;

	//좀비 타입
	UPROPERTY(EditAnywhere, Category = "AI")
		EZombieType ZombieType;

	void SetBotType(EZombieType NewType);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Attack")
		UAnimMontage* ActtackAnimMontage;

	
};
