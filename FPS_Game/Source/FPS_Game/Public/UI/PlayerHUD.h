// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class FPS_GAME_API APlayerHUD : public AHUD
{
	GENERATED_UCLASS_BODY()
	
public:
	virtual void DrawHUD() override;

protected:
	//0:left, 1:top, 2:right, 3: bottom, 4:center
	UPROPERTY()
		FCanvasIcon Crosshair[5];

	UPROPERTY()
		UTexture2D* CrosshairTexture;
	
private:
	void DrawCrosshair();
	void DrawHealth();

	float GetPlayerHealth();

	/* 해상도 배율 */
	float ScaleUI;

};
