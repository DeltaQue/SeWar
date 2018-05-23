// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/RyzenBaseCharacter.h"
#include "ZombieCharacter_2.generated.h"


UCLASS()
class RYZEN_API AZombieCharacter_2 : public ARyzenBaseCharacter
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere, Category = "AI")
		class UPawnSensingComponent* PawnSensingComp;

	UFUNCTION()
		void OnAttackCollisionCompBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
	UFUNCTION()
		void OnAttackCollisionCompEndOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser);

	//타겟을 찾지 못하는데 걸리는 시간 2.5초
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		float SightSenseTimeOut;

	//소리를 감지하고 그 곳을 탐색하는 시간 6초
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		float HearingSenseTimeOut;

	/* 타겟을 쫒다가 SenseTimeOut이 지나면 타겟을 리셋하는용 */
	bool bSensedTarget;

	bool bHeardTarget;

	//타겟을 발견 한 뒤 월드 시간을 받음
	float LastSeenTime;
	
	float LastHeardTime;

	bool bOverlapAttackCollision;

	float DefaultMaxWalkSpeed;
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

	UFUNCTION()
		void OnHearNoise(APawn* PawnInstigator, const FVector& Location, float Volume);
	
	UPROPERTY(VisibleAnywhere, Category = "Attack")
		UCapsuleComponent* AttackCollisionComp;

	//체력이 0이하로 내려갔을때 행동들 정의, ragdoll 등..
	void IsDeath();
public:
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		class UBehaviorTree* BehaviorTree;

	//좀비 타입
	UPROPERTY(EditAnywhere, Category = "AI")
		EZombieType ZombieType;

	UFUNCTION()
		bool GetOverlapAttackCollision() const;

	UFUNCTION()
		UAnimInstance* GetAttackAnimInstance() const;

	UFUNCTION()
		UAnimMontage* GetAttackAnimMontage() const;

	void SetZombieType(EZombieType NewType);

	bool DamageHit(uint8 damage);
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Attack")
		UAnimMontage* AttackAnimMontage;

	UPROPERTY(VisibleDefaultsOnly)
		class UAnimInstance* AnimInstance;
};
