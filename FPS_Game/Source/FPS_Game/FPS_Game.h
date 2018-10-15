// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "BaseCharacter.h"
#include "PlayerCharacter.h"
#include "Weapons.h"
#include "RPlayerController.h"
#include "ViewportClient.h"
#include "FPS_GameGameModeBase.h"
#include "ImpactEffects.h"
#include "FPS_GameStruct.h"
#include "NPCCharacter.h"
#include "NPCController.h"
#include "ZombieCharacter.h"
#include "ZombieAIController.h"



#define COLLISION_WEAPON		ECC_GameTraceChannel1
#define COLLISION_PROJECTILE	ECC_GameTraceChannel2
#define COLLISION_PICKUP		ECC_GameTraceChannel3



#define SURFACE_DEFAULT				SurfaceType_Default
#define SURFACE_CONCRETE			SurfaceType1
#define SURFACE_DIRT				SurfaceType2
#define SURFACE_WATER				SurfaceType3
#define SURFACE_METAL				SurfaceType4
#define SURFACE_WOOD				SurfaceType5
#define SURFACE_GRASS				SurfaceType6
#define SURFACE_GLASS				SurfaceType7
#define SURFACE_FLESH				SurfaceType8
#define SURFACE_ZOMBIEBODY			SurfaceType9
#define SURFACE_ZOMBIEHEAD			SurfaceType10
#define SURFACE_ZOMBIELIMB			SurfaceType11