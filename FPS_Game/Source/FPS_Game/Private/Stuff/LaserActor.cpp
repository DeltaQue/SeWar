// Fill out your copyright notice in the Description page of Project Settings.

#include "LaserActor.h"
#include "FPS_Game.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

// Sets default values
ALaserActor::ALaserActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*CollisionComp = ObjectInitializer.CreateDefaultSubobject<UCapsuleComponent>(this, TEXT("CollisionComp"));
	CollisionComp->InitCapsuleSize(40.0f, 50.0f);
	CollisionComp->SetCollisionObjectType(COLLISION_PICKUP);
	CollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	CollisionComp->SetSimulatePhysics(true);
	RootComponent = CollisionComp;*/


	BlockA = CreateDefaultSubobject<UDestructibleComponent>(FName("BlockA"));
	/*static ConstructorHelpers::FObjectFinder<UDestructibleComponent> DestructibleMesh(TEXT("DestructibleMesh'/Game/StaticMesh_DM.StaticMesh_DM'"));
	BlockA = DestructibleMesh.Object;*/
	BlockA->SetSimulatePhysics(true);
	RootComponent = BlockA;
	//BlockA->SetupAttachment(Root);


	/*BlockB = CreateDefaultSubobject<UDestructibleComponent>(FName("BlockB"));
	BlockB->SetRelativeLocation(FVector(-500.f, 0.f, 0.f)); */

	//LaserPSC = CreateDefaultSubobject<UParticleSystemComponent>(FName("LaserPSC"));
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

	/*if (BlockA)
		LaserPSC->SetBeamSourcePoint(0, BlockA->GetComponentLocation(), 0);
	else
		LaserPSC->Activate(false);

	if(BlockB)
		LaserPSC->SetBeamTargetPoint(0, BlockB->GetComponentLocation(), 0);
	else
		LaserPSC->Activate(false);*/
		
}


UDestructibleComponent* ALaserActor::GetDestructibleComponent() const
{
	return BlockA;
}