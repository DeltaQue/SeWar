// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DestructibleComponent.h"
#include "GameFramework/Actor.h"
#include "LaserActor.generated.h"

class UParticleSystemComponent;

UCLASS()
class FPS_GAME_API ALaserActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaserActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	USceneComponent* Root;

	UPROPERTY(EditDefaultsOnly)
		UParticleSystemComponent* LaserPSC;

	
	UPROPERTY(EditDefaultsOnly)
		UDestructibleComponent* BlockA;

	UPROPERTY(EditDefaultsOnly)
		UDestructibleComponent* BlockB;

	//UPROPERTY(EditDefaultsOnly)
	//	UStaticMeshComponent* BlockA;

	//UPROPERTY(EditDefaultsOnly)
	//	UStaticMeshComponent* BlockB;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
