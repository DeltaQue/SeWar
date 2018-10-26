// Fill out your copyright notice in the Description page of Project Settings.

#include "LaserActor.h"
#include "FPS_Game.h"

// Sets default values
ALaserActor::ALaserActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(FName("Root"));

	/*BlockA = CreateDefaultSubobject<UStaticMeshComponent>(FName("BlockA"));
	BlockA->SetRelativeLocation(FVector(500.f, 0.f, 0.f));
	BlockB = CreateDefaultSubobject<UStaticMeshComponent>(FName("BlockB"));
	BlockB->SetRelativeLocation(FVector(-500.f, 0.f, 0.f));*/

	BlockA = CreateDefaultSubobject<UDestructibleComponent>(FName("BlockA"));
	BlockA->SetRelativeLocation(FVector(500.f, 0.f, 0.f));
	BlockB = CreateDefaultSubobject<UDestructibleComponent>(FName("BlockB"));
	BlockB->SetRelativeLocation(FVector(-500.f, 0.f, 0.f)); 

	LaserPSC = CreateDefaultSubobject<UParticleSystemComponent>(FName("LaserPSC"));
}

// Called when the game starts or when spawned
void ALaserActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALaserActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (BlockA)
		LaserPSC->SetBeamSourcePoint(0, BlockA->GetComponentLocation(), 0);
	else
		LaserPSC->Activate(false);

	if(BlockB)
		LaserPSC->SetBeamTargetPoint(0, BlockB->GetComponentLocation(), 0);
	else
		LaserPSC->Activate(false);
		
}

