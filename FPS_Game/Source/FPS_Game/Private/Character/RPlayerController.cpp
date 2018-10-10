// Fill out your copyright notice in the Description page of Project Settings.

#include "RPlayerController.h"
#include "FPS_Game.h"
#include "CameraManager.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"

//wWidgetArray
//0 : GuideWidget
//1 : TutorialWidget
//2 : Stage1_QuestWidget
//3 : Stage2_QuestWidget
//4 : HealWidget
//5 : AmmoWidget

ARPlayerController::ARPlayerController(const class FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	PlayerCameraManagerClass = ACameraManager::StaticClass();

	OpenGuideWidget();
	
	
	bTurnViewTarget = false;

	TalkNPCType = -1;
}

void ARPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("Guide", IE_Pressed, this, &ARPlayerController::OpenGuideWidget);
	InputComponent->BindAction("Guide", IE_Released, this, &ARPlayerController::CloseGuideWidget);

	InputComponent->BindAction("Anykey", IE_Released, this, &ARPlayerController::NextScript);

	InputComponent->BindAction("ESC", IE_Released, this, &ARPlayerController::CloseAllWidget);

}


void ARPlayerController::OnScreenMessage(FName string)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, string.ToString());
}

void ARPlayerController::OnScreenMessage(FString string)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, *string);
}

void ARPlayerController::OnScreenMessageAmmo(int32 ammo)
{
	//UE_LOG(LogClass, Log, TEXT("Remaining Ammo : %d", ammo));

	FString str = FString::Printf(TEXT("Remaining Ammo : %d"), ammo);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, str);
}

void ARPlayerController::OnScreenMessageSwitch(int32 val)
{
	switch (val)
	{
	case 0:
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Attach Success"));
		break;

	case 1:
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Attach Fail"));
		break;

	default:
		break;
	}
}

void ARPlayerController::OpenGuideWidget()
{
	if (wWidgetArray.Num() != 0)
	{
		if (GuideWidget)
		{
			CloseGuideWidget();
		}
		else
		{
			if (wWidgetArray[0]) // Check if the Asset is assigned in the blueprint.
			{
				// Create the widget and store it.
				GuideWidget = CreateWidget<UUserWidget>(this, wWidgetArray[0]);

				// now you can use the widget directly since you have a referance for it.
				// Extra check to  make sure the pointer holds the widget.
				if (GuideWidget)
				{
					//let add it to the view port
					GuideWidget->AddToViewport();
				}

			}
		}
	}
}

void ARPlayerController::CloseGuideWidget()
{
	if (GuideWidget)
	{
		GuideWidget->RemoveFromParent();
		GuideWidget = nullptr;
	}
}

void ARPlayerController::OpenQuestWidget(int32 WidgetNum)
{
	if (wWidgetArray.Num() != 0)
	{
		//Widget Num
		//1 : Tutorial WIdget
		//2 : Stage1 Quest Widget
		//3 : Stage2 Quest Widget
		//4 : Heal Widget
		//5 : Ammo Widget
		switch (WidgetNum)
		{
		case 0:
		case 1:

			if (wWidgetArray[1]) // Check if the Asset is assigned in the blueprint.
			{
				// Create the widget and store it.
				TutorialWidget = CreateWidget<UUserWidget>(this, wWidgetArray[1]);

				// now you can use the widget directly since you have a referance for it.
				// Extra check to  make sure the pointer holds the widget.
				if (TutorialWidget)
				{
					//let add it to the view port
					TutorialWidget->AddToViewport();
				}

			}
			break;

		case 2:
			if (wWidgetArray[2])
			{
				Stage1_QuestWidget = CreateWidget<UUserWidget>(this, wWidgetArray[2]);

				if (Stage1_QuestWidget)
				{
					Stage1_QuestWidget->AddToViewport();
				}
			}
			break;

		case 3:
			if (wWidgetArray[3])
			{
				Stage2_QuestWidget = CreateWidget<UUserWidget>(this, wWidgetArray[3]);

				if (Stage2_QuestWidget)
				{
					Stage2_QuestWidget->AddToViewport();
				}
			}
			break;

		case 4:
			if (wWidgetArray[4])
			{
				HealWidget = CreateWidget<UUserWidget>(this, wWidgetArray[4]);

				if (HealWidget)
				{
					HealWidget->AddToViewport();
				}
			}
			break;

		case 5:
			if (wWidgetArray[5])
			{
				AmmoWidget = CreateWidget<UUserWidget>(this, wWidgetArray[5]);

				if (AmmoWidget)
				{
					AmmoWidget->AddToViewport();
				}
			}
			break;
		default:
			break;
		}
	}
}

void ARPlayerController::CloseQuestWidget(int32 WidgetNum)
{
	//Widget Num
	//1 : Tutorial WIdget
	//2 : Stage1 Quest Widget
	//3 : Stage2 Quest Widget
	//4 : Heal Widget
	//5 : Ammo Widget

	switch (WidgetNum)
	{
	case 0:
	case 1:
		if (TutorialWidget)
		{
			TutorialWidget->RemoveFromParent();
			TutorialWidget = nullptr;

			AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());

			//다음 퀘스트를 넘어가야할때
			if (GameMode->GetQuestScriptMaxSize(GameMode->GetQuestNum()) - 1 == GameMode->GetQuestScriptNum())
			{
				//다음 퀘스트로 넘어가는 조건 => GameMode에서 SetCompleteQuest()에서 진행
				//GameMode->NextQuest();
			}
			//스크립트가 완전히 종료되지 않았는데 퀘스트 위젯을 꺼야할때
			else
			{
				GameMode->ClearQuest();
			}
		}
		break;

	case 2:
		if (Stage1_QuestWidget)
		{
			Stage1_QuestWidget->RemoveFromParent();
			Stage1_QuestWidget = nullptr;

			AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());
			GameMode->ClearQuest();
		}
		break;

	case 3:
		if (Stage2_QuestWidget)
		{
			Stage2_QuestWidget->RemoveFromParent();
			Stage2_QuestWidget = nullptr;

			AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());
			GameMode->ClearQuest();
		}
		break;

	case 4:
		if (HealWidget)
		{
			HealWidget->RemoveFromParent();
			HealWidget = nullptr;

			AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());
			GameMode->ClearQuest();
		}
		break;

	case 5:
		if (AmmoWidget)
		{
			AmmoWidget->RemoveFromParent();
			AmmoWidget = nullptr;

			AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());
			GameMode->ClearQuest();
		}
		break;

	default:
		break;
	}
	
}

void ARPlayerController::OpenCurrentQuestHUD()
{
	if (wCurrentQuestHUD) // Check if the Asset is assigned in the blueprint.
	{
		// Create the widget and store it.
		CurrentQuestHUD = CreateWidget<UUserWidget>(this, wCurrentQuestHUD);

		// now you can use the widget directly since you have a referance for it.
		// Extra check to  make sure the pointer holds the widget.
		if (CurrentQuestHUD)
		{
			//let add it to the view port
			CurrentQuestHUD->AddToViewport();
		}

	}
}

void ARPlayerController::CloseCurrentQuestHUD()
{
	if (CurrentQuestHUD)
	{
		CurrentQuestHUD->RemoveFromParent();
		CurrentQuestHUD = nullptr;
	}
}

void ARPlayerController::NextScript()
{
	AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());
	APlayerCharacter* Player = Cast<APlayerCharacter>(GetPawn());

	switch (TalkNPCType)
	{
	//case 0 : Quest NPC
	case 0:
		//현재 스크립트가 끝인경우
		switch (GameMode->GetQuestNum())
		{
			//Tutorial Quest
		case 0:
			if (GameMode->GetQuestScriptNum() == GameMode->GetQuestScriptMaxSize(0) - 1)
			{
				CloseQuestWidget(0);

				//FRotator TargetRot = UKismetMathLibrary::FindLookAtRotation(Player->GetActorLocation(), TargetLoc);
				//Player->SetActorRotation(FMath::RInterpTo(Player->GetActorRotation(), TargetRot, GetWorld()->GetDeltaSeconds(), 5.0f));
				//Player->SetActorRotation(FMath::RInterpTo(Player->GetActorRotation(), Dir.Rotation(), GetWorld()->GetDeltaSeconds(), 5.0f));
				//Player->SetActorRelativeRotation(FMath::RInterpTo(Player->GetActorRotation(), TargetRot, GetWorld()->GetDeltaSeconds(), 5.0f));

				/*FVector MyLoc = MyCharacter->GetActorLocation();
				FVector TargetLoc = FVector(100.f, 100.f, 0.f);
				FVector Dir = (TargetLoc - MyLoc);
				Dir.Normalize();
				MyCharacter->SetActorRotation(FMath::Lerp(MyCharacter->GetActorRotation(), Dir.Rotation(), 0.05f));*/
			}
			else if (GameMode->GetQuestScriptNum() == GameMode->GetQuestScriptMaxSize(0) - 2)
			{
				bTurnViewTarget = true;

				GameMode->SpawnZombie();
			}
			break;

			//Stage1 - Quest 
		case 1:
			if (GameMode->GetQuestScriptNum() == GameMode->GetQuestScriptMaxSize(2) - 1)
			{
				CloseQuestWidget(2);

				//Quest UI SetActivate!
				OpenCurrentQuestHUD();
			}
			break;

			//Stage2 - Quest
		case 2:
			break;

		default:
			break;
		}

		//다음 스크립트가 있는경우
		/*if (QuestWidget)
		{
		GameMode->NextQuestScript();
		}*/
		if (GameMode->GetQuestNum() < 3)
		{
			GameMode->NextQuestScript();
		}
		
		break;

	//case 1 : Heal NPC
	case 1:
		if (GameMode->GetNPCScriptNum() == GameMode->GetNPCScriptMaxSize(1) - 1)
		{
			CloseQuestWidget(4);

			//HP 회복 함수
		}
		break;

	//case 2 : Ammo NPC
	case 2:
		if (GameMode->GetNPCScriptNum() == GameMode->GetNPCScriptMaxSize(2) - 1)
		{
			CloseQuestWidget(5);

			//Ammo 충전 함수
		}

		break;

	default:
		break;
	}
	
	
	
}

int32 ARPlayerController::BindKilledpoint()
{
	return Killpoint;
}

int32 ARPlayerController::GetScoreKillpoint()
{
	return Killpoint;
}

void ARPlayerController::SetScoreKillpoint()
{
	Killpoint++;

	if (Killpoint == 1)
	{
		AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());

		//Tutorial Quest Clear
		GameMode->SetCompleteQuest(0);
	}
}

void ARPlayerController::SetTalkNPCType(int32 NPCType)
{
	TalkNPCType = NPCType;
}


void ARPlayerController::CloseAllWidget()
{
	if (GuideWidget)
	{
		GuideWidget->RemoveFromParent();
		GuideWidget = nullptr;
	}
	if (TutorialWidget)
	{
		TutorialWidget->RemoveFromParent();
		TutorialWidget = nullptr;
	}
	if (Stage1_QuestWidget)
	{
		Stage1_QuestWidget->RemoveFromParent();
		Stage1_QuestWidget = nullptr;
	}
	if (Stage2_QuestWidget)
	{
		Stage2_QuestWidget->RemoveFromParent();
		Stage2_QuestWidget = nullptr;
	}
	if (HealWidget)
	{
		HealWidget->RemoveFromParent();
		HealWidget = nullptr;
	}
	if (AmmoWidget)
	{
		AmmoWidget->RemoveFromParent();
		AmmoWidget = nullptr;
	}

	AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());
	GameMode->ClearNPCScript();
	GameMode->ClearQuest();
}