// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FPS_Game.h"
#include "Character/BaseCharacter.h"
#include "FPS_GameStruct.h"
#include "BossCharacter.generated.h"

class UAnimMontage;
class UAudioComponent;
class USoundCue;

UCLASS()
class FPS_GAME_API ABossCharacter : public ABaseCharacter
{
	GENERATED_BODY()


private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	UFUNCTION()
		void OnAttackCollisionCompBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
		void OnAttackCollisionCompEndOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
	

	UFUNCTION()
		void OnSeePlayer(APawn* pawn);


	UPROPERTY(VisibleAnywhere, Category = "Attack")
		UCapsuleComponent* AttackCollisionComp;

	UPROPERTY(VisibleAnywhere, Category = "AI")
		class UPawnSensingComponent* PawnSensingComp;

	/* 타겟을 쫒다가 SenseTimeOut이 지나면 타겟을 리셋하는용 */
	bool bSensedTarget;
	bool bHeardTarget;
	bool bPlayedScream;

	//타겟을 발견 한 뒤 월드 시간을 받음
	float LastSeenTime;
	float LastHeardTime;

	float SightSenseTimeOut;
	float HearingSenseTimeOut;

	float DefaultMaxWalkSpeed;

public:
	// Sets default values for this character's properties
	ABossCharacter(const class FObjectInitializer& ObjectInitializer);



	UPROPERTY(EditDefaultsOnly, Category = "AI")
		class UBehaviorTree* BehaviorTree;
	////좀비 보스 타입
	UPROPERTY(EditAnywhere, Category = "AI")
		EBossType BossType;

	float PlayAttackAnimMontage(int AttackType);
	float PlayAttackSound(int AttackType);

	TSubclassOf<UDamageType> GetAttackDamageType() const;

	float GetAttackDamage(int AttackType) const;
protected:
	//0 : BiteAttack
	//1 : HookAttack
	UPROPERTY(EditDefaultsOnly, Category = Animation)
		UAnimMontage* BiteAttackAnimMontage;

	UPROPERTY(EditDefaultsOnly, Category = Animation)
		UAnimMontage* HookAttackAnimMontage;


	UPROPERTY(EditDefaultsOnly, Category = Animation)
		UAnimMontage* ScreamAnimMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundCue* PlayerChaseSoundCue;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundCue* PlayerWanderingSoundCue;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundCue* IdleSoundCue;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundCue* AttackSound;

	UPROPERTY(EditDefaultsOnly, Category = "Attack")
		TSubclassOf<UDamageType> AttackDamageType;

	UPROPERTY(EditDefaultsOnly, Category = "Attacking")
		float BiteAttackDamage;

	UPROPERTY(EditDefaultsOnly, Category = "Attacking")
		float HookAttackDamage;


	void TargetChase(APawn* pawn);


};
