// Fill out your copyright notice in the Description page of Project Settings.

#include "FPS_GameGameModeBase.h"




void AFPS_GameGameModeBase::SetPlayerSpawnTransform(FTransform SpawnTransform)
{
	PlayerSpawnTransform = SpawnTransform;
}

FTransform AFPS_GameGameModeBase::GetPlayerSpawnTransform() const
{
	return PlayerSpawnTransform;
}