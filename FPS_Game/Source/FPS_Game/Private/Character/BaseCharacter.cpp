// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCharacter.h"
#include "FPS_Game.h"

// Sets default values
ABaseCharacter::ABaseCharacter(const class FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	Health = 100.f;
	MaxHealth = 100.f;

	bIsRagdoll = false;
	bIsDie = false;
	bHitReact = false;
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
	return MaxHealth;
}

void ABaseCharacter::SetHealth(float ImproveHealth)
{
	if (ImproveHealth > 0.f)
	{
		if (MaxHealth >= Health + ImproveHealth)
		{
			Health += ImproveHealth;
		}
		else if (MaxHealth < Health + ImproveHealth)
		{
			Health = MaxHealth;
		}
	}
		
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

	PlayHit(KillingDamage, DamageEvent, Killer->GetPawn(), DamageCauser, true);


	//Player -> Zombie Kill
	if (Killer->GetPawn()->ActorHasTag(FName(TEXT("Player"))))
	{
		APlayerCharacter* Player = Cast<APlayerCharacter>(Killer->GetPawn());
		ARPlayerController* PlayerController = Cast<ARPlayerController>(Player->GetController());

		FPointDamageEvent* PointDamageEvent;
		if (DamageEvent.IsOfType(FPointDamageEvent::ClassID))
		{
			PointDamageEvent = (FPointDamageEvent*)&DamageEvent;

			AZombieCharacter* Zombie = Cast<AZombieCharacter>(PointDamageEvent->HitInfo.Actor);
			if (Zombie && !Zombie->IsPendingKill() && KilledZombie != Zombie)
			{
				PlayerController->SetScoreKillpoint();
				KilledZombie = Zombie;
			}
		}

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
		SetActorEnableCollision(true);


		SetRagdollPhysics();

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
	}
	//Zombie -> Player Kill
	else if (Killer->GetPawn()->ActorHasTag(FName(TEXT("Zombie"))))
	{
		//Death UI
		FPointDamageEvent* PointDamageEvent;
		if (DamageEvent.IsOfType(FPointDamageEvent::ClassID))
		{
			PointDamageEvent = (FPointDamageEvent*)&DamageEvent;

			APlayerCharacter* Player = Cast<APlayerCharacter>(PointDamageEvent->HitInfo.Actor);
			ARPlayerController* PlayerController = Cast<ARPlayerController>(Player->GetController());

			if (PlayerController)
			{
				PlayerController->OpenDeathWidget();
			}
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
		AZombieCharacter* Zombie = Cast<AZombieCharacter>(PawnInstigator);
		AZombieAIController* AIController = Cast<AZombieAIController>(PawnInstigator->GetController());
		if (AIController)
		{
			Zombie->GetCharacterMovement()->MaxWalkSpeed = Zombie->GetCharacterMovement()->MaxWalkSpeed / 2;
			float DeathAnimTime = PlayAnimMontage(HitAnim);

			

			bHitReact = true;

			FTimerHandle HitReactTimer_Handle;
			FTimerDelegate HitReactDelegate = FTimerDelegate::CreateUObject(this, &ABaseCharacter::AI_StopBehaviorTree, PawnInstigator);
			GetWorldTimerManager().SetTimer(HitReactTimer_Handle, HitReactDelegate, DeathAnimTime, true);
		}
		else
		{
			float DeathAnimTime = PlayAnimMontage(HitAnim);
		}
		
	}
}

void ABaseCharacter::AI_StopBehaviorTree(class APawn* PawnInstigator)
{
	AZombieCharacter* Zombie = Cast<AZombieCharacter>(PawnInstigator);
	Zombie->GetCharacterMovement()->MaxWalkSpeed = Zombie->GetCharacterMovement()->MaxWalkSpeed * 2;

	bHitReact = false;
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
		// Immediately hide the pawn
		TurnOff();
		SetActorHiddenInGame(true);
		SetLifeSpan(1.0f);
	}
	else
	{
		SetLifeSpan(4.0f);		//LifeSpan(float x) x가 지나면 모든 개체가 사라짐, 액터는 사라지지 않는다.
	}
}

float ABaseCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent
	, class AController* EventInstigator, class AActor* DamageCauser)
{
	if (Health < 0)
	{
		return 0.0f;
	}

	/*AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());
	Damage = GameMode->DamageCalc(Damage, this, DamageEvent, EventInstigator, DamageCauser);*/

	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	if (ActualDamage > 0.f)
	{
		Health -= ActualDamage;

		//Floating Damage Event 
		OnScreenDamage(ActualDamage);

		if (DamageEvent.IsOfType(FPointDamageEvent::ClassID))
		{
			FPointDamageEvent PointDmg = *((FPointDamageEvent*)(&DamageEvent));

			OnBloodEffectEvent(PointDmg.HitInfo);

			if (EventInstigator->GetPawn()->ActorHasTag("Player") && PointDmg.HitInfo.Actor->ActorHasTag("Boss"))
			{
				AZombieCharacter* Zombie = Cast<AZombieCharacter>(PointDmg.HitInfo.Actor);
				AZombieAIController* ZombieController = Cast<AZombieAIController>(Zombie->GetController());
				
				if (Zombie && Zombie->IsAlive())
				{
					//Boss HP가 50% 이하로 떨어질 경우 주변 모든 좀비들의 타겟을 플레이어로 집중시킴(한번만)
					if (Zombie->GetHealth() <= Zombie->GetMaxHealth() / 2)
					{
						ZombieController->SetBlackboardZombieType(EZombieType::Rage);
					}
					//Boss HP가 20% 이하로 떨어질 경우 HP회복을 하기 위해 도망친다.
					else if (Zombie->GetHealth() <= Zombie->GetMaxHealth() / 4)
					{
						ZombieController->SetBlackboardZombieType(EZombieType::RunAway);
					}
				}
			}
		}


		if (Health <= 0)
		{
			//Death
			Die(ActualDamage, DamageEvent, EventInstigator, DamageCauser);
		}
		else
		{
			APawn* Pawn = EventInstigator ? EventInstigator->GetPawn() : nullptr;
			PlayHit(ActualDamage, DamageEvent, Pawn, DamageCauser, false);
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
	Health = 0.f;
	Die(Health, FDamageEvent(UDamageType::StaticClass()), Killer, NULL);
}

bool ABaseCharacter::GetIsDie() const
{
	return bIsDie;
}

bool ABaseCharacter::GetHitReact() const
{
	return bHitReact;
}