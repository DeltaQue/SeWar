// Fill out your copyright notice in the Description page of Project Settings.

#include "FPS_GameGameModeBase.h"
#include "FPS_Game.h"



void AFPS_GameGameModeBase::SetPlayerSpawnTransform(FTransform SpawnTransform)
{
	PlayerSpawnTransform = SpawnTransform;
}

FTransform AFPS_GameGameModeBase::GetPlayerSpawnTransform() const
{
	return PlayerSpawnTransform;
}

float AFPS_GameGameModeBase::DamageCalc(float Damage, AActor * DamagedActor, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser) const
{
	float ActualDamage = Damage;

	ABaseCharacter* DamagedPawn = Cast<ABaseCharacter>(DamagedActor);
	if (DamagedPawn && EventInstigator)
	{

	}
	return ActualDamage;
}
