// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "RyzenCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Interactable.h"
#include "AutoPickup.h"
#include "InventoryItem.h"
#include "RyzenController.h"
#include "UObject/ConstructorHelpers.h"
//////////////////////////////////////////////////////////////////////////
// ARyzenCharacter

ARyzenCharacter::ARyzenCharacter() : GunOffset(FVector(68.0f, 16.0f, 24.0f)), CameraOffset(FVector(0,0,70.0f))
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	//CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->TargetArmLength = 0;
	CameraBoom->bUsePawnControlRotation = false; // Rotate the arm based on the controller
	CameraBoom->CameraRotationLagSpeed = 1.f;

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	//FollowCamera->AttachTo(CharacterMesh, "head");
	FollowCamera->bUsePawnControlRotation = false;

	//Collection Sphere Initialized
	CollectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollectionSphere"));
	CollectionSphere->SetupAttachment(RootComponent);
	CollectionSphere->SetSphereRadius(200.f);

	// Ryzen Character Mesh Initialized
	CharacterMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh"));
	CharacterMesh->SetOnlyOwnerSee(true);
	CharacterMesh->SetupAttachment(FollowCamera);
	CharacterMesh->bCastDynamicShadow = false;
	CharacterMesh->CastShadow = false;
	CharacterMesh->RelativeRotation = FRotator(1.9f, -19.19f, 5.2f);
	CharacterMesh->RelativeLocation = FVector(-0.5f, -4.4f, -155.7f);

	JumpButtonDown = false;

 // Camera does not rotate relative to arm

	//Gun muzzle Location Initialized 
	

	//static ConstructorHelpers::FObjectFinder<USoundBase> FireSoundobj(TEXT("/Game/RyzenBP/Texture/FirstPersonCrosshair"));
	//FireSound = 
}

//////////////////////////////////////////////////////////////////////////
// Input

void ARyzenCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &ARyzenCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ARyzenCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ARyzenCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ARyzenCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ARyzenCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ARyzenCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &ARyzenCharacter::OnResetVR);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ARyzenCharacter::OnFire);

}


void ARyzenCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ARyzenCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void ARyzenCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void ARyzenCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ARyzenCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ARyzenCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ARyzenCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void ARyzenCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	//FP_Gun->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));


}

void ARyzenCharacter::Tick(float Deltatime)
{
	Super::Tick(Deltatime);

	// Collection Sphere를 Tick마다 확인 
	CollectAutoPickups();
	CheckForInteractables();
}

//AutoPickup
void ARyzenCharacter::CollectAutoPickups()
{
	// Actor*배열을 만들어 Collection Sphere에 오버랩된 액터를 배열에 추가
	TArray<AActor*> CollectedActors;
	CollectionSphere->GetOverlappingActors(CollectedActors);

	//GetController()로 현재 컨트롤러를 받아와 RyzenController로 캐스트시킴
	ARyzenController* RController = Cast<ARyzenController>(GetController());


	for (int32 iCollected = 0; iCollected < CollectedActors.Num(); ++iCollected)
	{
		// Cast the actor to AAutoPickup
		AAutoPickup* const TestPickup = Cast<AAutoPickup>(CollectedActors[iCollected]);
		

		//IsPendingkill()은 Actor가 아직 GC에 들어가 메모리가 아직 해제되지 않았는지를 판단하는 함수
		if (TestPickup && !TestPickup->IsPendingKill())
		{
			TestPickup->Collect(RController);
		}
	}
}

//Collection Sphere에 MaualPickup 가능한 물체가 있는지 판단하는 함수
void ARyzenCharacter::CheckForInteractables()
{
	// LineTrace로 히트되는 액터 체크
	FHitResult HitResult;

	int32 Range = 500;
	FVector StartTrace = FollowCamera->GetComponentLocation();
	FVector EndTrace = (FollowCamera->GetForwardVector() * Range) + StartTrace;

	//캐릭터 본체는 LineTrace에 Ignore해서 LineTrace에 Hit되지않게 함
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	ARyzenController* RController = Cast<ARyzenController>(GetController());

	if (RController)
	{
		// ECC_Visibility는 언리얼내 오브젝트 판단 유형, Visible로 되어있는 모든 액터를 대상으로 Check ??
		if (GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_Visibility, QueryParams))
		{
			AInteractable* Interactable = Cast<AInteractable>(HitResult.GetActor());


			if (Interactable)
			{
				RController->CurrentInteractable = Interactable;
				return;
			}
		}
		//Hit된 Actor가 없다면 nullptr를 
		RController->CurrentInteractable = nullptr;
	}
}
//
//void ARyzenCharacter::CheckForManualPickup(AInteractable *Things)
//{
//
//	ARyzenController* RController = Cast<ARyzenController>(GetController());
//
//	if (RController) 
//	{
//		AInteractable* Manual = Cast<AInteractable>(Things);
//
//		if (Manual)
//		{
//			RController->CurrentInteractable = Manual;
//			return;
//		}
//
//		RController->CurrentInteractable = nullptr;
//	}
//
//}

void ARyzenCharacter::OnFire()
{

	if (Bullets != NULL)
	{
		UWorld* const World = GetWorld();
		if (World != NULL)
		{
			const FRotator SpawnRotation = GetControlRotation();
			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			const FVector SpawnLocation = ((MuzzleLocation != nullptr) ? MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

			//Set Spawn Collision Handling Override
			//액터의 콜리전을 생성될때 무언가에 충돌하면서 생성된다면 생성하지 못하게 셋팅
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

			// spawn the projectile at the muzzle
			World->SpawnActor<ABullet>(Bullets, SpawnLocation, SpawnRotation, ActorSpawnParams);
		}
	}

	if (FireSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	//Fire 애니메이션 몽타주를 엔진에서 지정 했을때만 사용 가능
	if (FireAnimation != NULL)
	{
		AnimInstance = CharacterMesh->GetAnimInstance();
		if (AnimInstance != NULL)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}

	if (ParticleFX != NULL)
	{
		FVector loc = CharacterMesh->GetSocketLocation("Muzzle");
		FRotator rot = CharacterMesh->GetSocketRotation("Muzzle");
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleFX, loc, rot);
	}
}