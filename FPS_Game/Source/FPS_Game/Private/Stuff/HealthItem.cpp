// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthItem.h"
#include "FPS_Game.h"



AHealthItem::AHealthItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ImproveHealth = 30;
}

bool AHealthItem::CanPickup(class APlayerCharacter* PickupPawn) const
{
	return (PickupPawn && (PickupPawn->GetHealth() < PickupPawn->GetMaxHealth()));
}

void AHealthItem::PickupEvent(class APlayerCharacter* PickupPawn)
{
	if (PickupPawn && CanPickup(PickupPawn))
	{
		PickupPawn->SetAddHealth(ImproveHealth);


	}
}