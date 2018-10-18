// Fill out your copyright notice in the Description page of Project Settings.

#include "RifleBulletItem.h"
#include "FPS_Game.h"



ARifleBulletItem::ARifleBulletItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ImproveBullet = 50.f;
}

bool ARifleBulletItem::CanPickup(class APlayerCharacter* PickupPawn) const
{
	return true;
}

void ARifleBulletItem::PickupEvent(class APlayerCharacter* PickupPawn)
{
	if (PickupPawn && CanPickup(PickupPawn))
	{
		if (PickupPawn->GetWeapon()->GetLoadedAmmo() == 0 && PickupPawn->GetWeapon()->GetRemainingAmmo() == 0)
		{
			PickupPawn->GetWeapon()->SetRemainingAmmo(ImproveBullet);

			PickupPawn->GetWeapon()->StartReload();
		}
		else
		{
			PickupPawn->GetWeapon()->SetRemainingAmmo(ImproveBullet);
		}

	}
}



