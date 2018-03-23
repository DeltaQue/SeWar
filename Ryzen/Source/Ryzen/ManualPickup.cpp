// Fill out your copyright notice in the Description page of Project Settings.

#include "ManualPickup.h"
#include "RyzenController.h"

AManualPickup::AManualPickup()
{
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");
	RootComponent = Cast<USceneComponent>(PickupMesh);

	ItemID = FName("No ID");

	Super::Name = "Item";
	Super::Action = "pickup";
}

void AManualPickup::Interact_Implementation(APlayerController* Controller)
{
	Super::Interact_Implementation(Controller);

	ARyzenController* RController = Cast<ARyzenController>(Controller);
	if (RController->AddItemToInventoryByID(ItemID))
		Destroy();
}



