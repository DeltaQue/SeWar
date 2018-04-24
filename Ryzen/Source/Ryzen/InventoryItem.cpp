// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryItem.h"


FInventoryItem::FInventoryItem()
{
	this->Name = FText::FromString("No Name");
	this->Weight = 1;
	this->Value = 1;
	this->Description = FText::FromString("No Description");
}

FName FInventoryItem::GetItemID() const { return ItemID; }

FText FInventoryItem::GetName() const { return Name; }

int32 FInventoryItem::GetValue() const { return Value; }

int32 FInventoryItem::GetWeight() const { return Weight; }

FText FInventoryItem::GetDescription() const { return Description; }