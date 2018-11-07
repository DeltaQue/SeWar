// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Stuff/AutoPickupItem.h"
#include "DamageItem.generated.h"

/**
 * 
 */
UCLASS()
class FPS_GAME_API ADamageItem : public AAutoPickupItem
{
	GENERATED_UCLASS_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Effect")
		float ImproveDamage;

	virtual bool CanPickup(class APlayerCharacter* pawn) const override;

	virtual void PickupEvent(class APlayerCharacter* PickupPawn) override;
	
	
};
