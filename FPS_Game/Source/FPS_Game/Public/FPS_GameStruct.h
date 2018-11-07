// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS_GameStruct.generated.h"

#pragma once

/**
 * 
 */
#define FPS_Game_SURFACE_Default	SurfaceType_Default
#define FPS_Game_SURFACE_Concrete	SurfaceType1
#define FPS_Game_SURFACE_Dirt		SurfaceType2
#define FPS_Game_SURFACE_Water		SurfaceType3
#define FPS_Game_SURFACE_Metal		SurfaceType4
#define FPS_Game_SURFACE_Wood		SurfaceType5
#define FPS_Game_SURFACE_Grass		SurfaceType6
#define FPS_Game_SURFACE_Glass		SurfaceType7
#define FPS_Game_SURFACE_Flesh		SurfaceType8



USTRUCT()
struct FDecalData
{
	GENERATED_USTRUCT_BODY()

	/** material */
	UPROPERTY(EditDefaultsOnly, Category = Decal)
		UMaterial* DecalMaterial;

	/** quad size (width & height) */
	UPROPERTY(EditDefaultsOnly, Category = Decal)
		float DecalSize;

	/** lifespan */
	UPROPERTY(EditDefaultsOnly, Category = Decal)
		float LifeSpan;

	/** defaults */
	FDecalData()
		: DecalSize(256.f)
		, LifeSpan(10.f)
	{
	}
};


UENUM()
enum class EZombieType : uint8
{
	RunAway,
	Rage,
	Patrol
};

UENUM()
enum class EBossType : uint8
{
	Patrol,
	RunAway
};

UENUM()
enum class ENPCType : uint8
{
	Idle,
	RunAway
};

