// Fill out your copyright notice in the Description page of Project Settings.

#include "RyzenController.h"
#include "RyzenStateBase.h"
#include "RyzenCharacter.h"



ARyzenController::ARyzenController()
{
	InventorySlotLimit = 50;
	InventoryWeightLimit = 500;
}

int32 ARyzenController::GetInventoryWeight()
{
	int32 Weight = 0;
	for (auto& Item : Inventory)
	{
		Weight += Item.Weight;
	}

	return Weight;
}

bool ARyzenController::AddItemToInventoryByID(FName ID)
{
	ARyzenStateBase* GameState = Cast<ARyzenStateBase>(GetWorld()->GetGameState());
	UDataTable* ItemTable = GameState->GetItemDB();
	FInventoryItem* ItemToAdd = ItemTable->FindRow<FInventoryItem>(ID, "");

	if (ItemToAdd)
	{
		//인벤토리 슬롯 50개보다 인텐토리 아이템 수가 적고, 인벤토리 Limit무게보다 아이템 무게를 더 했을때 인벤토리 무게가 Limit보다 적어야 아이템 습득 가능 
		if (Inventory.Num() < InventorySlotLimit && GetInventoryWeight() + ItemToAdd->Weight <= InventoryWeightLimit)
		{
			Inventory.Add(*ItemToAdd);
			ReloadInventory();
			return true;
		}
	}
	return false;
}

void ARyzenController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//F키를 누르면 Interact() 호출
	InputComponent->BindAction("Interact", IE_Pressed, this, &ARyzenController::Interact);
}

void ARyzenController::Interact()
{
	//Ryzen Character에서 Collection Sphere가 체크한 액터가 유효하면 Interactable_Implement함수를 호출함.
	if (CurrentInteractable)
	{
		CurrentInteractable->Interact(this);
	}
}


