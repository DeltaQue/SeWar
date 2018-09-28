// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameViewportClient.h"
#include "ViewportClient.generated.h"

/**
  Fade Out & In Àü¿ë Class
 */
UCLASS()
class FPS_GAME_API UViewportClient : public UGameViewportClient
{
	GENERATED_BODY()
	
	
public:
	/* The canvas to use for rendering. */
	virtual void PostRender(UCanvas* Canvas) override;
	/** Clear fading state */
	virtual void ClearFade();
	/** Used for Fade to and from black */
	virtual void Fade(const float Duration, const bool bToBlack);
	/** Does the actual screen fading */
	void DrawScreenFade(UCanvas* Canvas);

private:
	// Values used by our screen fading
	uint32 bFading : 1;
	uint32 bToBlack : 1; // Fading to black will be applied even if alpha is 1
	float FadeAlpha;
	float FadeStartTime;
	float FadeDuration;
	
};
