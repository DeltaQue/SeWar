// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "FPS_Game.h"
#include "BaseCharacter.h"




APlayerCharacter::APlayerCharacter(const class FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FPP_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FPP_Camera->SetupAttachment(GetCapsuleComponent());
	FPP_Camera->RelativeLocation = FVector(-39.56f, 1.75f, 100.f); // Position the camera
	FPP_Camera->bUsePawnControlRotation = true;
	FPP_Camera->Activate(true);

	FPP_BackTargetViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("BackTargetViewCamera"));
	FPP_BackTargetViewCamera->SetupAttachment(GetCapsuleComponent());
	FPP_BackTargetViewCamera->RelativeLocation = FVector(-200.f, 1.75f, 100.f); // Position the camera
	FPP_BackTargetViewCamera->RelativeRotation = FRotator(0.f, 0.f, -180.f);
	FPP_BackTargetViewCamera->bUsePawnControlRotation = false;
	FPP_BackTargetViewCamera->Deactivate();

	GetMesh()->SetupAttachment(FPP_Camera);
	GetMesh()->bOnlyOwnerSee = true;
	GetMesh()->bOwnerNoSee = false;
	GetMesh()->bCastDynamicShadow = false;
	GetMesh()->bReceivesDecals = false;
	GetMesh()->MeshComponentUpdateFlag = EMeshComponentUpdateFlag::OnlyTickPoseWhenRendered;
	GetMesh()->PrimaryComponentTick.TickGroup = TG_PrePhysics;
	GetMesh()->SetCollisionObjectType(ECC_Pawn);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionResponseToAllChannels(ECR_Ignore);

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(COLLISION_PROJECTILE, ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(COLLISION_WEAPON, ECR_Ignore);
	GetCapsuleComponent()->SetCapsuleHalfHeight(127.5f);
	GetCapsuleComponent()->SetCapsuleRadius(95.f);


	bIsADS = false;
	bIsJumping = false;
	bIsSprint = false;

	bHasNewFocus = true;

	fDefaultSpeed = GetCharacterMovement()->MaxWalkSpeed;
	fWalkModifier = 1.f;
	fSprintModifier = 1.5f;

	WeaponAttachPoint = "WeaponPoint";
}

void APlayerCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	SetDefaultWeaponEquip();

	AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());
	GameMode->SetCheckPoint(GetActorLocation());

	//GameMode->GetCheckPoint();
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();


	/*ARPlayerController* Controller = Cast<ARPlayerController>(GetController());
	Controller->ClientSetCameraFade(true, FColor::Black, FVector2D(1.0, 0.0), 5.0f);*/
	StartFadeIn(5.0f);

	if (CurrentWeapon)
	{
		WeaponFireEvent(CurrentWeapon->GetLoadedAmmo());
	}

	if (Controller)
	{
		FTimerHandle TutorialTimer_Handle;
		GetWorld()->GetTimerManager().SetTimer(TutorialTimer_Handle, this, &APlayerCharacter::MovementTutorialOpen, 5.0f, false);
	}

}

void APlayerCharacter::OnCameraUpdate(const FVector& CameraLocation, const FRotator& CameraRotation)
{
	//USkeletalMeshComponent* DefMesh1P = Cast<USkeletalMeshComponent>(GetClass()->GetDefaultSubobjectByName(TEXT("PawnMesh1P")));
	const FMatrix DefMeshLS = FRotationTranslationMatrix(GetMesh()->RelativeRotation, GetMesh()->RelativeLocation);
	const FMatrix LocalToWorld = ActorToWorld().ToMatrixWithScale();

	const FRotator RotCameraPitch(CameraRotation.Pitch, 0.0f, 0.0f);
	const FRotator RotCameraYaw(0.0f, CameraRotation.Yaw, 0.0f);

	const FMatrix LeveledCameraLS = FRotationTranslationMatrix(RotCameraYaw, CameraLocation) * LocalToWorld.Inverse();
	const FMatrix PitchedCameraLS = FRotationMatrix(RotCameraPitch) * LeveledCameraLS;
	const FMatrix MeshRelativeToCamera = DefMeshLS * LeveledCameraLS.Inverse();
	const FMatrix PitchedMesh = MeshRelativeToCamera * PitchedCameraLS;

	//GetMesh()->SetRelativeLocationAndRotation(PitchedMesh.GetOrigin(), PitchedMesh.Rotator());
}

void APlayerCharacter::AddWeapon(AWeapons* TargetWeapon)
{
	if (TargetWeapon)
	{
		TargetWeapon->OnEnterInventory(this);
		Inventory.AddUnique(TargetWeapon);
	}
}

void APlayerCharacter::RemoveWeapon(AWeapons* TargetWeapon)
{

}

void APlayerCharacter::SetDefaultWeaponEquip()
{
	if (DefaultWeapon.Num() > 0)
	{
		int32 NumWeaponClasses = DefaultWeapon.Num();
		for (int32 i = 0; i < NumWeaponClasses; i++)
		{
			if (DefaultWeapon[i])
			{
				FActorSpawnParameters SpawnInfo;
				SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
				AWeapons* NewWeapon = GetWorld()->SpawnActor<AWeapons>(DefaultWeapon[i], SpawnInfo);
				AddWeapon(NewWeapon);

				ARPlayerController* Cont = Cast<ARPlayerController>(GetController());
				Cont->OnScreenMessageSwitch(0);
			}
		}

		if (Inventory.Num() > 0)
		{
			EquipWeapon(Inventory[0]);
		}
	}
}


void APlayerCharacter::EquipWeapon(AWeapons* NewWeapon)
{
	SetCurrentWeapon(NewWeapon, CurrentWeapon);
}


void APlayerCharacter::SetCurrentWeapon(AWeapons* NewWeapon, AWeapons* LastWeapon)
{
	AWeapons* LocalLastWeapon = NULL;

	if (LastWeapon != NULL)
	{
		LocalLastWeapon = LastWeapon;
	}
	else if (NewWeapon != CurrentWeapon)
	{
		LocalLastWeapon = CurrentWeapon;
	}

	// 이전 무기UnEquip
	if (LocalLastWeapon)
	{
		LocalLastWeapon->OnUnEquip();
	}

	CurrentWeapon = NewWeapon;

	// NewWeapon Equip
	if (NewWeapon)
	{
		NewWeapon->SetOwnerWeapon(this);

		NewWeapon->OnEquip(LastWeapon);
	}
}


void APlayerCharacter::StartWeaponFire()
{
	if (!bIsFire)
	{
		bIsFire = true;
		
		if (CurrentWeapon) 
		{
			CurrentWeapon->StartFire();
		}
	}
}


void APlayerCharacter::StopWeaponFire()
{
	if (bIsFire)
	{
		bIsFire = false;
		
		if(CurrentWeapon)
			CurrentWeapon->StopFire();
	}
}


class AWeapons* APlayerCharacter::GetWeapon() const
{
	return CurrentWeapon;
}

bool APlayerCharacter::CanFire() const
{
	return IsAlive();
}

FName APlayerCharacter::GetWeaponAttachPoint() const
{
	return WeaponAttachPoint;
}

USkeletalMeshComponent* APlayerCharacter::GetOwenerMesh() const
{
	return GetMesh();
}

void APlayerCharacter::CheckForWeaponInView(FVector CameraLocation, FVector CameraFowardVector, FRotator CameraRotator)
{
	// LineTrace로 히트되는 액터 체크
	FHitResult HitResult;

	int32 Range = 500;
	FVector StartTrace = CameraLocation;
	FVector EndTrace = (CameraFowardVector * Range) + StartTrace;

	//캐릭터 본체는 LineTrace에 Ignore해서 LineTrace에 Hit되지않게 함
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	// ECC_Visibility는 언리얼내 오브젝트 판단 유형, Visible로 되어있는 모든 액터를 대상으로 Check ??
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_Visibility, QueryParams))
	{
		AWeapons* Pickup = Cast<AWeapons>(HitResult.GetActor());

		if (Pickup)
		{
			Pickup->OnBeginFocus();
			PickupWeapon = Pickup;
		}

	}
	//Hit된 Actor가 없다면 nullptr를 
	PickupWeapon->OnEndFocus();
}


void APlayerCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::OnStartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::OnStopJump);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerCharacter::OnStartFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &APlayerCharacter::OnStopFire);
	PlayerInputComponent->BindAction("ADS", IE_Pressed, this, &APlayerCharacter::OnStartADS);
	PlayerInputComponent->BindAction("ADS", IE_Released, this, &APlayerCharacter::OnStopADS);
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &APlayerCharacter::OnReload);

	PlayerInputComponent->BindAction("Suicide", IE_Pressed, this, &ABaseCharacter::Suicide);
	PlayerInputComponent->BindAction("CheckPoint", IE_Pressed, this, &APlayerCharacter::ReturnCheckPoint);

	PlayerInputComponent->BindAction("NextWeapon", IE_Pressed, this, &APlayerCharacter::OnNextWeapon);
	PlayerInputComponent->BindAction("NextWeapon", IE_Pressed, this, &APlayerCharacter::OnPrevWeapon);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &APlayerCharacter::OnStartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &APlayerCharacter::OnStopSprint);

	PlayerInputComponent->BindAction("Use", IE_Pressed, this, &APlayerCharacter::WeaponEquip);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	

}

void APlayerCharacter::Tick(float DeltaTime)
{
}

void APlayerCharacter::OnStartJump()
{
	bIsJumping = true;
	Jump();
}

void APlayerCharacter::OnStopJump()
{
	bIsJumping = false;
	StopJumping();
}

void APlayerCharacter::OnStartFire()
{
	if (bIsSprint)
	{
		OnStopSprint();
	}
	StartWeaponFire();
}

void APlayerCharacter::OnStopFire()
{
	StopWeaponFire();
}

void APlayerCharacter::OnStartADS()
{
	bIsADS = true;
}

void APlayerCharacter::OnStopADS()
{
	bIsADS = false;
}

void APlayerCharacter::OnReload()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->StartReload();
	}

}

void APlayerCharacter::OnStartSprint()
{
	bIsSprint = true;

	GetCharacterMovement()->MaxWalkSpeed = fDefaultSpeed * fSprintModifier + fWalkModifier;
}

void APlayerCharacter::OnStopSprint()
{
	bIsSprint = false;

	GetCharacterMovement()->MaxWalkSpeed = fDefaultSpeed + fWalkModifier;
}

void APlayerCharacter::WeaponEquip()
{
	if (PickupWeapon)
	{
		AddWeapon(PickupWeapon);
	}
}

void APlayerCharacter::OnNextWeapon()
{
	ARPlayerController* Controller = Cast<ARPlayerController>(GetController());
	if (Controller)
	{
		if (Inventory.Num() >= 2 && (CurrentWeapon == NULL || CurrentWeapon->GetWeaponState() != EWeaponState::Equipping))
		{
			const int32 CurrentWeaponIdx = Inventory.IndexOfByKey(CurrentWeapon);
			AWeapons* NextWeapon = Inventory[(CurrentWeaponIdx + 1) % Inventory.Num()];
			EquipWeapon(NextWeapon);
		}
	}
}

void APlayerCharacter::OnPrevWeapon()
{
	ARPlayerController* Controller = Cast<ARPlayerController>(GetController());
	if (Controller)
	{
		if (Inventory.Num() >= 2 && (CurrentWeapon == NULL || CurrentWeapon->GetWeaponState() != EWeaponState::Equipping))
		{
			const int32 CurrentWeaponIdx = Inventory.IndexOfByKey(CurrentWeapon);
			AWeapons* PrevWeapon = Inventory[(CurrentWeaponIdx - 1 + Inventory.Num()) % Inventory.Num()];
			EquipWeapon(PrevWeapon);
		}
	}
}

void APlayerCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		//// find out which way is forward
		//const FRotator Rotation = Controller->GetControlRotation();
		//const FRotator YawRotation(0, Rotation.Yaw, 0);

		//// get forward vector
		//const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		const bool bLimitRotation = (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling());
		const FRotator Rotation = bLimitRotation ? GetActorRotation() : Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);

		if (bIsADS)
		{
			float SlowVal = Value / 2.f;

			AddMovementInput(Direction, SlowVal);
		}
		else if (!bIsADS)
		{
			AddMovementInput(Direction, Value);
		}
	}
}

void APlayerCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		//const FRotator Rotation = Controller->GetControlRotation();
		//const FRotator YawRotation(0, Rotation.Yaw, 0);

		//const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		const FQuat Rotation = GetActorQuat();
		const FVector Direction = FQuatRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);

		if (bIsADS)
		{
			float SlowVal = Value / 2.f;
			// add movement in that direction
			AddMovementInput(Direction, SlowVal);
		}
		else if (!bIsADS)
		{
			// add movement in that direction
			AddMovementInput(Direction, Value);
		}
	}
}

void APlayerCharacter::ReturnCheckPoint()
{
	AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		GameMode->GetCheckPoint();
		SetActorLocation(GameMode->GetCheckPoint());
		
	}
}

void APlayerCharacter::StopAllAnimMontages()
{
	USkeletalMeshComponent* Mesh = GetMesh();
	if (Mesh && Mesh->AnimScriptInstance)
	{
		Mesh->AnimScriptInstance->Montage_Stop(0.0f);
	}

}

void APlayerCharacter::FaceRotation(FRotator NewRotation, float DeltaTime)
{
	FRotator CurrentRotation = FMath::RInterpTo(GetActorRotation(), NewRotation, DeltaTime, 5.0f);
	Super::FaceRotation(CurrentRotation, DeltaTime);
}

void APlayerCharacter::SwitchTargetCamera(float BlendTime)
{
	ARPlayerController* Controller = Cast<ARPlayerController>(GetController());

	FViewTargetTransitionParams prams;
	prams.BlendTime = BlendTime;

	//Controller->SetViewTargetWithBlend(FPP_BackTargetViewCamera, prams);

	if (FPP_Camera->IsActive() && !FPP_BackTargetViewCamera->IsActive())
	{
		FPP_Camera->Deactivate();
		FPP_BackTargetViewCamera->Activate();
	}
	else if (!FPP_Camera->IsActive() && FPP_BackTargetViewCamera->IsActive())
	{
		FPP_BackTargetViewCamera->Deactivate();
		FPP_Camera->Activate();
	}

	FTimerHandle CameraTimerHandle;
	GetWorldTimerManager().SetTimer(CameraTimerHandle, this, &APlayerCharacter::SwitchMyCamera, 5.0f, false);
}

void APlayerCharacter::SwitchMyCamera()
{
	if (FPP_Camera->IsActive() && !FPP_BackTargetViewCamera->IsActive())
	{
		FPP_Camera->Deactivate();
		FPP_BackTargetViewCamera->Activate();
	}
	else if (!FPP_Camera->IsActive() && FPP_BackTargetViewCamera->IsActive())
	{
		FPP_BackTargetViewCamera->Deactivate();
		FPP_Camera->Activate();
	}
}


bool APlayerCharacter::IsTargeting() const
{
	return bIsADS;
}

bool APlayerCharacter::IsJumping() const
{
	return bIsSprint;
}

bool APlayerCharacter::IsSprint() const
{
	return bIsSprint;
}

bool APlayerCharacter::IsFire() const
{
	return bIsFire;
}

float APlayerCharacter::GetDefaultSpeed()
{
	return fDefaultSpeed + fWalkModifier;
}

float APlayerCharacter::GetPlayerHP()
{
	return GetHealth();
}


void APlayerCharacter::MovementTutorialOpen()
{
	ARPlayerController* PlayerController = Cast<ARPlayerController>(GetController());

	PlayerController->OpenGuideWidget(0);
}

void APlayerCharacter::StartFadeOut(float Time)
{
	ARPlayerController* Controller = Cast<ARPlayerController>(GetController());
	Controller->ClientSetCameraFade(true, FColor::Black, FVector2D(0.0, 1.0), Time);
}

void APlayerCharacter::StartFadeIn(float Time)
{
	ARPlayerController* Controller = Cast<ARPlayerController>(GetController());
	Controller->ClientSetCameraFade(true, FColor::Black, FVector2D(1.0, 0.0), Time);
}