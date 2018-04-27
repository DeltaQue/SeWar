// Fill out your copyright notice in the Description page of Project Settings.
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

/**
*
*/
UCLASS()
class RYZEN_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

public:
	APlayerHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};
