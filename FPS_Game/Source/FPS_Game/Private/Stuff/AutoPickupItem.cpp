// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoPickupItem.h"
#include "FPS_Game.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AAutoPickupItem::AAutoPickupItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	UCapsuleComponent* CollisionComp = ObjectInitializer.CreateDefaultSubobject<UCapsuleComponent>(this, TEXT("CollisionComp"));
	CollisionComp->InitCapsuleSize(40.0f, 50.0f);
	CollisionComp->SetCollisionObjectType(COLLISION_PICKUP);
	CollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	RootComponent = CollisionComp;

	PickupPSC = ObjectInitializer.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("PickupFX"));
	PickupPSC->bAutoActivate = false;
	PickupPSC->bAutoDestroy = false;
	PickupPSC->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AAutoPickupItem::BeginPlay()
{
	Super::BeginPlay();
	
	
	RespawnEvent();
}

void AAutoPickupItem::NotifyActorBeginOverlap(class AActor* Other)
{
	Super::NotifyActorBeginOverlap(Other);

	PickupItem(Cast<APlayerCharacter>(Other));
}

void AAutoPickupItem::PickupItem(class APlayerCharacter* pawn)
{
	if (pawn && pawn->IsAlive() && !IsPendingKill())
	{
		if (CanPickup(pawn))
		{
			//child class func call
			PickupEvent(pawn);


			if (RespawningFX)
			{
				PickupPSC->SetTemplate(RespawningFX);
				PickupPSC->ActivateSystem();
			}
			else
			{
				PickupPSC->DeactivateSystem();
			}

			if (PickupSound)
			{
				UGameplayStatics::SpawnSoundAttached(PickupSound, pawn->GetRootComponent());
			}
		}
	}
}

void AAutoPickupItem::PickupEvent(class APlayerCharacter* PickupPawn)
{

}

bool AAutoPickupItem::CanPickup(class APlayerCharacter* PickupPawn) const
{
	return (PickupPawn && PickupPawn->IsAlive() && !IsPendingKill());
}

void AAutoPickupItem::RespawnEvent()
{
	if (ActiveFX)
	{
		PickupPSC->SetTemplate(ActiveFX);
		PickupPSC->ActivateSystem();
	}
	else
	{
		PickupPSC->DeactivateSystem();
	}

	//CreationTime은 액터가 생성된 시간
	const bool bJustSpawned = CreationTime <= (GetWorld()->GetTimeSeconds() + 5.0f);
	if (RespawnSound && !bJustSpawned)
	{
		UGameplayStatics::PlaySoundAtLocation(this, RespawnSound, GetActorLocation());
	}
}