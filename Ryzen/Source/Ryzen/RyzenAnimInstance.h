// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Animation/AnimInstance.h"
#include "RyzenCharacter.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FVector Speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FRotator Rotate;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool bEnableJump;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool bCrouching;

	/*Holds the current speed of our character*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float MovementSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		APawn *Pawn;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		ARyzenCharacter *Ryzen;

	/*Updates the above properties*/
	UFUNCTION(BlueprintCallable, Category = "UpdateAnimationProperties")
		void UpdateAnimationProperties();
	
private:
	bool CanJump();

	float CalculateDirection();
};
