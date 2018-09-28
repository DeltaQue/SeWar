// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenuController.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


void AMainMenuController::BeginPlay()
{
	Super::BeginPlay();

	if (wMainMenu) 
	{
		MyMainMenu = CreateWidget <UUserWidget> (this, wMainMenu);

		if (MyMainMenu) {
			// 뷰 포트에 추가
			MyMainMenu-> AddToViewport (); 
		}

		bShowMouseCursor = true; 
	}

}



void AMainMenuController::NextLevel(FName MapName)
{
	UGameplayStatics::OpenLevel(this, MapName);
}