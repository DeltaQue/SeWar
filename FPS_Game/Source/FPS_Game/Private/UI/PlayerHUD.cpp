﻿// Fill out your copyright notice in the Description page of Project Settings.


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


	/* Radar */
	DrawRadar();
	DrawPlayerInRadar();
	FindEnemy();
	DrawFIndEnemyInRadar();

	RadarActors.Empty();
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


/*		Radar		*/
FVector2D APlayerHUD::GetRadarCenterPosition()
{
	if (Canvas)
	{
		return FVector2D(Canvas->SizeX*RadarStartLocation.X, Canvas->SizeY*RadarStartLocation.Y);
	}
	else
	{
		return FVector2D(0, 0);
	}
}

FVector2D APlayerHUD::ConvertWorldLocationToLocal(AActor* ActorToPlace)
{
	APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (Player && ActorToPlace)
	{
		//받아온 액터의 World좌표를 기반으로 Local좌표로 변환
		FVector ActorsLocal3dVector = Player->GetTransform().InverseTransformPosition(ActorToPlace->GetActorLocation());

		//정확한 방향을 위해 y축 -90회전
		ActorsLocal3dVector = FRotator(0.f, -90.f, 0.f).RotateVector(ActorsLocal3dVector);

		//거리 비례로 변환
		ActorsLocal3dVector /= RadarDistanceScale;

		//레이더는 평면이기때문에 2D벡터로 변환
		return FVector2D(ActorsLocal3dVector);
	}

	return FVector2D(0, 0);
}

void APlayerHUD::DrawRadar()
{
	FVector2D RadarCenter = GetRadarCenterPosition();

	for (float i = 0; i < 360; i += DegreeStep)
	{
		float fixedX = FMath::Cos(i) * RadarRadius;
		float fixedY = FMath::Sin(i) * RadarRadius;

		DrawLine(RadarCenter.X, RadarCenter.Y, RadarCenter.X + fixedX, RadarCenter.Y + fixedY, FLinearColor::Gray, 1.f);
	}
}

void APlayerHUD::DrawPlayerInRadar()
{
	FVector2D RadarCenter = GetRadarCenterPosition();

	DrawRect(FLinearColor::Blue, RadarCenter.X, RadarCenter.Y, DrawPixelSize, DrawPixelSize);
}

void APlayerHUD::FindEnemy()
{
	APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());

	if (Player)
	{
		if (GameMode->GetSpawnZombie().Num() != 0)
		{
			for (auto It : GameMode->GetSpawnZombie())
			{
				AZombieCharacter* Zombie = Cast<AZombieCharacter>(It);

				if (Zombie)
				{
					if (Zombie->ActorHasTag("Boss") || Zombie->ActorHasTag("Zombie"))
						RadarActors.Add(Zombie);
				}
			}
		}
	}
}

void APlayerHUD::DrawFIndEnemyInRadar()
{
	FVector2D RadarCenter = GetRadarCenterPosition();

	if(RadarActors.Num() != 0)
	{
		for (auto It : RadarActors)
		{
			FVector2D convertedLocation = ConvertWorldLocationToLocal(It);

			FVector tempVector = FVector(convertedLocation.X, convertedLocation.Y, 0.f);


			tempVector = tempVector.GetClampedToMaxSize2D(RadarRadius - DrawPixelSize);

			convertedLocation.X = tempVector.X;
			convertedLocation.Y = tempVector.Y;

			AZombieCharacter* Zombie = Cast<AZombieCharacter>(It);
			AZombieAIController* ZombieController = Cast<AZombieAIController>(Zombie->GetController());

			if (Zombie && ZombieController)
			{
				if (ZombieController->GetTargetEnemy())
				{
					DrawRect(FLinearColor::Red, RadarCenter.X + convertedLocation.X, RadarCenter.Y + convertedLocation.Y, DrawPixelSize, DrawPixelSize);
				}
				else
				{
					DrawRect(FLinearColor::Green, RadarCenter.X + convertedLocation.X, RadarCenter.Y + convertedLocation.Y, DrawPixelSize, DrawPixelSize);
				}
			}

		}
	}
}
