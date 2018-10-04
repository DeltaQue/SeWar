// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Character/BaseCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class FPS_GAME_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

private:
	APlayerCharacter(const class FObjectInitializer& ObjectInitializer);

	virtual void PostInitializeComponents() override;
	
	void AddWeapon(AWeapons* TargetWeapon);
	void RemoveWeapon(AWeapons* TargetWeapon);
	void SetDefaultWeaponEquip();
	void EquipWeapon(AWeapons* NewWeapon);
	void SetCurrentWeapon(AWeapons* NewWeapon, AWeapons* LastWeapon);

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

protected:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnStartJump();
	void OnStopJump();
	void OnStartFire();
	void OnStopFire();
	void OnStartADS();
	void OnStopADS();
	void OnReload();

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


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FPP_Camera;
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

	bool CanFire() const;
	void StopAllAnimMontages();

	void OnCameraUpdate(const FVector& CameraLocation, const FRotator& CameraRotation);
	void CheckForWeaponInView(FVector CameraLocation, FVector CameraFowardVector, FRotator CameraRotator);
	float GetDefaultSpeed();

	

	FName GetWeaponAttachPoint() const;
	USkeletalMeshComponent* GetOwenerMesh() const;
};
