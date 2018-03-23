// Fill out your copyright notice in the Description page of Project Settings.

#include "RyzenStateBase.h"


ARyzenStateBase::ARyzenStateBase()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> BP_ItemDB(TEXT("DataTable'/Game/Data/ItemDB.ItemDB'"));
	ItemDB = BP_ItemDB.Object;
}

UDataTable* ARyzenStateBase::GetItemDB() const
{
	return ItemDB;
}

