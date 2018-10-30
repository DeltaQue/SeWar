// Fill out your copyright notice in the Description page of Project Settings.

#include "ImpactEffects.h"
#include "FPS_Game.h"

AImpactEffects::AImpactEffects(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bAutoDestroyWhenFinished = true;
}


void AImpactEffects::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UPhysicalMaterial* HitPhysMat = SurfaceHit.PhysMaterial.Get();
	EPhysicalSurface HitSurfaceType = UPhysicalMaterial::DetermineSurfaceType(HitPhysMat);

	// show particles
	UParticleSystem* ImpactFX = GetImpactFX(HitSurfaceType);
	if (ImpactFX)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, ImpactFX, GetActorLocation(), GetActorRotation());
	}

	// play sound
	USoundCue* ImpactSound = GetImpactSound(HitSurfaceType);
	if (ImpactSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation());
	}

	if (DefaultDecal.DecalMaterial)
	{
		FRotator RandomDecalRotation = SurfaceHit.ImpactNormal.Rotation();
		RandomDecalRotation.Roll = FMath::FRandRange(-180.0f, 180.0f);

		UGameplayStatics::SpawnDecalAttached(DefaultDecal.DecalMaterial, FVector(1.0f, DefaultDecal.DecalSize, DefaultDecal.DecalSize),
			SurfaceHit.Component.Get(), SurfaceHit.BoneName,
			SurfaceHit.ImpactPoint, RandomDecalRotation, EAttachLocation::KeepWorldPosition,
			DefaultDecal.LifeSpan);
	}
}

UParticleSystem* AImpactEffects::GetImpactFX(TEnumAsByte<EPhysicalSurface> SurfaceType) const
{
	UParticleSystem* ImpactFX = NULL;

	switch (SurfaceType)
	{
	case SURFACE_CONCRETE:		ImpactFX = ConcreteFX; break;
	case SURFACE_DIRT:			ImpactFX = DirtFX; break;
	case SURFACE_METAL:			ImpactFX = MetalFX; break;
	case SURFACE_WATER:			ImpactFX = WaterFX; break;
	case SURFACE_WOOD:			ImpactFX = WoodFX; break;
	case SURFACE_GRASS:			ImpactFX = GrassFX; break;
	case SURFACE_GLASS:			ImpactFX = GlassFX; break;
	case SURFACE_FLESH:			ImpactFX = FleshFX; break;
	case SURFACE_ZOMBIEBODY:
	case SURFACE_ZOMBIEHEAD:
	case SURFACE_ZOMBIELIMB:	
		ImpactFX = FleshFX; break;

	default:						ImpactFX = DefaultFX; break;
	}

	return ImpactFX;
}

USoundCue* AImpactEffects::GetImpactSound(TEnumAsByte<EPhysicalSurface> SurfaceType) const
{
	USoundCue* ImpactSound = NULL;

	switch (SurfaceType)
	{
	case SURFACE_CONCRETE:	ImpactSound = ConcreteSound; break;
	case SURFACE_DIRT:		ImpactSound = DirtSound; break;
	case SURFACE_METAL:		ImpactSound = WaterSound; break;
	case SURFACE_WATER:		ImpactSound = MetalSound; break;
	case SURFACE_WOOD:		ImpactSound = WoodSound; break;
	case SURFACE_GRASS:		ImpactSound = GrassSound; break;
	case SURFACE_GLASS:		ImpactSound = GlassSound; break;
	case SURFACE_FLESH:		ImpactSound = FleshSound; break;
	default:						ImpactSound = DefaultSound; break;
	}

	return ImpactSound;
}
