// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainMenuController.generated.h"

/**
 * 
 */
UCLASS()
class FPS_GAME_API AMainMenuController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable, Category = "Util")
		void NextLevel(FName MapName);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget") 
		TSubclassOf<class UUserWidget> wMainMenu;
	
	UUserWidget * MyMainMenu;

	
};
