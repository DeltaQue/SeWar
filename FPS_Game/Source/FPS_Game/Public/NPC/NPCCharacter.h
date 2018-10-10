// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPS_GameStruct.h"
#include "Character/BaseCharacter.h"
#include "NPCCharacter.generated.h"

/**
 * 
 */
UCLASS()
class FPS_GAME_API ANPCCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	
	

private:
	UFUNCTION()
		void OnAttackCollisionCompBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
		void OnAttackCollisionCompEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		void OnTalkCollisionCompBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
		void OnTalkCollisionCompEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		void OnSeeZombie(APawn* pawn);

	UFUNCTION()
		void OnHearNoise(APawn* PawnInstigator, const FVector& Location, float Volume);

	UFUNCTION(BlueprintCallable, Category = "Attack")
		void ScratchAttack(AActor* HitActor);

	UFUNCTION(BlueprintCallable, Category = "Attack")
		void ReTriggerAttack();

	/////////////////////


	UPROPERTY(VisibleAnywhere, Category = "AI")
		class UPawnSensingComponent* PawnSensingComp;

	//타겟을 찾지 못하는데 걸리는 시간 2.5초
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		float SightSenseTimeOut;

	//소리를 감지하고 그 곳을 탐색하는 시간 6초
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		float HearingSenseTimeOut;

	UPROPERTY(VisibleAnywhere, Category = "Attack")
		class UCapsuleComponent* AttackCollisionComp;

	UPROPERTY(VisibleAnywhere, Category = "Talk")
		class UCapsuleComponent* TalkCollisionComp;


	void StopAllAnimation();


	float LastAttackTime;
	float AttackCooltime;

	/* 타겟을 쫒다가 SenseTimeOut이 지나면 타겟을 리셋하는용 */
	bool bSensedTarget;
	bool bHeardTarget;

	//타겟을 발견 한 뒤 월드 시간을 받음
	float LastSeenTime;
	float LastHeardTime;

	float DefaultMaxWalkSpeed;

	FTimerHandle TimerHandle_AttackTimer;
public:
	// Sets default values for this character's properties
	ANPCCharacter(const class FObjectInitializer& ObjectInitializer);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(EditDefaultsOnly, Category = "Attack")
		UAnimMontage* AttackAnimMontage;

	UPROPERTY(VisibleDefaultsOnly)
		class UAnimInstance* AnimInstance;

	UPROPERTY(EditDefaultsOnly, Category = "Talk")
		UAnimMontage* TalkAnimMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Talk")
		UAnimMontage* AngryAnimMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Talk")
		UAnimMontage* HappyAnimMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Talk")
		UAnimMontage* SurpriseAnimMontage;


	//NPC Type
	UPROPERTY(EditDefaultsOnly, Category = "NPC")
		bool bIsQuestNPC;

	UPROPERTY(EditDefaultsOnly, Category = "NPC")
		bool bIsHealNPC;

	UPROPERTY(EditDefaultsOnly, Category = "NPC")
		bool bIsAmmoNPC;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		class UBehaviorTree* BehaviorTree;

	void PlayAttackMotion();

	void TimerHandleFunc();

	void PlayTalkMotion();

	void PlayAngryMotion();

	void PlayHappyMotion();

	void PlaySurpriseMotion();

	UPROPERTY(EditAnywhere, Category = "AI")
		ENPCPersonality Personality;
	
};
