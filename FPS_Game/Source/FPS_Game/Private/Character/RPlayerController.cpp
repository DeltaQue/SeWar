// Fill out your copyright notice in the Description page of Project Settings.

#include "RPlayerController.h"
#include "FPS_Game.h"
#include "CameraManager.h"



ARPlayerController::ARPlayerController(const class FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	PlayerCameraManagerClass = ACameraManager::StaticClass();
}

void ARPlayerController::OnScreenMessage(FName string)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, string.ToString());
}

void ARPlayerController::OnScreenMessage(FString string)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, *string);
}

void ARPlayerController::OnScreenMessageAmmo(int32 ammo)
{
	//UE_LOG(LogClass, Log, TEXT("Remaining Ammo : %d", ammo));

	FString str = FString::Printf(TEXT("Remaining Ammo : %d"), ammo);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, str);
}

void ARPlayerController::OnScreenMessageSwitch(int32 val)
{
	switch (val)
	{
	case 0:
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Attach Success"));
		break;

	case 1:
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Attach Fail"));
		break;

	default:
		break;
	}
}

