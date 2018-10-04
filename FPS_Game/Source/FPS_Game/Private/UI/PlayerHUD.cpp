// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"
#include "FPS_Game.h"


#define LOCTEXT_NAMESPACE "FPS_Game.HUD"

APlayerHUD::APlayerHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UTexture2D> MainTextureObj(TEXT("/Game/UI/HUD/MainTexture"));
	MainTexture = MainTextureObj.Object;

	// Center offset
	//0:left, 1:top, 2:right, 3: bottom, 4:center
	Crosshair[0] = UCanvas::MakeIcon(MainTexture, 43, 402, 25, 9);
	Crosshair[1] = UCanvas::MakeIcon(MainTexture, 74, 371, 9, 25);
	Crosshair[2] = UCanvas::MakeIcon(MainTexture, 88, 402, 25, 9);
	Crosshair[3] = UCanvas::MakeIcon(MainTexture, 74, 415, 9, 25);
	Crosshair[4] = UCanvas::MakeIcon(MainTexture, 75, 403, 7, 7); 


	DeathMessage = UCanvas::MakeIcon(MainTexture, 502, 177, 342, 187);


	static ConstructorHelpers::FObjectFinder<UFont> FontObj(TEXT("/Game/UI/HUD/Roboto51"));
	MessageFont = FontObj.Object;



	FontColor1 = FColor(110, 124, 131, 255);
	FontColor2 = FColor(175, 202, 213, 255);
}

void APlayerHUD::DrawHUD()
{
	Super::DrawHUD();

	if (Canvas == nullptr)
	{
		return;
	}

	// FHD 1080
	ScaleUI = Canvas->ClipY / 1080.0f;

	ARPlayerController* Controller = Cast<ARPlayerController>(PlayerOwner);
	APlayerCharacter* Player = Cast<APlayerCharacter>(GetOwningPawn());

	if (!Controller && !Player)
	{
		if (!Player->IsAlive() && Player->GetIsDie())
		{
			FString Text = LOCTEXT("WaitingForRespawn", "WAITING FOR RESPAWN").ToString();
			FCanvasTextItem TextItem(FVector2D::ZeroVector, FText::GetEmpty(), MessageFont, FontColor1);
			TextItem.EnableShadow(FLinearColor::Black);
			TextItem.Text = FText::FromString(Text);
			TextItem.Scale = FVector2D(ScaleUI, ScaleUI);
			//TextItem.FontRenderInfo = ShadowedFont;
			TextItem.SetColor(FontColor2);

			InfoItems.Add(TextItem);
			//AddMatchInfoString(TextItem);
		}
	}
	//Crosshair
	DrawCrosshair();

	ShowTextItems((Canvas->ClipY / 4.0)* ScaleUI, 1.f);
}

void APlayerHUD::DrawCrosshair()
{
	//PlayerOwner HUD제공
	ARPlayerController* OwnerController = Cast<ARPlayerController>(PlayerOwner);
	APlayerCharacter* MyPawn = Cast<APlayerCharacter>(OwnerController->GetPawn());

	if (OwnerController && MyPawn)
	{
		if (MyPawn->GetWeapon() && !MyPawn->IsSprint())
		{
			AWeapons* MyWeapon = Cast<AWeapons>(MyPawn->GetWeapon());

			//Crosshair 간격, Idle & Run
			float AimOffset = 0;
			float CurrentSpeed = MyPawn->GetVelocity().Size();

			if (CurrentSpeed > 0.f)
				AimOffset = 300 * 0.15f;
			else
				AimOffset = 300 * 0.1f;

			float CrossSpread = 2 + AimOffset;


			FCanvasIcon* CurrentCrosshair[5];
			for (int i = 0; i < 5; i++)
			{
				CurrentCrosshair[i] = &Crosshair[i];
			}


			float CenterX = Canvas->ClipX / 2;
			float CenterY = Canvas->ClipY / 2;
			Canvas->SetDrawColor(255, 255, 255, 192);


			if (MyPawn->IsTargeting())
			{
				//0:left, 1:top, 2:right, 3: bottom, 4:center
				Canvas->SetDrawColor(255, 0, 0, 192);
				Canvas->DrawIcon(*CurrentCrosshair[4],
					CenterX - (*CurrentCrosshair[4]).UL*ScaleUI / 2.0f,
					CenterY - (*CurrentCrosshair[4]).VL*ScaleUI / 2.0f, ScaleUI);
			}
			else
			{
				//0:left, 1:top, 2:right, 3: bottom, 4:center
				Canvas->DrawIcon(*CurrentCrosshair[4],
					CenterX - (*CurrentCrosshair[4]).UL*ScaleUI / 2.0f,
					CenterY - (*CurrentCrosshair[4]).VL*ScaleUI / 2.0f, ScaleUI);

				Canvas->DrawIcon(*CurrentCrosshair[0],
					CenterX - 1 - (*CurrentCrosshair[0]).UL * ScaleUI - CrossSpread * ScaleUI,
					CenterY - (*CurrentCrosshair[0]).VL*ScaleUI / 2.0f, ScaleUI);

				Canvas->DrawIcon(*CurrentCrosshair[2],
					CenterX + CrossSpread * ScaleUI,
					CenterY - (*CurrentCrosshair[2]).VL * ScaleUI / 2.0f, ScaleUI);

				Canvas->DrawIcon(*CurrentCrosshair[1],
					CenterX - (*CurrentCrosshair[1]).UL * ScaleUI / 2.0f,
					CenterY - 1 - (*CurrentCrosshair[1]).VL * ScaleUI - CrossSpread * ScaleUI, ScaleUI);
				
				Canvas->DrawIcon(*CurrentCrosshair[3],
					CenterX - (*CurrentCrosshair[3]).UL * ScaleUI / 2.0f,
					CenterY + CrossSpread * ScaleUI, ScaleUI);
			}
		}

	}

}


void APlayerHUD::DrawHealth()
{

}

float APlayerHUD::GetPlayerHealth()
{
	APlayerCharacter* MyPawn = Cast<APlayerCharacter>(PlayerOwner->GetPawn());

	return MyPawn->GetHealth();
}

float APlayerHUD::ShowTextItems(float YOffset, float TextScale)
{
	float Y = YOffset;
	float CanvasCentre = Canvas->ClipX / 2.0f;

	for (int32 iItem = 0; iItem < InfoItems.Num(); iItem++)
	{
		float X = 0.0f;
		float SizeX, SizeY;
		Canvas->StrLen(InfoItems[iItem].Font, InfoItems[iItem].Text.ToString(), SizeX, SizeY);
		X = CanvasCentre - (SizeX * InfoItems[iItem].Scale.X) / 2.0f;
		Canvas->DrawItem(InfoItems[iItem], X, Y);
		Y += SizeY * InfoItems[iItem].Scale.Y;
	}
	return Y;
}
