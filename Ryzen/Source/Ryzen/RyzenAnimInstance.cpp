// Fill out your copyright notice in the Description page of Project Settings.

#include "RyzenAnimInstance.h"




URyzenAnimInstance::URyzenAnimInstance() {

}

void URyzenAnimInstance::UpdateAnimationProperties() {

	//Get the pawn which is affected by our anim instance
	Pawn = TryGetPawnOwner();
	
	if (Pawn)
	{
		//Update our falling property
		bIsFalling = Pawn->GetMovementComponent()->IsFalling();

		Speed = Pawn->GetMovementComponent()->Velocity;

		Rotate = Pawn->GetActorRotation();

		//Update our movement speed
		MovementSpeed = Pawn->GetVelocity().Size();
		
		//바라보는 방향과 움직이는 방향 사이의 각도를 반환

		//if (CanJump()) {

		//}
		
	}

}

bool URyzenAnimInstance::CanJump() {
	if (&ACharacter::CanJump) {
		bEnableJump = true;
	}
	else
		bEnableJump = false;

	return bEnableJump;
}

float URyzenAnimInstance::CalculateDirection() {
//	Pawn->GetActorForwardVector;


	return 0.0f;
}