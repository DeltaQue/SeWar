// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapons.h"
#include "FPS_Game.h"
#include "PlayerDamageType.h"
#include "LaserActor.h"
#include "Components/SpotLightComponent.h"


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

	WeaponLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("WeaponLight"));
	WeaponLight->AttachToComponent(WeaponMesh, FAttachmentTransformRules::KeepRelativeTransform, FName("MuzzleFlashSocket"));
	WeaponLight->RelativeLocation = FVector(16.f, 0.0f, -6.f); 
	WeaponLight->RelativeRotation = FRotator(0.f, 5.f, 0.f);

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
	//실질적인 데미지를 가하는 함수
	//HitScan방식, 

	//Controller의 Camera Rot vector
	/*const FVector AimDir = GetAdjustAim();
	const float CurrentSpread = CalcWeaponSpread();
	const FVector StartVector = MuzzleTransform.GetLocation();
	const FVector EndVector = StartVector * WeaponConfig.WeaponRange;

	const FHitResult Impact = HitScanLinTrace(StartVector, EndVector);

	ProcessHitScan(Impact, StartVector, AimDir, CurrentSpread);*/

	/////////////////////////

	const int32 RandomSeed = FMath::Rand();
	FRandomStream WeaponRandomStream(RandomSeed);
	const float CurrentSpread = CalcWeaponSpread();
	const float ConeHalfAngle = FMath::DegreesToRadians(CurrentSpread * 0.5f);

	//WeaponConfig.WeaponRange BP에서 설정해줘야함

	const FVector AimDir = GetAdjustAim();
	const FVector CameraPos = GetCameraStartLocation(AimDir);
	const FVector EndPos = CameraPos + (AimDir * WeaponConfig.WeaponRange);
	FHitResult Impact = HitScanLineTrace(CameraPos, EndPos);

	const FVector MuzzleOrigin = GetMuzzleLocation();

	FVector AdjustedAimDir = AimDir;
	if (Impact.bBlockingHit)
	{
		AdjustedAimDir = (Impact.ImpactPoint - MuzzleOrigin).GetSafeNormal();

		Impact = HitScanLineTrace(MuzzleOrigin, MuzzleOrigin + (AdjustedAimDir * WeaponConfig.WeaponRange));
	}
	else
	{
		Impact.ImpactPoint = FVector_NetQuantize(EndPos);
	}

	ProcessHitScan(Impact, MuzzleOrigin, AdjustedAimDir);

	//
	//DrawDebugPoint(GetWorld(), CameraPos, 20.f,  FColor::Red, false, 999999, SDPG_MAX);
	//DrawDebugPoint(GetWorld(), EndPos, 20.f, FColor::Green, false, 999999, SDPG_MAX);
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
		Instigator = Owner;
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
		if (RemainingAmmo <= 0 && CanReload())
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
	if (RemainingAmmo > 0 && WeaponConfig.AmmoPerClip > LoadedAmmo)
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
			RemainingAmmo -= (WeaponConfig.AmmoPerClip - LoadedAmmo);
			LoadedAmmo += (WeaponConfig.AmmoPerClip - LoadedAmmo);
		}

		WeaponOwner->WeaponFireEvent(LoadedAmmo);
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
			FireWeapon();

			LoadedAmmo--;

			WeaponOwner->WeaponFireEvent(LoadedAmmo);

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

	if (WeaponOwner)
	{
		WeaponOwner->MakePawnNoise(1.f);
	}

	//LastFireTime을 발사시간으로 초기화 하여, 연사시 딜레이 타임 체크
	LastFireTime = GetWorld()->GetTimeSeconds();
}

FHitResult AWeapons::HitScanLineTrace(const FVector &Start, const FVector &End) const
{
	FCollisionQueryParams TraceParams(TEXT("WeaponTrace"), true, Instigator);
	TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = true;

	FHitResult Hit(ForceInit);
	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, COLLISION_WEAPON, TraceParams);

	return Hit;
}


float AWeapons::CalcWeaponSpread() const
{
	if (WeaponOwner && WeaponOwner->IsTargeting())
	{
		return WeaponConfig.WeaponSpread * WeaponConfig.WeaponTargetingSpread;
	}
	else
	{
		return WeaponConfig.WeaponSpread;
	}
}

void AWeapons::ProcessHitScan(const FHitResult & Impact, const FVector & Origin, const FVector & ShootDir)
{
	if (Impact.GetActor()->ActorHasTag("DestructibleMesh") && Impact.GetActor() != WeaponOwner && Impact.GetActor() != this )
	{
		ALaserActor* Dest = Cast<ALaserActor>(Impact.GetActor());
		if (Dest)
		{
			if (Dest->GetDestructibleComponent()->IsSimulatingPhysics())
			{
				Dest->GetDestructibleComponent()->SetSimulatePhysics(true);
				Dest->GetDestructibleComponent()->AddRadialForce(Impact.Location, 500.f, 1000000.f, RIF_Constant);
			}
		}
	}

	if(Impact.GetActor()->ActorHasTag("Zombie") || Impact.GetActor()->ActorHasTag("Boss"))
	{
		if (Impact.GetActor() && Impact.GetActor() != WeaponOwner && Impact.GetActor() != this)
		{
			float ActualDamage = WeaponConfig.HitDamage;

			UPlayerDamageType* DmgType = Cast<UPlayerDamageType>(WeaponConfig.DamageType->GetDefaultObject());
			UPhysicalMaterial * PhysMat = Impact.PhysMaterial.Get();
			if (PhysMat && DmgType)
			{
				if (PhysMat->SurfaceType == SURFACE_ZOMBIEHEAD)
				{
					ActualDamage *= DmgType->GetHeadDamageModifier();
				}
				else if (PhysMat->SurfaceType == SURFACE_ZOMBIEBODY)
				{
					ActualDamage *= DmgType->GetBodyDamageModifier();
				}
				else if (PhysMat->SurfaceType == SURFACE_ZOMBIELIMB)
				{
					ActualDamage *= DmgType->GetLimbDamageModifier();
				}
			}

			FPointDamageEvent PointDmg;
			PointDmg.DamageTypeClass = WeaponConfig.DamageType;
			PointDmg.HitInfo = Impact;
			PointDmg.HitInfo.Actor = Impact.Actor;
			PointDmg.ShotDirection = ShootDir;
			PointDmg.Damage = ActualDamage;

			Impact.GetActor()->TakeDamage(PointDmg.Damage, PointDmg, WeaponOwner->Controller, this);
		}

		const FVector MuzzleOrigin = GetMuzzleLocation();
		//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("You are MuzzleLocation: %d, %d, %d"), MuzzleOrigin.X, MuzzleOrigin.Y, MuzzleOrigin.Z));

		const FVector AimDir = (Impact.ImpactPoint - MuzzleOrigin).GetSafeNormal();

		const FVector EndTrace = MuzzleOrigin + (AimDir * WeaponConfig.WeaponRange);
		const FHitResult ImpactResult = HitScanLineTrace(MuzzleOrigin, EndTrace);

		if (ImpactResult.bBlockingHit)
		{
			SpawnImpactEffect(ImpactResult);
			//SpawnTrailEffect(ImpactResult.ImpactPoint);
		}
		else
		{
			//SpawnTrailEffect(EndTrace);
		}
	}
}

void AWeapons::SpawnImpactEffect(const FHitResult & Impact)
{
	if (ImpactTemplate && Impact.bBlockingHit)
	{
		// TODO: Possible re-trace to get hit component that is lost during replication.

		AImpactEffects* EffectActor = GetWorld()->SpawnActorDeferred<AImpactEffects>(ImpactTemplate, FTransform(Impact.ImpactPoint.Rotation(), Impact.ImpactPoint));
		if (EffectActor)
		{
			EffectActor->SurfaceHit = Impact;
			UGameplayStatics::FinishSpawningActor(EffectActor, FTransform(Impact.ImpactNormal.Rotation(), Impact.ImpactPoint));
		}
	}
}

void AWeapons::SpawnTrailEffect(const FVector & EndPoint)
{
	if (TrailFX)
	{
		const FVector AimDir = GetAdjustAim();
		const FVector CameraPos = GetCameraStartLocation(AimDir);
		const FVector Origin = GetMuzzleLocation();

		//UParticleSystemComponent* TrailPSC = UGameplayStatics::SpawnEmitterAtLocation(this, TrailFX, CameraPos);
		UParticleSystemComponent* TrailPSC = UGameplayStatics::SpawnEmitterAtLocation(this, TrailFX, Origin);
		if (TrailPSC)
		{
			TrailPSC->SetVectorParameter(TrailTargetParam, EndPoint);
		}
	}
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
	bool bAmmoCheck = (LoadedAmmo < WeaponConfig.AmmoPerClip) && (RemainingAmmo > 0);
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

int32 AWeapons::GetLoadedAmmo()
{
	return LoadedAmmo;
}

int32 AWeapons::GetRemainingAmmo()
{
	return RemainingAmmo;
}

FVector AWeapons::GetAdjustAim() const
{
	ARPlayerController* const PlayerController = Instigator ? Cast<ARPlayerController>(Instigator->Controller) : nullptr;
	FVector AdjustAim = FVector::ZeroVector;

	if (PlayerController)
	{
		FVector Loc;
		FRotator Rot;
		PlayerController->GetPlayerViewPoint(Loc, Rot);
		AdjustAim = Rot.Vector();
	}

	return AdjustAim;
}

FVector AWeapons::GetCameraStartLocation(const FVector &AimDir) const
{
	ARPlayerController* PC = WeaponOwner ? Cast<ARPlayerController>(WeaponOwner->Controller) : NULL;
	FVector OutStartTrace = FVector::ZeroVector;

	if (PC)
	{
		FRotator UnusedRot;
		PC->GetPlayerViewPoint(OutStartTrace, UnusedRot);

		//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("You are Startlocation: %d, %d, %d"),Instigator->GetActorLocation().X, Instigator->GetActorLocation().Y, Instigator->GetActorLocation().Z));
		//OutStartTrace = OutStartTrace + AimDir * ((Instigator->GetActorLocation() - OutStartTrace) | AimDir);
		OutStartTrace = OutStartTrace + AimDir * (FVector::DotProduct((Instigator->GetActorLocation() - OutStartTrace), AimDir));
	}

	return OutStartTrace;
}


FVector AWeapons::GetMuzzleLocation() const
{
	return WeaponMesh->GetSocketLocation("MuzzleFlashSocket");
}

void AWeapons::SetRemainingAmmo(int32 ImproveAmmo)
{
	if (WeaponConfig.MaxAmmo >= RemainingAmmo + ImproveAmmo)
	{
		RemainingAmmo += ImproveAmmo;
	}
	else if (WeaponConfig.MaxAmmo < RemainingAmmo + ImproveAmmo)
	{
		RemainingAmmo = WeaponConfig.MaxAmmo;
	}
}

void AWeapons::SetLoadedAmmo(int32 ImproveAmmo)
{
	if (WeaponConfig.AmmoPerClip >= LoadedAmmo + ImproveAmmo)
	{
		LoadedAmmo += ImproveAmmo;
	}
	else if (WeaponConfig.AmmoPerClip < LoadedAmmo + ImproveAmmo)
	{
		LoadedAmmo = WeaponConfig.AmmoPerClip;
	}
}


EWeaponState::Type AWeapons::GetWeaponState() const
{
	return CurrentWeaponState;
}


USpotLightComponent* AWeapons::GetWeaponLight()
{
	if (WeaponLight)
		return WeaponLight;
	else
		return nullptr;
}