// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FPS_Game.h"
#include "Character/BaseCharacter.h"
#include "Components/WidgetComponent.h"
#include "ZombieCharacter.generated.h"


class UAnimMontage;
class UAudioComponent;
class USoundCue;

UCLASS()
class FPS_GAME_API AZombieCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	

private:
	UPROPERTY(VisibleAnywhere, Category = "AI")
		class UPawnSensingComponent* PawnSensingComp;

	//UPROPERTY(EditDefaultsOnly, Category = "HUD")
	//	UWidgetComponent* MyWidget;

	UFUNCTION()
		void OnAttackCollisionCompBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
		void OnAttackCollisionCompEndOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION(BlueprintCallable, Category = "Attack")
		void ScratchAttack(AActor* HitActor);

	UFUNCTION(BlueprintCallable, Category = "Attack")
		void ReTriggerAttack();

	//타겟을 찾지 못하는데 걸리는 시간 2.5초
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		float SightSenseTimeOut;

	//소리를 감지하고 그 곳을 탐색하는 시간 6초
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		float HearingSenseTimeOut;

	
	void AudioLoopUpdate(bool bNewSensedTarget);
	void Attack_TakeDamage(AActor* HitActor);


	float LastAttackTime;
	float AttackCooltime;

	/* 타겟을 쫒다가 SenseTimeOut이 지나면 타겟을 리셋하는용 */
	bool bSensedTarget;
	bool bHeardTarget;
	bool bPlayedScream;

	//타겟을 발견 한 뒤 월드 시간을 받음
	float LastSeenTime;
	float LastHeardTime;

	float DefaultMaxWalkSpeed;

	FTimerHandle TimerHandle_AttackTimer;
	FTimerHandle TimerHandle_ScreamTimer;

	FTimerDelegate ScreamTimerDelegate;

public:
	// Sets default values for this character's properties
	AZombieCharacter(const class FObjectInitializer& ObjectInitializer);

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

	UPROPERTY(VisibleAnywhere, Category = "Sound")
		UAudioComponent* AudioLoopComp;

	//체력이 0이하로 내려갔을때 행동들 정의, ragdoll 등..
	void IsDeath();
public:
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		class UBehaviorTree* BehaviorTree;

	//좀비 타입
	UPROPERTY(EditAnywhere, Category = "AI")
		EZombieType ZombieType;

	UFUNCTION()
		UAnimInstance* GetAttackAnimInstance() const;

	UFUNCTION()
		UAnimMontage* GetAttackAnimMontage() const;

	UFUNCTION()
		void PlayAttackMotion();

	UFUNCTION()
		void TimerHandleFunc();

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundCue* AttackSound;


	void SetZombieType(EZombieType NewType);

	bool DamageHit(uint8 damage);

	bool GetIsBoss() const;

	UFUNCTION()
		void TargetChase(APawn* pawn);
protected:
	UPROPERTY(EditDefaultsOnly, Category = Animation)
		UAnimMontage* AttackAnimMontage;

	UPROPERTY(EditDefaultsOnly, Category = Animation)
		UAnimMontage* AttackAnim2Montage;

	UPROPERTY(EditDefaultsOnly, Category = Animation)
		UAnimMontage* ScreamAnimMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundCue* PlayerChaseSoundCue;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundCue* PlayerWanderingSoundCue;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundCue* IdleSoundCue;
	

	UPROPERTY(EditDefaultsOnly, Category = "ZombieState")
		bool IsBoss;


	UPROPERTY(VisibleDefaultsOnly)
		class UAnimInstance* AnimInstance;

	UPROPERTY(EditDefaultsOnly, Category = "Attack")
		TSubclassOf<UDamageType> ScratchDamageType;

	UPROPERTY(EditDefaultsOnly, Category = "Attacking")
		float AttackDamage;
	
	
};
