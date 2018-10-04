// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCharacter.h"
#include "FPS_Game.h"

// Sets default values
ABaseCharacter::ABaseCharacter(const class FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	Health = 100.f;

	bIsRagdoll = false;
	bIsDie = false;
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
		
		bIsDie = true;
		//Score 부분 추가

		if (DeathSound)
		{
			UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation());
		}

		//StopAllAimMontages();

		if (GetMesh())
		{
			static FName CollisionProfileName(TEXT("Ragdoll"));
			GetMesh()->SetCollisionProfileName(CollisionProfileName);
		}

		float DeathAnimTime = PlayAnimMontage(DeathAnim);

		if (DeathAnimTime > 0.f)
		{
			// Trigger ragdoll a little before the animation early so the character doesn't
			// blend back to its normal position.
			const float TriggerRagdollTime = DeathAnimTime - 0.7f;

			// Enable blend physics so the bones are properly blending against the montage.
			GetMesh()->bBlendPhysics = true;

			// Use a local timer handle as we don't need to store it for later but we don't need to look for something to clear
			FTimerHandle TimerHandle;
			GetWorldTimerManager().SetTimer(TimerHandle, this, &ABaseCharacter::SetRagdollPhysics, FMath::Max(0.1f, TriggerRagdollTime), false);
		}
		else
		{
			SetRagdollPhysics();
		}

		// disable collisions on capsule
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Ignore);
	}

	bIsDie = false;

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

void ABaseCharacter::SetRagdollPhysics()
{

	bool bIsRagdoll = false;

	if (IsPendingKill())
	{
		bIsRagdoll = false;
	}
	else if (!GetMesh() || !GetMesh()->GetPhysicsAsset())
	{
		bIsRagdoll = false;
	}
	else
	{
		// initialize physics/etc
		GetMesh()->SetSimulatePhysics(true);
		GetMesh()->WakeAllRigidBodies();
		GetMesh()->bBlendPhysics = true;

		bIsRagdoll = true;
	}

	GetCharacterMovement()->StopMovementImmediately();
	GetCharacterMovement()->DisableMovement();
	GetCharacterMovement()->SetComponentTickEnabled(false);

	if (!bIsRagdoll)
	{
		// hide and set short lifespan
		TurnOff();
		SetActorHiddenInGame(true);
		SetLifeSpan(1.0f);
	}
	else
	{
		SetLifeSpan(10.0f);		//LifeSpan(float x) x가 지나면 모든 개체가 사라짐, 액터는 사라지지 않는다.
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
			Die(ActualDamage, DamageEvent, EventInstigator, DamageCauser);
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
	AController* Killer = NULL;
	if (this != NULL)
	{
		Killer = this->Controller;
		LastHitBy = NULL;
	}

	Die(Health, FDamageEvent(UDamageType::StaticClass()), Killer, NULL);
}

bool ABaseCharacter::GetIsDie() const
{
	return bIsDie;
}