// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(ABSTRACT)
class FPS_GAME_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter(const class FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


protected:
	UPROPERTY(EditDefaultsOnly, Category = "PlayerState")
		float Health;

	bool IsAlive() const;

public:	
	float GetHealth() const;
	float GetMaxHealth() const;
	
	void DestroyTarget();

	void DamagedHealth(float value);
};
