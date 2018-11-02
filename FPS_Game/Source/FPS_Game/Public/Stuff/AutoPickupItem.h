// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AutoPickupItem.generated.h"

class UParticleSystem;
class UParticleSystemComponent;
class USoundCue;


UCLASS(ABSTRACT)
class FPS_GAME_API AAutoPickupItem : public AActor
{
	GENERATED_UCLASS_BODY()
	
public:	
	virtual void NotifyActorBeginOverlap(class AActor* Other) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	/** FX component */
	UPROPERTY(VisibleDefaultsOnly, Category = Effects)
		UParticleSystemComponent* PickupPSC;

	/** FX of active pickup */
	UPROPERTY(EditDefaultsOnly, Category = Effects)
		UParticleSystem* ActiveFX;

	/** FX of pickup on respawn timer */
	UPROPERTY(EditDefaultsOnly, Category = Effects)
		UParticleSystem* RespawningFX;

	/** sound played when player picks it up */
	UPROPERTY(EditDefaultsOnly, Category = Effects)
		USoundCue* PickupSound;

	/** sound played on respawn */
	UPROPERTY(EditDefaultsOnly, Category = Effects)
		USoundCue* RespawnSound;

	/** how long it takes to respawn */
	UPROPERTY(EditDefaultsOnly, Category = Pickup)
		float RespawnTime;



	void PickupItem(class APlayerCharacter* PickupPawn);

	virtual bool CanPickup(class APlayerCharacter* PickupPawn) const;

	virtual void PickupEvent(class APlayerCharacter* PickupPawn);

	void RespawnEvent();

private:
	float RotateTime;
};
