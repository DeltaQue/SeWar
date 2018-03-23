// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoPickup.h"
#include "RyzenController.h"

AAutoPickup::AAutoPickup()
{
	//AutoPick up아이템 초기화
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");
	RootComponent = Cast<USceneComponent>(PickupMesh);

	ItemID = FName("No ID");
}

void AAutoPickup::Collect_Implementation(APlayerController* Controller)
{
	ARyzenController* IController = Cast<ARyzenController>(Controller);
	if (IController->AddItemToInventoryByID(ItemID))
		Destroy();
}

FName AAutoPickup::GetItemID()
{
	return ItemID;
}