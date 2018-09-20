// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapons.h"
#include "FPS_Game.h"



// Sets default values
AWeapons::AWeapons(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WeaponMesh = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("WeaponMesh1P"));
	WeaponMesh->MeshComponentUpdateFlag = EMeshComponentUpdateFlag::OnlyTickPoseWhenRendered;
	WeaponMesh->bReceivesDecals = false;
	WeaponMesh->CastShadow = false;
	WeaponMesh->SetCollisionObjectType(ECC_WorldDynamic);
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WeaponMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	RootComponent = WeaponMesh;


	bLoopedMuzzleFX = false;
	bLoopedFireAnim = false;
	bPlayingFireAnim = false;
	bEquipped = false;
	bIsFire = false;
	bPendingReload = false;
	bPendingEquip = false;
	CurrentWeaponState = EWeaponState::Idle;

	LoadedAmmo = 30;
	RemainingAmmo = 30;
	BurstCount = 0;
	LastFireTime = 0.0f;
}

void AWeapons::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	DetachFromPawn();
}

void AWeapons::BeginPlay()
{
	Super::BeginPlay();
	
}


void AWeapons::OnBeginFocus()
{
	//WeaponMesh->SetRenderCustomDepth(true);
}

void AWeapons::OnEndFocus()
{
	//WeaponMesh->SetRenderCustomDepth(false);
}

void AWeapons::FireWeapon()
{
}

void AWeapons::StartReload()
{
	if (CanReload())
	{
		bPendingReload = true;
		DetermineWeaponState();

		float AnimDuration = PlayWeaponAnimation(ReloadAnim);
		if (AnimDuration <= 0.0f)
		{
			AnimDuration = WeaponConfig.NoAnimReloadDuration;
		}

		GetWorldTimerManager().SetTimer(TimerHandle_StopReload, this, &AWeapons::StopReload, AnimDuration, false);
		
		GetWorldTimerManager().SetTimer(TimerHandle_ReloadWeapon, this, &AWeapons::ReloadWeapon, FMath::Max(0.1f, AnimDuration - 0.1f), false);
		

		if (WeaponOwner)
		{
			PlayWeaponSound(ReloadSound);
		}
	}

}


void AWeapons::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ARPlayerController* cont = Cast<ARPlayerController>(WeaponOwner->GetController());
	cont->OnScreenMessageAmmo(LoadedAmmo);
}

void AWeapons::OnEnterInventory(APlayerCharacter* NewOwner)
{
	SetOwnerWeapon(NewOwner);
}

void AWeapons::OnEquip(const AWeapons* LastWeapon)
{
	AttachToPawn();

	if (LastWeapon)
	{
		float Duration = PlayWeaponAnimation(EquipAnim);
		if (Duration <= 0.0f)
		{
			Duration = 0.5f;
		}
		EquipStartedTime = GetWorld()->GetTimeSeconds();
		EquipDuration = Duration;

		GetWorldTimerManager().SetTimer(TimerHandle_OnEquipFinished, this, &AWeapons::OnEquipFinished, Duration, false);

	}

	else
	{
		OnEquipFinished();
	}

	if (WeaponOwner)
	{
		PlayWeaponSound(EquipSound);
	}
}


void AWeapons::OnUnEquip()
{
	DetachFromPawn();
	bEquipped = false;
	StopFire();

	if (bPendingReload)
	{
		StopWeaponAnimation(ReloadAnim);
		bPendingReload = false;

		GetWorldTimerManager().ClearTimer(TimerHandle_StopReload);
		GetWorldTimerManager().ClearTimer(TimerHandle_ReloadWeapon);
	}

	if (bPendingEquip)
	{
		StopWeaponAnimation(EquipAnim);
		bPendingEquip = false;

		GetWorldTimerManager().ClearTimer(TimerHandle_OnEquipFinished);
	}

	DetermineWeaponState();
}


void AWeapons::SetOwnerWeapon(APlayerCharacter* Owner)
{
	if (WeaponOwner != Owner)
	{
		WeaponOwner = Owner;

		SetOwner(Owner);
	}
}


void AWeapons::StartFire()
{
	if (!bIsFire)
	{
		bIsFire = true;
		DetermineWeaponState();
	}
}


void AWeapons::StopFire()
{
	if (bIsFire)
	{
		bIsFire = false;
		DetermineWeaponState();
	}

}


void AWeapons::AttachToPawn()
{
	if (WeaponOwner)
	{
		DetachFromPawn();

		FName AttachSocketName = WeaponOwner->GetWeaponAttachPoint();
		USkeletalMeshComponent* AttachMesh = WeaponOwner->GetOwenerMesh();

		WeaponMesh->SetHiddenInGame(false);
		WeaponMesh->AttachToComponent(AttachMesh, FAttachmentTransformRules::KeepRelativeTransform, AttachSocketName);
	}
}

void AWeapons::DetachFromPawn()
{
	if (WeaponMesh)
	{
		WeaponMesh->DetachFromComponent(FDetachmentTransformRules::KeepRelativeTransform);
		WeaponMesh->SetHiddenInGame(true);
	}
}

void AWeapons::OnEquipFinished()
{
	AttachToPawn();

	bEquipped = true;
	bPendingEquip = false;

	DetermineWeaponState();

	if (WeaponOwner)
	{
		if (LoadedAmmo <= 0 && CanReload())
		{
			StartReload();
		}
	}
}

void AWeapons::DetermineWeaponState()
{
	EWeaponState::Type NewState = EWeaponState::Idle;

	if (bEquipped)
	{
		if (bPendingReload)
		{
			if (CanReload() == false)
			{
				NewState = CurrentWeaponState;
			}
			else
			{
				NewState = EWeaponState::Reloading;
			}
		}
		else if ((bPendingReload == false) && (bIsFire == true) && (CanFire() == true))
		{
			NewState = EWeaponState::Firing;

			ARPlayerController* cont = Cast<ARPlayerController>(WeaponOwner->GetController());
			cont->OnScreenMessageSwitch(0);
		}
	}
	else if (bPendingEquip)
	{
		NewState = EWeaponState::Equipping;
	}

	SetWeaponState(NewState);

}

void AWeapons::SetWeaponState(EWeaponState::Type NewState)
{
	const EWeaponState::Type PrevState = CurrentWeaponState;

	if (PrevState == EWeaponState::Firing && NewState != EWeaponState::Firing)
	{
		OnBurstFinished();
	}

	CurrentWeaponState = NewState;

	if (PrevState != EWeaponState::Firing && NewState == EWeaponState::Firing)
	{
		OnBurstStarted();
		
	}
}


void AWeapons::OnBurstStarted()
{
	//현재 시간
	const float GameTime = GetWorld()->GetTimeSeconds();

	//딜레이 체크
	if (LastFireTime > 0 && WeaponConfig.TimeBetweenShots > 0.0f &&
		LastFireTime + WeaponConfig.TimeBetweenShots > GameTime)
	{
		GetWorldTimerManager().SetTimer(TimerHandle_HandleFiring, this, &AWeapons::HandleFiring, LastFireTime + WeaponConfig.TimeBetweenShots - GameTime, false);
	}
	else
	{
		HandleFiring();
	}
}

void AWeapons::OnBurstFinished()
{
	BurstCount = 0;
	
	StopSimulationWeaponFire();

	GetWorldTimerManager().ClearTimer(TimerHandle_HandleFiring);
	bRefiring = false;
}

void AWeapons::StopReload()
{
	if (CurrentWeaponState == EWeaponState::Reloading)
	{
		bPendingReload = false;
		DetermineWeaponState();
		StopWeaponAnimation(ReloadAnim);
	}
}

void AWeapons::ReloadWeapon()
{
	if (RemainingAmmo > 0)
	{
		// 장전할 총알이 남은 총알보다 더 많거나 같을 경우 
		// ex) 30-20 >= 9, 10발 충전해야하지만 9발만 장전
		if ((WeaponConfig.AmmoPerClip - LoadedAmmo) >= RemainingAmmo)
		{
			LoadedAmmo += RemainingAmmo;
			RemainingAmmo = 0;
		}
		// ex) 30-20 < 50, 장전할 총알보다 남은 총알이 더 많을경우
		else if ((WeaponConfig.AmmoPerClip - LoadedAmmo) < RemainingAmmo)
		{
			LoadedAmmo += (WeaponConfig.AmmoPerClip - LoadedAmmo);
			RemainingAmmo -= (WeaponConfig.AmmoPerClip - LoadedAmmo);
		}
	}
}

UAudioComponent* AWeapons::PlayWeaponSound(USoundCue * Sound)
{
	UAudioComponent* AC = NULL;
	if (Sound && WeaponOwner)
	{
		AC = UGameplayStatics::SpawnSoundAttached(Sound, WeaponOwner->GetRootComponent());
	}

	return AC;
}

float AWeapons::PlayWeaponAnimation(UAnimMontage* Animation)
{
	float Duration = 0.0f;
	if (WeaponOwner)
	{
		if (Animation)
		{
			Duration = WeaponOwner->PlayAnimMontage(Animation);
		}
	}

	return Duration;
}

void AWeapons::StopWeaponAnimation(UAnimMontage * Animation)
{
	if (WeaponOwner)
	{
		WeaponOwner->StopAnimMontage(Animation);
	}
}


void AWeapons::StartSimulationWeaponFire()
{
	if (CurrentWeaponState != EWeaponState::Firing)
	{
		return;
	}

	if (MuzzleFX)
	{
		USkeletalMeshComponent* UseWeaponMesh = GetWeaponMesh();
		if (!bLoopedMuzzleFX || MuzzlePSC == NULL)
		{
			if (WeaponOwner != NULL)
			{
				AController* PlayerCon = WeaponOwner->GetController();
				if (PlayerCon != NULL)
				{
					WeaponMesh->GetSocketLocation(MuzzleAttachPoint);
					MuzzlePSC = UGameplayStatics::SpawnEmitterAttached(MuzzleFX, WeaponMesh, MuzzleAttachPoint);
					MuzzlePSC->bOwnerNoSee = false;
					MuzzlePSC->bOnlyOwnerSee = true;
				}
			}
			else
			{
				MuzzlePSC = UGameplayStatics::SpawnEmitterAttached(MuzzleFX, UseWeaponMesh, MuzzleAttachPoint);
			}
		}
	}

	if (!bLoopedFireAnim || !bPlayingFireAnim)
	{
		PlayWeaponAnimation(FireAnim);
		bPlayingFireAnim = true;
	}

	if (bLoopedFireSound)
	{
		if (FireAC == NULL)
		{
			FireAC = PlayWeaponSound(FireLoopSound);
		}
	}
	else
	{
		PlayWeaponSound(FireSound);
	}

	APlayerController* PC = (WeaponOwner != NULL) ? Cast<APlayerController>(WeaponOwner->Controller) : NULL;
	if (PC != NULL && PC->IsLocalController())
	{
		if (FireCameraShake != NULL)
		{
			//Camera Shake로 Weapon 반동 추가
			PC->ClientPlayCameraShake(FireCameraShake, 1);
		}
	}
}


void AWeapons::StopSimulationWeaponFire()
{
	if (bLoopedMuzzleFX)
	{
		if (MuzzlePSC != NULL)
		{
			MuzzlePSC->DeactivateSystem();
			MuzzlePSC = NULL;
		}
		if (MuzzlePSCSecondary != NULL)
		{
			MuzzlePSCSecondary->DeactivateSystem();
			MuzzlePSCSecondary = NULL;
		}
	}

	if (bLoopedFireAnim && bPlayingFireAnim)
	{
		StopWeaponAnimation(FireAnim);
		bPlayingFireAnim = false;
	}

	//Audio Clip
	if (FireAC)
	{
		FireAC->FadeOut(0.1f, 0.0f);
		FireAC = NULL;

		PlayWeaponSound(FireFinishSound);
	}
}

void AWeapons::HandleFiring()
{
	if ((LoadedAmmo > 0) && CanFire())
	{

		StartSimulationWeaponFire();

		if (WeaponOwner)
		{
			//FireWeapon();

			LoadedAmmo--;

			BurstCount++;
		}
	}
	//총알이 없을 경우
	else if (CanReload())
	{
		StartReload();
	}
	//재장전을 하고 난 뒤에도 총알이 없을 경우, 남은 탄약이 0일경우
	else if (WeaponOwner)
	{
		if (LoadedAmmo == 0 && !bRefiring)
		{
			PlayWeaponSound(OutOfAmmoSound);

			/*ARPlayerController* MyPC = Cast<ARPlayerController>(WeaponOwner->Controller);
			AShooterHUD* MyHUD = MyPC ? Cast<AShooterHUD>(MyPC->GetHUD()) : NULL;
			if (MyHUD)
			{
				MyHUD->NotifyOutOfAmmo();
			}*/
		}

		if (BurstCount > 0)
		{
			OnBurstFinished();
		}
	}

	if (WeaponOwner)
	{
		if (LoadedAmmo <= 0 && CanReload())
		{
			StartReload();
		}

		bRefiring = (CurrentWeaponState == EWeaponState::Firing && WeaponConfig.TimeBetweenShots > 0.0f);
		if (bRefiring)
		{
			GetWorldTimerManager().SetTimer(TimerHandle_HandleFiring, this, &AWeapons::HandleFiring, WeaponConfig.TimeBetweenShots, false);
		}
	}

	//LastFireTime을 발사시간으로 초기화 하여, 연사시 딜레이 타임 체크
	LastFireTime = GetWorld()->GetTimeSeconds();
}

bool AWeapons::CanFire() const
{
	bool bAmmoCheck = (LoadedAmmo > 0);
	bool bCanFire = (WeaponOwner && WeaponOwner->CanFire());
	bool bWeaponStateCheck = ((CurrentWeaponState == EWeaponState::Idle) || (CurrentWeaponState == EWeaponState::Firing));
	return ((bCanFire == true) && (bWeaponStateCheck == true) && (bPendingReload == false) && (bAmmoCheck == true));
}


bool AWeapons::CanReload() const
{
	bool bAmmoCheck = (LoadedAmmo < WeaponConfig.AmmoPerClip);
	bool bWeaponStateCheck = ((CurrentWeaponState == EWeaponState::Idle) || (CurrentWeaponState == EWeaponState::Firing));

	return ((bAmmoCheck == true) && (bWeaponStateCheck == true));
}

int32 AWeapons::GetCurrentAmmo() const
{
	return LoadedAmmo;
}

USkeletalMeshComponent* AWeapons::GetWeaponMesh() const
{
	return WeaponMesh;
}