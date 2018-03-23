// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/GameStateBase.h"
#include "RyzenStateBase.generated.h"

/**
 * 
 */
UCLASS()
class RYZEN_API ARyzenStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	ARyzenStateBase();

	UDataTable* GetItemDB() const;

protected:
	UPROPERTY(EditDefaultsOnly)
		class UDataTable* ItemDB;
	
};
