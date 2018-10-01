// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class UAudioComponent;
class USoundCue;

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

private:
	void ReSpawnPlayer();

protected:
	

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent
		, class AController* EventInstigator, class AActor* DamageCauser) override;

	virtual bool CanDie(float KillingDamage, FDamageEvent const& DamageEvent
		, AController* Killer, AActor* DamageCauser) const;

	virtual bool Die(float KillingDamage, struct FDamageEvent const& DamageEvent
		, class AController* Killer, class AActor* DamageCauser);

	virtual void FellOutOfWorld(const class UDamageType& dmgType) override;

	virtual void Suicide();


	UPROPERTY(EditDefaultsOnly, Category = "PlayerState")
		float Health;
	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundCue* DeathSound;
	UPROPERTY(EditDefaultsOnly, Category = Animation)
		UAnimMontage* DeathAnim;

public:	
	bool IsAlive() const;
	float GetHealth() const;
	float GetMaxHealth() const;
	
	void DestroyTarget();

	void DamagedHealth(float value);
};
