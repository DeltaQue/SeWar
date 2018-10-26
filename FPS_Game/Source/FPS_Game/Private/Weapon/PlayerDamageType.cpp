// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerDamageType.h"


UPlayerDamageType::UPlayerDamageType(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

	HeadDmgModifier = 2.0f;
	LimbDmgModifier = 0.5f;
	BodyDmgModifier = 1.0f;
}


float UPlayerDamageType::GetHeadDamageModifier()
{
	return HeadDmgModifier;
}

float UPlayerDamageType::GetLimbDamageModifier()
{
	return LimbDmgModifier;
}

float UPlayerDamageType::GetBodyDamageModifier()
{
	return BodyDmgModifier;
}