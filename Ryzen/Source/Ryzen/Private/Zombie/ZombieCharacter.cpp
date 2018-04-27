// Fill out your copyright notice in the Description page of Project Settings.

#include "ZombieCharacter.h"
#include "RyzenBaseCharacter.h"
//#include "Waypoint.h"
#include "ZombieAIController.h"
/* AI Include */
#include "Perception/PawnSensingComponent.h"


// Sets default values
AZombieCharacter::AZombieCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AZombieCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZombieCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AZombieCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AZombieCharacter::OnSeePlayer(APawn* pawn) {
	
	bSensedTarget = true;

	AZombieAIController* ZombieAIController = Cast<AZombieAIController>(GetController());
	ARyzenBaseCharacter* Player = Cast<ARyzenBaseCharacter>(pawn);

	if (ZombieAIController && Player) {
		ZombieAIController->SetTargetEnemy(Player);
	}
}



