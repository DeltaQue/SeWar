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

	virtual void Tick(float DeltaTime) override;



	//wWidgetArray
	//1 : QusetScriptlWidget
	//2 : HealWidget
	//3 : AmmoWidget
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TArray<TSubclassOf<class UUserWidget>> wWidgetArray;

	//wGuideWidgetArray
	//0 : Movement GuideWidget
	//1 : Weapon GuideWidget
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TArray<TSubclassOf<class UUserWidget>> wGuideWidgetArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> wStatusHUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> wDeathWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> wStageClearWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> wCreditWidget;

	UUserWidget* MovementGuideWidget;
	UUserWidget* WeaponGuideWidget;
	UUserWidget* QuestScriptWidget;
	UUserWidget* HealWidget;
	UUserWidget* AmmoWidget;

	UUserWidget* StatusHUD;

	UUserWidget* DeathWidget;

	UUserWidget* StageClearWidget;
	UUserWidget* CreditWidget;


public:
	void OnScreenMessage(FName string);
	void OnScreenMessage(FString string);
	void OnScreenMessageAmmo(int32 ammo);
	void OnScreenMessageSwitch(int32 val);

	void OpenAllGuideWidget();
	void OpenGuideWidget(int GuideWidgetNum);
	void CloseGuideWidget(int GuideWidgetNum);

	void OpenWidget(int32 WidgetNum);
	void CloseWidget(int32 WidgetNum);
	
	void OpenDeathWidget();

	int OpenStageClearWidget(int QuestNum);
	void OpenCreditWidget();


	UFUNCTION(BlueprintCallable, Category = "Bind")
		int32 BindKilledpoint();
	UFUNCTION(BlueprintCallable, Category = "Bind")
		void NextScript();

	void SetGamePause();
	void SetGameUnPause();

	void SetScoreKillpoint(int Num);
	void AddScoreKillpoint();
	int32 GetScoreKillpoint() const;

	UPROPERTY()
		bool bTurnViewTarget;

	void SetTalkNPCType(int32 NPCType);


	//Status WIdget을 얻기 위한 함수
	UFUNCTION(BlueprintCallable, Category = "Widget")
		UUserWidget* GetStatusHUD() const;
	//퀘스트 스코어
	UFUNCTION(BlueprintCallable, Category = "Widget")
		int32 GetQuestScore() const;


	void OpenStatusHUD();
	void CloseStatusHUD();

};
