// Fill out your copyright notice in the Description page of Project Settings.

#include "ZombieCharacter_2.h"
#include "ZombieAIController.h"
#include "PlayerCharacter.h"
#include "RyzenBaseCharacter.h"

/* AI Include */
#include "Perception/PawnSensingComponent.h"


// Sets default values
AZombieCharacter_2::AZombieCharacter_2(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	/* Note: We assign the Controller class in the Blueprint extension of this class
	Because the zombie AIController is a blueprint in content and it's better to avoid content references in code.  */
	/*AIControllerClass = ASZombieAIController::StaticClass();*/

	/* Our sensing component to detect players by visibility and noise checks. */
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->SetPeripheralVisionAngle(60.0f);
	PawnSensingComp->SightRadius = 2000;
	PawnSensingComp->HearingThreshold = 600;
	PawnSensingComp->LOSHearingThreshold = 1200;

	/* Ignore this channel or it will absorb the trace impacts instead of the skeletal mesh */
	GetCapsuleComponent()->SetCapsuleHalfHeight(96.0f, false);
	GetCapsuleComponent()->SetCapsuleRadius(42.0f);

	/* These values are matched up to the CapsuleComponent above and are used to find navigation paths */
	GetMovementComponent()->NavAgentProps.AgentRadius = 42;
	GetMovementComponent()->NavAgentProps.AgentHeight = 192;

	Health = 100;

	SenseTimeOut = 2.5f;

	LastSeenTime = 0.0f;
}


void AZombieCharacter_2::BeginPlay()
{
	Super::BeginPlay();

	if (PawnSensingComp)
	{
		PawnSensingComp->OnSeePawn.AddDynamic(this, &AZombieCharacter_2::OnSeePlayer);
	}
}


void AZombieCharacter_2::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	/* 2.5초 동안 플레이어를 쫒다가 플레이어를 쫒지 못하면 타겟 초기화 */
	if (bSensedTarget && (GetWorld()->TimeSeconds - LastSeenTime) > SenseTimeOut)
	{
		AZombieAIController* AIController = Cast<AZombieAIController>(GetController());
		if (AIController)
		{
			bSensedTarget = false;
			/* 타겟 리셋 */
			AIController->SetTargetEnemy(nullptr);
		}
	}
}



void AZombieCharacter_2::OnSeePlayer(APawn* Pawn)
{
	if (!IsAlive())
	{
		return;
	}

	if (!bSensedTarget)
	{

	}

	//타겟을 발견 한 뒤 월드 시간을 받음
	LastSeenTime = GetWorld()->GetTimeSeconds();
	bSensedTarget = true;

	AZombieAIController* AIController = Cast<AZombieAIController>(GetController());
	ARyzenBaseCharacter* SensedPawn = Cast<ARyzenBaseCharacter>(Pawn);
	if (AIController && SensedPawn->IsAlive())
	{
		AIController->SetTargetEnemy(SensedPawn);
	}
}

