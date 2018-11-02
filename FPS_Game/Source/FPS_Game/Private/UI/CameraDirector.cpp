// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraDirector.h"
#include "RPlayerController.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	ARPlayerController* Controller = Cast<ARPlayerController>(OurPlayerController);
	if (Controller->bTurnViewTarget)
	{
		SwitchCameraViewTarget(4.0f);
	}
}

void ACameraDirector::SwitchCameraViewTarget(float BlendTime)
{
	APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	ARPlayerController* Controller = Cast<ARPlayerController>(OurPlayerController);

	Controller->bTurnViewTarget = false;

	if (OurPlayerController)
	{
		if ((OurPlayerController->GetViewTarget() != CameraTwo) && (CameraTwo != nullptr))
		{
			//Blend smoothly to camera two.
			OurPlayerController->SetViewTargetWithBlend(CameraTwo, BlendTime);


			FTimerHandle CameraTimer_Handle;
			/*FTimerDelegate CameraFuncDelegate = FTimerDelegate::CreateUObject(this, &ACameraDirector::SwitchPlayerCamera, BlendTime);
			GetWorldTimerManager().SetTimer(CameraTimer_Handle, CameraFuncDelegate, 5.0f, false);*/
			GetWorldTimerManager().SetTimer(CameraTimer_Handle, this, &ACameraDirector::SwitchPlayerCamera, 10.0f, false);
		}
	}
}


void ACameraDirector::SwitchPlayerCamera()
{
	APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	ARPlayerController* Controller = Cast<ARPlayerController>(OurPlayerController);
	if (OurPlayerController)
	{
		if ((OurPlayerController->GetViewTarget() == CameraTwo) && (CameraTwo != nullptr))
		{
			//Blend smoothly to camera two.
			OurPlayerController->SetViewTargetWithBlend(Controller->GetPawn(), 1.8f);

			FTimerHandle TutorialTimer_Handle;
			GetWorld()->GetTimerManager().SetTimer(TutorialTimer_Handle, this, &ACameraDirector::WeaponTutorialOpen, 3.4f, false);
		}
	}
}


void ACameraDirector::WeaponTutorialOpen()
{
	APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	ARPlayerController* PlayerController = Cast<ARPlayerController>(OurPlayerController);

	PlayerController->OpenGuideWidget(1);
}