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
	//if (!CanDie(KillingDamage, DamageEvent, Killer, DamageCauser))
	//{
	//	return false;
	//}

	//Health = 0.f;

	//PlayHit(KillingDamage, DamageEvent, Killer->GetPawn(), DamageCauser, true);

	//if (Health <= 0)
	//{
	//	UDamageType const* DamageType = DamageEvent.DamageTypeClass ? DamageEvent.DamageTypeClass->GetDefaultObject<UDamageType>() : GetDefault<UDamageType>();
	//	
	//	APlayerCharacter* Player = Cast<APlayerCharacter>(Killer->GetCharacter());
	//	ARPlayerController* PlayerController = Cast<ARPlayerController>(Player->GetController());

	//	//Score 부분 추가
	//	PlayerController->SetScoreKillpoint();

	//	bIsDie = true;
	//	
	//	DetachFromControllerPendingDestroy();

	//	if (DeathSound)
	//	{
	//		UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation());
	//	}

	//	//StopAllAimMontages();

	//	if (GetMesh())
	//	{
	//		static FName CollisionProfileName(TEXT("Ragdoll"));
	//		GetMesh()->SetCollisionProfileName(CollisionProfileName);
	//	}

	//	SetActorEnableCollision(true);

	//	float DeathAnimTime = PlayAnimMontage(DeathAnim);

	//	if (DeathAnimTime > 0.f)
	//	{
	//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Zombie Death Anim Duration: %f"), DeathAnimTime));
	//		
	//		// Trigger ragdoll a little before the animation early so the character doesn't
	//		// blend back to its normal position.
	//		const float TriggerRagdollTime = DeathAnimTime - 0.7f;

	//		// Enable blend physics so the bones are properly blending against the montage.
	//		GetMesh()->bBlendPhysics = true;

	//		SetRagdollPhysics();

	//		// Use a local timer handle as we don't need to store it for later but we don't need to look for something to clear
	//		//FTimerHandle TimerHandle;
	//		//GetWorldTimerManager().SetTimer(TimerHandle, this, &ABaseCharacter::SetRagdollPhysics, FMath::Max(0.1f, TriggerRagdollTime), false);
	//	}
	//	else
	//	{
	//		SetRagdollPhysics();
	//	}

	//	// disable collisions on capsule
	//	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Ignore);

	//}

	///* Apply physics impulse on the bone of the enemy skeleton mesh we hit (ray-trace damage only) */
	//if (DamageEvent.IsOfType(FPointDamageEvent::ClassID))
	//{
	//	FPointDamageEvent PointDmg = *((FPointDamageEvent*)(&DamageEvent));
	//	{
	//		GetMesh()->AddImpulseAtLocation(PointDmg.ShotDirection * 5000, PointDmg.HitInfo.ImpactPoint, PointDmg.HitInfo.BoneName);
	//	}
	//}
	//if (DamageEvent.IsOfType(FRadialDamageEvent::ClassID))
	//{
	//	FRadialDamageEvent RadialDmg = *((FRadialDamageEvent const*)(&DamageEvent));
	//	{
	//		GetMesh()->AddRadialImpulse(RadialDmg.Origin, RadialDmg.Params.GetMaxRadius(), 100000, ERadialImpulseFalloff::RIF_Linear);
	//	}
	//}

	//bIsDie = false;

	//return true;


	if (!CanDie(KillingDamage, DamageEvent, Killer, DamageCauser))
	{
		return false;
	}

	Health = 0.f;

	PlayHit(KillingDamage, DamageEvent, Killer->GetPawn(), DamageCauser, true);


	DetachFromControllerPendingDestroy();

	/* Disable all collision on capsule */
	UCapsuleComponent* CapsuleComp = GetCapsuleComponent();
	CapsuleComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CapsuleComp->SetCollisionResponseToAllChannels(ECR_Ignore);

	
	USkeletalMeshComponent* Mesh = GetMesh();
	if (Mesh)
	{
		Mesh->SetCollisionProfileName(TEXT("Ragdoll"));
	}
	//SetActorEnableCollision(true);


	SetRagdollPhysics();

	/* Apply physics impulse on the bone of the enemy skeleton mesh we hit (ray-trace damage only) */
	if (DamageEvent.IsOfType(FPointDamageEvent::ClassID))
	{
		FPointDamageEvent PointDmg = *((FPointDamageEvent*)(&DamageEvent));
		{
			// TODO: Use DamageTypeClass->DamageImpulse
			Mesh->AddImpulseAtLocation(PointDmg.ShotDirection * 12000, PointDmg.HitInfo.ImpactPoint, PointDmg.HitInfo.BoneName);
		}
	}
	if (DamageEvent.IsOfType(FRadialDamageEvent::ClassID))
	{
		FRadialDamageEvent RadialDmg = *((FRadialDamageEvent const*)(&DamageEvent));
		{
			Mesh->AddRadialImpulse(RadialDmg.Origin, RadialDmg.Params.GetMaxRadius(), 100000 /*RadialDmg.DamageTypeClass->DamageImpulse*/, ERadialImpulseFalloff::RIF_Linear);
		}
	}

	return true;
}

void ABaseCharacter::PlayHit(float DamageTaken, struct FDamageEvent const& DamageEvent, APawn* PawnInstigator, AActor* DamageCauser, bool bKilled)
{
	if (bKilled && DeathSound)
	{
		UGameplayStatics::SpawnSoundAttached(DeathSound, RootComponent, NAME_None, FVector::ZeroVector, EAttachLocation::SnapToTarget, true);
	}
	else if (HitSound)
	{
		UGameplayStatics::SpawnSoundAttached(HitSound, RootComponent, NAME_None, FVector::ZeroVector, EAttachLocation::SnapToTarget, true);
	}

	if (bKilled && DeathAnim)
	{
		float DeathAnimTime = PlayAnimMontage(DeathAnim);
	}
	else if (HitAnim)
	{
		float DeathAnimTime = PlayAnimMontage(HitAnim);
	}
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

	bool bInRagdoll = false;
	USkeletalMeshComponent* Mesh = GetMesh();

	if (IsPendingKill())
	{
		bInRagdoll = false;
	}
	else if (!Mesh || !Mesh->GetPhysicsAsset())
	{
		bInRagdoll = false;
	}
	else
	{
		Mesh->SetAllBodiesSimulatePhysics(true);
		Mesh->SetSimulatePhysics(true);
		Mesh->WakeAllRigidBodies();
		Mesh->bBlendPhysics = true;

		PlayAnimMontage(DeathAnim);

		bInRagdoll = true;
	}

	UCharacterMovementComponent* CharacterComp = Cast<UCharacterMovementComponent>(GetMovementComponent());
	if (CharacterComp)
	{
		CharacterComp->StopMovementImmediately();
		CharacterComp->DisableMovement();
		CharacterComp->SetComponentTickEnabled(false);
	}

	if (!bInRagdoll)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("bInRagdoll is false")));

		// Immediately hide the pawn
		TurnOff();
		SetActorHiddenInGame(true);
		SetLifeSpan(1.0f);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("bInRagdoll is true")));
		//SetLifeSpan(10.0f);		//LifeSpan(float x) x가 지나면 모든 개체가 사라짐, 액터는 사라지지 않는다.
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
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Zombie Die In")));
			//Death
			//Die(ActualDamage, DamageEvent, EventInstigator, DamageCauser);
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Zombie Play Hit in")));
			SetRagdollPhysics();

			//APawn* Pawn = EventInstigator ? EventInstigator->GetPawn() : nullptr;
			//PlayHit(ActualDamage, DamageEvent, Pawn, DamageCauser, false);
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