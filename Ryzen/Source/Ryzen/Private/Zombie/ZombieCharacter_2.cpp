// Fill out your copyright notice in the Description page of Project Settings.

#include "ZombieCharacter_2.h"
#include "ZombieAIController.h"
#include "RyzenBaseCharacter.h"

/* AI Include */
#include "Perception/PawnSensingComponent.h"


// Sets default values
AZombieCharacter_2::AZombieCharacter_2(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//시야에 적이 있는지 체크하는 컴포넌트
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->SetPeripheralVisionAngle(60.0f);
	PawnSensingComp->SightRadius = 2000;
	PawnSensingComp->HearingThreshold = 600;
	PawnSensingComp->LOSHearingThreshold = 1200;

	GetCapsuleComponent()->SetCapsuleHalfHeight(96.0f, false);
	GetCapsuleComponent()->SetCapsuleRadius(42.0f);

	AttackCollisionComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("AttackCollision"));
	AttackCollisionComp->SetRelativeLocation(FVector(45, 0, 25));
	AttackCollisionComp->SetCapsuleHalfHeight(60);
	AttackCollisionComp->SetCapsuleRadius(35, false);
	AttackCollisionComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	AttackCollisionComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	AttackCollisionComp->SetupAttachment(GetCapsuleComponent());


	GetMovementComponent()->NavAgentProps.AgentRadius = 42;
	GetMovementComponent()->NavAgentProps.AgentHeight = 192;

	//기본 체력 100
	Health = 100;

	//적을 타겟으로 감지하고 리셋하는데 걸리는 시간 2.5초
	SenseTimeOut = 2.5f;

	//현재 시간 저장용 변수
	LastSeenTime = 0.0f;
}


void AZombieCharacter_2::BeginPlay()
{
	Super::BeginPlay();

	if (PawnSensingComp)
	{
		PawnSensingComp->OnSeePawn.AddDynamic(this, &AZombieCharacter_2::OnSeePlayer);
	}
	if (AttackCollisionComp)
	{
		AttackCollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AZombieCharacter_2::OnAttackCollisionCompBeginOverlap);
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

	OnDeath();
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

void AZombieCharacter_2::SetZombieType(EZombieType NewType) 
{
	ZombieType = NewType;

	AZombieAIController* ZombieController = Cast<AZombieAIController>(GetController());
	if (ZombieController)
	{
		ZombieController->SetBlackboardZombieType(NewType);
	}
}


void AZombieCharacter_2::OnAttackCollisionCompBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	//AZombieCharacter_2* other = Cast<AZombieCharacter_2>(OtherComp);
	if (OtherActor && OtherActor != this && IsAlive()) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Overlap 1"));
		if (AttackAnimMontage != NULL) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Overlap 2"));
			AnimInstance = this->GetMesh()->GetAnimInstance();
			if (AnimInstance != NULL) {
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Overlap 3"));
				//PlayAnimMontage(AttackAnimMontage);
				AnimInstance->Montage_Play(AttackAnimMontage, 2.5f);
			}

		}
	}
}

bool AZombieCharacter_2::DamageHit(uint8 damage) {
	if (this->Health - damage > 0) {
		this->Health -= damage;
		if (this->IsAlive()) {
			return true;
		}

	}

	return false;
}

void AZombieCharacter_2::IsDeath() {
	if (!this->IsAlive())
		Destroy();
}