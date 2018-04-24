// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "InventoryItem.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FInventoryItem : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Weight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* Thumbnail;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Description;

	bool operator==(const FInventoryItem& OtherItem) const
	{
		if (ItemID == OtherItem.ItemID)
			return true;
		return false;
	}

public:
	FInventoryItem();

	

	FName GetItemID() const;
	FText GetName() const;
	int32 GetWeight() const;
	int32 GetValue() const;
	FText GetDescription() const;
};