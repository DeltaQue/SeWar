// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RyzenHUD.generated.h"

/**
 * 
 */
UCLASS()
class RYZEN_API ARyzenHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	ARyzenHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;
	
};
