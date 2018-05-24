// Fill out your copyright notice in the Description page of Project Settings.

#include "RDamageType.h"




URDamageType::URDamageType(const FObjectInitializer& objectInitializer)
	: Super(objectInitializer)
{
	HeadDmgModifier = 2.0f;
	LimbDmgModifier = 0.5f;
}


float URDamageType::GetHeadDamageModifier()
{
	return HeadDmgModifier;
}

float URDamageType::GetLimbDamageModifier()
{
	return LimbDmgModifier;
}