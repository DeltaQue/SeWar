// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraManager.h"
#include "FPS_Game.h"
#include "PlayerCharacter.h"



ACameraManager::ACameraManager(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	NormalFOV = 90.0f;
	TargetingFOV = 60.0f;

	ViewPitchMin = -87.0f;
	ViewPitchMax = 87.0f;
	bAlwaysApplyModifiers = true;
}

void ACameraManager::UpdateCamera(float DeltaTime)
{

	//PCOwner -> Camera Owner(APlayerCharacter)
	APlayerCharacter* MyPawn = PCOwner ? Cast<APlayerCharacter>(PCOwner->GetPawn()) : nullptr;
	if (MyPawn)
	{
		const float TargetFOV = MyPawn->IsTargeting() ? TargetingFOV : NormalFOV;
		DefaultFOV = FMath::FInterpTo(DefaultFOV, TargetFOV, DeltaTime, 20.0f);
		//SetFOV(DefaultFOV);
	}

	Super::UpdateCamera(DeltaTime);

	if (MyPawn)
	{
		MyPawn->OnCameraUpdate(GetCameraLocation(), GetCameraRotation());
		MyPawn->CheckForWeaponInView(GetCameraLocation(), GetActorForwardVector(), GetCameraRotation());
	}
}

void ACameraManager::BeginPlay()
{
	Super::BeginPlay();
}
