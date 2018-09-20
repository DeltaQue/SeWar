// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCharacter.h"


// Sets default values
ABaseCharacter::ABaseCharacter(const class FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	Health = 100.f;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

float ABaseCharacter::GetHealth() const
{
	return Health;
}

float ABaseCharacter::GetMaxHealth() const
{
	return 100.f;
}

bool ABaseCharacter::IsAlive() const
{
	if (Health > 0.f)
		return true;
	else
		return false;
}

void ABaseCharacter::DestroyTarget()
{
	if (IsAlive())
		return;
	else
		this->Destroy();
}

void ABaseCharacter::DamagedHealth(float value)
{

}
