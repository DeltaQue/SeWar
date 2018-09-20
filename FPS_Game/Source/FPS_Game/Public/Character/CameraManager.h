// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "CameraManager.generated.h"

/**
 * 
 */
UCLASS()
class FPS_GAME_API ACameraManager : public APlayerCameraManager
{
	GENERATED_BODY()

	ACameraManager(const FObjectInitializer& ObjectInitializer);
	
	virtual void UpdateCamera(float DeltaTime) override;

	virtual void BeginPlay() override;
private:

	float NormalFOV;
	float TargetingFOV;
};
