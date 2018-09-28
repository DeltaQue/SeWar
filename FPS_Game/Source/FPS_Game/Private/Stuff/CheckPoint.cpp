// Fill out your copyright notice in the Description page of Project Settings.

#include "CheckPoint.h"
#include "FPS_Game.h"

ACheckPoint::ACheckPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereRadius = 100.0f;

	CheckPointCollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CheckPoint Collision"));
	CheckPointCollisionSphere->InitSphereRadius(SphereRadius);
	CheckPointCollisionSphere->SetCollisionProfileName("Trigger");
	RootComponent = CheckPointCollisionSphere;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Mesh"));
	MyMesh->SetupAttachment(RootComponent);

	CheckPointCollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ACheckPoint::OnOverlapBegin);
}


void ACheckPoint::BeginPlay()
{
	Super::BeginPlay();
	
}


void ACheckPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACheckPoint::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		AFPS_GameGameModeBase* GameMod = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());
		GameMod->SetPlayerSpawnTransform(this->GetActorTransform());
	}
}