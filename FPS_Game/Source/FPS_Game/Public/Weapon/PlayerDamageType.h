// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DamageType.h"
#include "PlayerDamageType.generated.h"

/**
 * 
 */
UCLASS()
class FPS_GAME_API UPlayerDamageType : public UDamageType
{
	GENERATED_BODY()

	UPlayerDamageType(const FObjectInitializer& ObjectInitializer);
	
	
	/* Can player die from this damage type (eg. players don't die from hunger) */
	UPROPERTY(EditDefaultsOnly)
		bool bCanDieFrom;

	/* 
	헤드샷 데미지 2배
	바디샷 데미지 1배
	기타 부위 데미지 0.5배
	*/
	UPROPERTY(EditDefaultsOnly)
		float HeadDmgModifier;

	UPROPERTY(EditDefaultsOnly)
		float LimbDmgModifier;

	UPROPERTY(EditDefaultsOnly)
		float BodyDmgModifier;

public:

	bool GetCanDieFrom();

	float GetHeadDamageModifier();

	float GetLimbDamageModifier();

	float GetBodyDamageModifier();
};
