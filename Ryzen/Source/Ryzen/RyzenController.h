// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Interactable.h"
#include "InventoryItem.h"
#include "RyzenController.generated.h"

/**
 * 
 */
UCLASS()
class RYZEN_API ARyzenController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	ARyzenController();

	//블루프린트 내에서 호출할 함수, BlueprintImplementableEvent
	//인벤토리 위젯이 유효한지를 판단해야하는데 코드 내에서 실시간 위젯의 유효성을 판단하기 어려워 블루프린트로 뺌
	UFUNCTION(BlueprintImplementableEvent)
		void ReloadInventory();

	UFUNCTION(BlueprintCallable, Category = "Utils")
		int32 GetInventoryWeight();

	UFUNCTION(BlueprintCallable, Category = "Utils")
		bool AddItemToInventoryByID(FName ID);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class AInteractable* CurrentInteractable;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TArray<FInventoryItem> Inventory;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int32 Money;

	//슬롯 개수 한계
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 InventorySlotLimit;

	//슬롯 무게 한계
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 InventoryWeightLimit;

protected:
	void Interact();

	virtual void SetupInputComponent() override;
};
