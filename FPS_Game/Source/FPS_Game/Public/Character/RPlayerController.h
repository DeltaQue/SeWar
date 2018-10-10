// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RPlayerController.generated.h"

/**
 * 
 */
class ACameraDirector;


UCLASS()
class FPS_GAME_API ARPlayerController : public APlayerController
{
	GENERATED_BODY()


	ARPlayerController(const class FObjectInitializer& ObjectInitializer);
private:
	UPROPERTY()
		int32 Killpoint;

	void CloseAllWidget();

	//0 : Quest NPC
	//1 : Heal NPC
	//2 : Ammo NPC
	int32 TalkNPCType;
protected:
	virtual void SetupInputComponent() override;

	


	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	//	TSubclassOf<class UUserWidget> wGuideWidget;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	//	TSubclassOf<class UUserWidget> wTutorialWidget;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	//	TSubclassOf<class UUserWidget> wStage1_QuestWidget;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	//	TSubclassOf<class UUserWidget> wStage2_QuestWidget;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	//	TSubclassOf<class UUserWidget> wHealWidget;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	//	TSubclassOf<class UUserWidget> wAmmoWidget;


	//wWidgetArray
	//0 : GuideWidget
	//1 : TutorialWidget
	//2 : Stage1_QuestWidget
	//3 : Stage2_QuestWidget
	//4 : HealWidget
	//5 : AmmoWidget
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TArray<TSubclassOf<class UUserWidget>> wWidgetArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> wCurrentQuestHUD;

	UUserWidget* GuideWidget;
	UUserWidget* TutorialWidget;
	UUserWidget* Stage1_QuestWidget;
	UUserWidget* Stage2_QuestWidget;
	UUserWidget* HealWidget;
	UUserWidget* AmmoWidget;

	UUserWidget* CurrentQuestHUD;

public:
	void OnScreenMessage(FName string);
	void OnScreenMessage(FString string);
	void OnScreenMessageAmmo(int32 ammo);
	void OnScreenMessageSwitch(int32 val);

	void OpenGuideWidget();
	void CloseGuideWidget();

	void OpenQuestWidget(int32 WidgetNum);
	void CloseQuestWidget(int32 WidgetNum);

	void OpenCurrentQuestHUD();
	void CloseCurrentQuestHUD();

	UFUNCTION(BlueprintCallable, Category = "Bind")
		int32 BindKilledpoint();
	UFUNCTION(BlueprintCallable, Category = "Bind")
		void NextScript();


	void SetScoreKillpoint();
	int32 GetScoreKillpoint();

	UPROPERTY()
		bool bTurnViewTarget;

	void SetTalkNPCType(int32 NPCType);
};
