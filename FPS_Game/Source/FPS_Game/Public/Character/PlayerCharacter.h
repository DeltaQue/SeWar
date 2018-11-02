// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Character/BaseCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */

class UCameraShake;

UCLASS()
class FPS_GAME_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

private:
	APlayerCharacter(const class FObjectInitializer& ObjectInitializer);

	virtual void PostInitializeComponents() override;

	void MovementTutorialOpen();

	void AddWeapon(AWeapons* TargetWeapon);
	void RemoveWeapon(AWeapons* TargetWeapon);
	void SetDefaultWeaponEquip();
	void EquipWeapon(AWeapons* NewWeapon);
	void SetCurrentWeapon(AWeapons* NewWeapon, AWeapons* LastWeapon);

	void ReturnCheckPoint();

	void StartWeaponFire();
	void StopWeaponFire();

	bool bIsADS;
	bool bIsJumping;
	bool bIsSprint;
	bool bIsFire;

	float fDefaultSpeed;
	float fSprintModifier;
	float fWalkModifier;

	
	class AWeapons* PickupWeapon;

	bool bHasNewFocus;

	void PlayEarthquakeShake();
	FTimerHandle Earthquake_TimerHandle;
protected:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnStartJump();
	void OnStopJump();
	void OnStartFire();
	void OnStopFire();
	void OnStartADS();
	void OnStopADS();
	void OnReload();
	void OnPrevWeapon();
	void OnNextWeapon();
	void OnTurnOnLight();

	void OnStartSprint();
	void OnStopSprint();
	void WeaponEquip();

	void MoveForward(float value);
	void MoveRight(float value);

	UPROPERTY(EditDefaultsOnly, Category = Inventory)
		TArray<TSubclassOf<class AWeapons> > DefaultWeapon;

	UPROPERTY(EditDefaultsOnly, Category = Inventory)
		class AWeapons* CurrentWeapon;

	UPROPERTY(EditDefaultsOnly, Category = Inventory)
		TArray<class AWeapons*> Inventory;

	UPROPERTY(EditDefaultsOnly, Category = Inventory)
		FName WeaponAttachPoint;


	UPROPERTY(EditDefaultsOnly, Category = Effects)
		TSubclassOf<UCameraShake> EarthquakeCameraShake;
	


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FPP_Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FPP_BackTargetViewCamera;

public:
	UFUNCTION(BlueprintCallable, Category = "PlayerState")
		bool IsTargeting() const;
	UFUNCTION(BlueprintCallable, Category = "PlayerState")
		bool IsJumping() const;
	UFUNCTION(BlueprintCallable, Category = "PlayerState")
		bool IsSprint() const;
	UFUNCTION(BlueprintCallable, Category = "PlayerState")
		bool IsFire() const;
	UFUNCTION(BlueprintCallable, Category = "PlayerState")
		float GetPlayerHP();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		class AWeapons* GetWeapon() const;

	//Ammo Gauge Event
	UFUNCTION(BlueprintImplementableEvent, Category = "AmmoGauge")
		void WeaponFireEvent(float LoadedAmmo);
	//현재 퀘스트 활성화
	UFUNCTION(BlueprintImplementableEvent, Category = "Widget")
		void SetCurrentQuestActivate(int QuestNum);
	//현재 퀘스트 비활성화
	UFUNCTION(BlueprintImplementableEvent, Category = "Widget")
		void SetCurrentQuestDeActivate(int QuestNum);

	UFUNCTION(BlueprintCallable, Category = "PlayerState")
		void StartFadeOut(float Time);
	UFUNCTION(BlueprintCallable, Category = "PlayerState")
		void StartFadeIn(float Time);

	bool CanFire() const;
	void StopAllAnimMontages();

	void OnCameraUpdate(const FVector& CameraLocation, const FRotator& CameraRotation);
	void CheckForWeaponInView(FVector CameraLocation, FVector CameraFowardVector, FRotator CameraRotator);
	float GetDefaultSpeed();

	virtual void FaceRotation(FRotator NewRotation, float DeltaTime = 0.f) override;
	void SwitchTargetCamera(float BlendTime = 5.0f);
	void SwitchMyCamera();

	FName GetWeaponAttachPoint() const;
	USkeletalMeshComponent* GetOwenerMesh() const;
};
