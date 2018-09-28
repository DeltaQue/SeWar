// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "MainMenuPawn.generated.h"

UCLASS()
class FPS_GAME_API AMainMenuPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMainMenuPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UFUNCTION(BlueprintCallable)
		void StartGame();

	UFUNCTION(BlueprintCallable)
		void ExitGame();

};
