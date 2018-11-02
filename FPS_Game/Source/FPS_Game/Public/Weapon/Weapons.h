
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Weapons.generated.h"

class USpotLightComponent;
class APlayerCharacter;
class UAnimMontage;
class UAudioComponent;
class UParticleSystemComponent;
class UCameraShake;
class UForceFeedbackEffect;
class USoundCue;
class AImpactEffects;

namespace EWeaponState
{
	enum Type
	{
		Idle,
		Firing,
		Reloading,
		Equipping,
	};
}


USTRUCT()
struct FWeaponData
{
	GENERATED_USTRUCT_BODY()

	/** √— ¿˚¿Á ∞°¥… ≈∫æ‡ ºˆ */
	UPROPERTY(EditDefaultsOnly, Category = Ammo)
		int32 MaxAmmo;

	/** ¿Â¿¸ ªÁ¿Ã¡Ó */
	UPROPERTY(EditDefaultsOnly, Category = Ammo)
		int32 AmmoPerClip;

	/** initial clips */
	UPROPERTY(EditDefaultsOnly, Category = Ammo)
		int32 InitialClips;

	/** ø¨ªÁ ∞£ µÙ∑π¿Ã */
	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
		float TimeBetweenShots;

	/** failsafe reload duration if weapon doesn't have any animation for it */
	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
		float NoAnimReloadDuration;

	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
		float WeaponRange;

	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
		float WeaponSpread;

	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
		float WeaponTargetingSpread;

	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
		int32 HitDamage;

	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
		TSubclassOf<class UDamageType> DamageType;


	//true : HitScan
	//false : Projectile
	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
		bool IsHitScan;

	/** defaults */
	FWeaponData()
	{
		MaxAmmo = 100;
		AmmoPerClip = 30;
		InitialClips = 4;
		TimeBetweenShots = 0.2f;
		NoAnimReloadDuration = 1.0f;
		WeaponRange = 1500.0f;
		WeaponSpread = 5.0f;
		WeaponTargetingSpread = 0.25f;
		HitDamage = 10.f;
		DamageType = UDamageType::StaticClass();
		IsHitScan = true;
	}
};


UCLASS(Abstract, Blueprintable)
class FPS_GAME_API AWeapons : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeapons(const FObjectInitializer& ObjectInitializer);

	virtual void PostInitializeComponents() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	/** impact effects */
	UPROPERTY(EditDefaultsOnly, Category = Effects)
		TSubclassOf<AImpactEffects> ImpactTemplate;

	/** smoke trail */
	UPROPERTY(EditDefaultsOnly, Category = Effects)
		UParticleSystem* TrailFX;

	/** param name for beam target in smoke trail */
	UPROPERTY(EditDefaultsOnly, Category = Effects)
		FName TrailTargetParam;

	/** firing audio (bLoopedFireSound set) */
	UPROPERTY(Transient)
		UAudioComponent* FireAC;

	/** name of bone/socket for muzzle in weapon mesh */
	UPROPERTY(EditDefaultsOnly, Category = Effects)
		FName MuzzleAttachPoint;

	/** FX for muzzle flash */
	UPROPERTY(EditDefaultsOnly, Category = Effects)
		UParticleSystem* MuzzleFX;

	/** spawned component for muzzle FX */
	UPROPERTY(Transient)
		UParticleSystemComponent* MuzzlePSC;

	/** spawned component for second muzzle FX (Needed for split screen) */
	UPROPERTY(Transient)
		UParticleSystemComponent* MuzzlePSCSecondary;

	/** camera shake on firing */
	UPROPERTY(EditDefaultsOnly, Category = Effects)
		TSubclassOf<UCameraShake> FireCameraShake;

	/** force feedback effect to play when the weapon is fired */
	UPROPERTY(EditDefaultsOnly, Category = Effects)
		UForceFeedbackEffect *FireForceFeedback;

	/** single fire sound (bLoopedFireSound not set) */
	UPROPERTY(EditDefaultsOnly, Category = Sound)
		USoundCue* FireSound;

	/** looped fire sound (bLoopedFireSound set) */
	UPROPERTY(EditDefaultsOnly, Category = Sound)
		USoundCue* FireLoopSound;

	/** finished burst sound (bLoopedFireSound set) */
	UPROPERTY(EditDefaultsOnly, Category = Sound)
		USoundCue* FireFinishSound;

	/** out of ammo sound */
	UPROPERTY(EditDefaultsOnly, Category = Sound)
		USoundCue* OutOfAmmoSound;

	/** reload sound */
	UPROPERTY(EditDefaultsOnly, Category = Sound)
		USoundCue* ReloadSound;

	/** reload animations */
	UPROPERTY(EditDefaultsOnly, Category = Animation)
		UAnimMontage* ReloadAnim;


	/** equip sound */
	UPROPERTY(EditDefaultsOnly, Category = Sound)
		USoundCue* EquipSound;

	/** equip animations */
	UPROPERTY(EditDefaultsOnly, Category = Animation)
		UAnimMontage* EquipAnim;

	/** fire animations */
	UPROPERTY(EditDefaultsOnly, Category = Animation)
		UAnimMontage* FireAnim;

	/** is muzzle FX looped? */
	UPROPERTY(EditDefaultsOnly, Category = Effects)
		bool bLoopedMuzzleFX;

	/** is fire sound looped? */
	UPROPERTY(EditDefaultsOnly, Category = Sound)
		bool bLoopedFireSound;

	/** is fire animation looped? */
	UPROPERTY(EditDefaultsOnly, Category = Animation)
		bool bLoopedFireAnim;

	/** is fire animation playing? */
	bool bPlayingFireAnim;

	
	//virtual void FireWeapon() PURE_VIRTUAL(AWeapons::FireWeapon, );
	void FireWeapon();

	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		USpotLightComponent* WeaponLight;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnEnterInventory(APlayerCharacter* NewOwner);
	

	void OnEquip(const AWeapons* LastWeapon);
	void OnUnEquip();
	void SetOwnerWeapon(APlayerCharacter* Owner);

	FVector GetCameraStartLocation(const FVector &AimDir) const;

	void StartFire();
	void StopFire();

	FVector GetMuzzleLocation() const;

	void StartReload();

	int32 GetCurrentAmmo() const;
	USkeletalMeshComponent* GetWeaponMesh() const;
	EWeaponState::Type GetWeaponState() const;

	void OnBeginFocus();
	void OnEndFocus();

	FVector GetAdjustAim() const;

	UFUNCTION(BlueprintCallable, Category = "WeaponState")
		int32 GetLoadedAmmo();
	UFUNCTION(BlueprintCallable, Category = "WeaponState")
		int32 GetRemainingAmmo();

	void SetRemainingAmmo(int32 ImproveBullet);

	UPROPERTY(EditDefaultsOnly, Category = Config)
		FWeaponData WeaponConfig;

	USpotLightComponent* GetWeaponLight();

private:
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* WeaponMesh;
	UPROPERTY()
		class APlayerCharacter* WeaponOwner;

	EWeaponState::Type CurrentWeaponState;

	//Weapon Fire
	bool bIsFire;
	bool bEquipped;
	bool bPendingReload;
	bool bPendingEquip;
	bool bRefiring;

	float LastFireTime;
	float EquipStartedTime;
	float EquipDuration;

	UPROPERTY()
		int32 BurstCount;
	//¿Â¿¸µ» √—æÀ
	UPROPERTY()
		int32 LoadedAmmo;
	//≥≤¿∫ √—æÀ
	UPROPERTY()
		int32 RemainingAmmo;
	
	FTimerHandle TimerHandle_HandleFiring;
	FTimerHandle TimerHandle_OnEquipFinished;
	FTimerHandle TimerHandle_StopReload;
	FTimerHandle TimerHandle_ReloadWeapon;

	void StartSimulationWeaponFire();
	void StopSimulationWeaponFire();
	void HandleFiring();

	FHitResult HitScanLineTrace(const FVector &Start, const FVector &End) const;
	float CalcWeaponSpread() const;
	void ProcessHitScan(const FHitResult& Impact, const FVector& Origin, const FVector& ShootDir);
	
	//Decal Spawn
	void SpawnImpactEffect(const FHitResult& Impact);
	//Bullet ±À¿˚ ¿Ã∆Â∆Æ
	void SpawnTrailEffect(const FVector& EndPoint);

	bool CanFire() const;
	bool CanReload() const;

	void OnBurstStarted();
	void OnBurstFinished();

	void StopReload();
	void ReloadWeapon();

	UAudioComponent* PlayWeaponSound(USoundCue* Sound);
	float PlayWeaponAnimation(UAnimMontage* Animation);
	void StopWeaponAnimation(UAnimMontage* Animation);

	//Attach Weapon
	void AttachToPawn();
	void DetachFromPawn();

	void OnEquipFinished();

	//Weapon State
	void DetermineWeaponState();
	void SetWeaponState(EWeaponState::Type State);
};
