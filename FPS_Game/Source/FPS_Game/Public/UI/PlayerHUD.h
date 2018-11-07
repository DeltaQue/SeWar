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
		UTexture2D* MainTexture;
	
	UPROPERTY()
		FCanvasIcon DeathMessage;
	UPROPERTY()
		UFont* MessageFont;


	FColor FontColor1;
	FColor FontColor2;
private:
	void DrawCrosshair();

	float ShowTextItems(float YOffset, float TextScale);

	/* 해상도 배율 */
	float ScaleUI;


	//HUD Text 출력변수
	TArray<FCanvasTextItem> InfoItems;



	//Radar System
protected:
	/*The distance scale of the radar actors*/
	UPROPERTY(EditAnywhere, Category = Radar)
		float RadarDistanceScale = 25.f;

	/*The start location of our radar*/
	UPROPERTY(EditAnywhere, Category = Radar)
		FVector2D RadarStartLocation = FVector2D(0.9f, 0.2f);

	/*The radius of our radar*/
	UPROPERTY(EditAnywhere, Category = Radar)
		float RadarRadius = 100.f;

	UPROPERTY(EditAnywhere, Category = Radar)
		float DegreeStep = 0.25f;

	/*Sphere height and radius for our raycast*/
	UPROPERTY(EditAnywhere, Category = Radar)
		float SphereHeight = 200.f;

	UPROPERTY(EditAnywhere, Category = Radar)
		float SphereRadius = 500.f;

	/*The pixel size of the drawable radar actors*/
	UPROPERTY(EditAnywhere, Category = Radar)
		float DrawPixelSize = 5.f;

private:
	TArray<AActor*> RadarActors;
	FVector2D GetRadarCenterPosition();
	FVector2D ConvertWorldLocationToLocal(AActor* ActorToPlace);

	void DrawRadar();
	void DrawPlayerInRadar();
	void FindEnemy();
	void DrawFIndEnemyInRadar();
};
