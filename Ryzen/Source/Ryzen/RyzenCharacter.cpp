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
//////////////////////////////////////////////////////////////////////////
// ARyzenCharacter

ARyzenCharacter::ARyzenCharacter()
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
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm



	CollectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollectionSphere"));
	CollectionSphere->SetupAttachment(RootComponent);
	CollectionSphere->SetSphereRadius(200.f);

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
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