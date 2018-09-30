// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCharacter.h"
#include "FPS_Game.h"

// Sets default values
ABaseCharacter::ABaseCharacter(const class FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	Health = 100.f;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

float ABaseCharacter::GetHealth() const
{
	return Health;
}

float ABaseCharacter::GetMaxHealth() const
{
	return 100.f;
}

bool ABaseCharacter::IsAlive() const
{
	if (Health > 0.f)
		return true;
	else
		return false;
}

void ABaseCharacter::DestroyTarget()
{
	if (IsAlive())
		return;
	else
		this->Destroy();
}

void ABaseCharacter::DamagedHealth(float value)
{

}


bool ABaseCharacter::CanDie(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer, AActor* DamageCauser) const
{
	//이미 삭제중인지 판단
	if (IsPendingKill())
	{
		return false;
	}
	else
	{
		return true;
	}
}


bool ABaseCharacter::Die(float KillingDamage, struct FDamageEvent const& DamageEvent
	, class AController* Killer, class AActor* DamageCauser)
{
	if (!CanDie(KillingDamage, DamageEvent, Killer, DamageCauser))
	{
		return false;
	}

	Health = 0.f;

	if (Health <= 0)
	{
		UDamageType const* DamageType = DamageEvent.DamageTypeClass ? DamageEvent.DamageTypeClass->GetDefaultObject<UDamageType>() : GetDefault<UDamageType>();
		
		//Score 부분 추가

		if (DeathSound)
		{
			UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation());
		}

		//StopAllAimMontages();
	}

	return true;
}


void ABaseCharacter::ReSpawnPlayer()
{
	AFPS_GameGameModeBase* GameMod = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());

	if (GameMod)
	{
		this->SetActorTransform(GameMod->GetPlayerSpawnTransform());
		
	}
}

float ABaseCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent
	, class AController* EventInstigator, class AActor* DamageCauser)
{
	if (Health < 0)
	{
		return 0.0f;
	}

	AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());
	Damage = GameMode->DamageCalc(Damage, this, DamageEvent, EventInstigator, DamageCauser);

	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	if (ActualDamage > 0.f)
	{
		Health -= ActualDamage;
		if (Health <= 0)
		{
			//Death
		}
		else
		{

		}
	}

	return ActualDamage;
}

void ABaseCharacter::FellOutOfWorld(const class UDamageType& dmgType)
{
	
}

void ABaseCharacter::Suicide()
{

}
