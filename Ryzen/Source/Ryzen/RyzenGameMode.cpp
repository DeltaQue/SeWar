// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "RyzenGameMode.h"
#include "RyzenCharacter.h"
#include "ZombieCharacter_2.h"
#include "StructClass.h"
#include "UObject/ConstructorHelpers.h"

ARyzenGameMode::ARyzenGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ARyzenGameMode::PreInitializeComponents()
{
	Super::PreInitializeComponents();

	/* Set timer to run every second */
	//GetWorldTimerManager().SetTimer(TimerHandle_DefaultTimer, this, &ARyzenGameMode::InitZombieType, GetWorldSettings()->GetEffectiveTimeDilation(), true);
}

void ARyzenGameMode::InitZombieType() {
	for (FConstPawnIterator It = GetWorld()->GetPawnIterator(); It; It++)
	{
		AZombieCharacter_2* Zombie = Cast<AZombieCharacter_2>(*It);
		if (Zombie)
		{
			Zombie->SetZombieType(EZombieType::Patrol);
		}
	}
}