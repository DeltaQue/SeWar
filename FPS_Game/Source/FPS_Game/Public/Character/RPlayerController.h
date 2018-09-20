// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FPS_GAME_API ARPlayerController : public APlayerController
{
	GENERATED_BODY()


	ARPlayerController(const class FObjectInitializer& ObjectInitializer);
	
public:
	void OnScreenMessage(FName string);
	void OnScreenMessage(FString string);
	void OnScreenMessageAmmo(int32 ammo);
	void OnScreenMessageSwitch(int32 val);
};
