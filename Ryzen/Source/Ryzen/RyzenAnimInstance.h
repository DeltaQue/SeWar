// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Animation/AnimInstance.h"
#include "RyzenAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class RYZEN_API URyzenAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	URyzenAnimInstance();

protected:
	/*True means that we're currently in air - or falling*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool bIsFalling;

	/*Holds the current speed of our character*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float MovementSpeed;

	/*Updates the above properties*/
	UFUNCTION(BlueprintCallable, Category = "UpdateAnimationProperties")
		void UpdateAnimationProperties();
	
	
};
