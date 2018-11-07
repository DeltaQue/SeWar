// Fill out your copyright notice in the Description page of Project Settings.

#include "DamageItem.h"
#include "FPS_Game.h"



ADamageItem::ADamageItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ImproveDamage = 10;
}

bool ADamageItem::CanPickup(class APlayerCharacter* PickupPawn) const
{
	return (PickupPawn && PickupPawn->GetWeapon());
}

void ADamageItem::PickupEvent(class APlayerCharacter* PickupPawn)
{
	if (PickupPawn && CanPickup(PickupPawn))
	{
		PickupPawn->GetWeapon()->WeaponConfig.HitDamage += ImproveDamage;
	}
}



