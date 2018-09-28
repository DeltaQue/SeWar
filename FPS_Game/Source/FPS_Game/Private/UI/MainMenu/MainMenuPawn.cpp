// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenuPawn.h"
#include "FPS_Game.h"

// Sets default values
AMainMenuPawn::AMainMenuPawn()
{

}

// Called when the game starts or when spawned
void AMainMenuPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMainMenuPawn::StartGame()
{
	const UWorld* World = GetWorld(); 
	if (World) 
	{
		UViewportClient* GameViewportClient = Cast<UViewportClient>(World->GetGameViewport());
		if (GameViewportClient)
		{
			GameViewportClient->Fade(5.f, 0);

		}
	}

}

void AMainMenuPawn::ExitGame()
{

}