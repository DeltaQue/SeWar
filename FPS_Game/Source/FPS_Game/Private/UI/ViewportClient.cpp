// Fill out your copyright notice in the Description page of Project Settings.

#include "ViewportClient.h"
#include "FPS_Game.h"


void UViewportClient::PostRender(UCanvas* Canvas) 
{
	Super::PostRender(Canvas);

	// Fade if requested, you could use the same DrawScreenFade method from any canvas such as the HUD
	if (bFading)
	{
		DrawScreenFade(Canvas);
	}
}

void UViewportClient::ClearFade() 
{

	bFading = false;
}

void UViewportClient::Fade(const float Duration, const bool bToBlack) 
{

	const UWorld* World = GetWorld();
	if (World)
	{
		bFading = true;
		this->bToBlack = bToBlack;
		FadeDuration = Duration;
		FadeStartTime = World->GetTimeSeconds();
	}
}

void UViewportClient::DrawScreenFade(UCanvas* Canvas) 
{

	if (bFading)
	{
		const UWorld* World = GetWorld();
		if (World)
		{
			const float Time = World->GetTimeSeconds();
			const float Alpha = FMath::Clamp((Time - FadeStartTime) / FadeDuration, 0.f, 1.f);

			if (Alpha == 1.f && !bToBlack)
			{
				bFading = false;
			}
			else
			{
				FColor OldColor = Canvas->DrawColor;
				FLinearColor FadeColor = FLinearColor::Black;
				FadeColor.A = bToBlack ? Alpha : 1 - Alpha;
				Canvas->DrawColor = FadeColor.ToFColor(true); 
				Canvas->DrawTile(Canvas->DefaultTexture, 0, 0, Canvas->ClipX, Canvas->ClipY, 0, 0, Canvas->DefaultTexture->GetSizeX(), Canvas->DefaultTexture->GetSizeY());
				Canvas->DrawColor = OldColor;
			}
		}
	}
}

