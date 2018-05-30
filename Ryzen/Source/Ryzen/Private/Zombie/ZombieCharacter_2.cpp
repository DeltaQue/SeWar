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

	bSensedTarget = false;
	bHeardTarget = false;

	//적을 타겟으로 감지하고 리셋하는데 걸리는 시간 2.5초
	SightSenseTimeOut = 2.5f;
	HearingSenseTimeOut = 6.0f;

	//현재 시간 저장용 변수
	LastSeenTime = 0.0f;
	LastHeardTime = 0.0f;

	DefaultMaxWalkSpeed = 0.0f;

	AttackCooltime = 1.5f;
}


void AZombieCharacter_2::BeginPlay()
{
	Super::BeginPlay();

	if (PawnSensingComp)
	{
		PawnSensingComp->OnSeePawn.AddDynamic(this, &AZombieCharacter_2::OnSeePlayer);

		PawnSensingComp->OnHearNoise.AddDynamic(this, &AZombieCharacter_2::OnHearNoise);
	}
	if (AttackCollisionComp)
	{
		AttackCollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AZombieCharacter_2::OnAttackCollisionCompBeginOverlap);
	}

	DefaultMaxWalkSpeed = GetMovementComponent()->GetMaxSpeed();
}


void AZombieCharacter_2::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	/* 2.5초 동안 플레이어를 쫒다가 플레이어를 쫒지 못하면 타겟 초기화 */
	if (bSensedTarget && (GetWorld()->TimeSeconds - LastSeenTime) > SightSenseTimeOut
		&& (GetWorld()->TimeSeconds - LastHeardTime) > HearingSenseTimeOut)
	{
		AZombieAIController* AIController = Cast<AZombieAIController>(GetController());
		if (AIController)
		{
			bSensedTarget = false;
			/* 타겟 리셋 */
			AIController->SetTargetEnemy(nullptr);

			bHeardTarget = false;

			AIController->SetReconLocation(FVector(-1, -1, -1));

			Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = DefaultMaxWalkSpeed;
		}
	}

	IsDeath();
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
		//167.0f == Zombie Run
		Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = 167.0f;
	}
}

void AZombieCharacter_2::OnHearNoise(APawn* PawnInstigator, const FVector& Location, float Volume) {
	if (!IsAlive())
	{
		return;
	}

	if (!bSensedTarget)
	{
		//AudioLoop(true);
	}

	bSensedTarget = true;
	LastHeardTime = GetWorld()->GetTimeSeconds();

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Noise Check!"));

	AZombieAIController* AIController = Cast<AZombieAIController>(GetController());
	if (AIController)
	{
		AIController->SetTargetEnemy(PawnInstigator);
		AIController->SetReconLocation(Location);
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
	//Timer Stop
	TimerHandle_AttackTimer.Invalidate();

	ScratchAttack(OtherActor);

	AZombieAIController* Controller = Cast<AZombieAIController>(GetController());
	Controller->SetIsAttackCollisionOverlap(true);

	//Timer함수. AttackTimer가 Invalidate 되지 않았다면, AttackCooltime 마다 ReTriggerAttack 함수를 실행함.
	GetWorldTimerManager().SetTimer(TimerHandle_AttackTimer, this, &AZombieCharacter_2::ReTriggerAttack, AttackCooltime, true);
	//TimerHandleFunc();
}

void AZombieCharacter_2::OnAttackCollisionCompEndOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AZombieAIController* Controller = Cast<AZombieAIController>(GetController());

	Controller->SetIsAttackCollisionOverlap(false);
}

bool AZombieCharacter_2::DamageHit(uint8 damage) 
{
	if (this->Health - damage > 0) {
		this->Health -= damage;
		if (this->IsAlive()) {
			return true;
		}

	}

	return false;
}

void AZombieCharacter_2::IsDeath() 
{
	if (!this->IsAlive())
		Destroy();
}

void AZombieCharacter_2::PlayAttackMotion()
{
	if (AttackAnimMontage)
	{
		AnimInstance->Montage_Play(AttackAnimMontage, 2.5f);
	}
	else
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Attack anim error"));
	
	if (AttackSound)
	{
		UGameplayStatics::SpawnSoundAttached(AttackSound, RootComponent, NAME_None, FVector::ZeroVector, EAttachLocation::SnapToTarget, true);
	}
	else
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Attack sound error"));
}


void AZombieCharacter_2::ScratchAttack(AActor* HitActor)
{
	if (LastAttackTime > GetWorld()->GetTimeSeconds() - AttackCooltime)
	{
		if (!TimerHandle_AttackTimer.IsValid()) 
		{

		}
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Attack CoolTime!"));
		return;
	}

	//AZombieCharacter_2* other = Cast<AZombieCharacter_2>(OtherComp);
	if (HitActor && HitActor != this && IsAlive()) {
		
		if (AttackAnimMontage != NULL) {
			AnimInstance = this->GetMesh()->GetAnimInstance();
			if (AnimInstance != NULL) {
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Begin Attack"));

				LastAttackTime = GetWorld()->GetTimeSeconds();

				FPointDamageEvent DmgEvent;
				DmgEvent.DamageTypeClass = ScratchDamageType;
				DmgEvent.Damage = AttackDamage;

				HitActor->TakeDamage(DmgEvent.Damage, DmgEvent, GetController(), this);

				PlayAttackMotion();
			}

		}
	}
}


void AZombieCharacter_2::ReTriggerAttack()
{
	TArray<AActor*> OverlapActor;
	//Attack Collision에 Timer가 ReTriggerAttack을 실행 할 때 마다, Overlap된 액터를 집어넣음
	AttackCollisionComp->GetOverlappingActors(OverlapActor, ARyzenBaseCharacter::StaticClass());
	for (int32 i = 0; i < OverlapActor.Num(); i++)
	{
		ARyzenBaseCharacter* OverlappingPawn = Cast<ARyzenBaseCharacter>(OverlapActor[i]);
		if (OverlappingPawn)
		{
			ScratchAttack(OverlappingPawn);
		}
		else
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("ReTrigger Attack fail"));
	}
	if (OverlapActor.Num() == 0)
	{
		TimerHandle_AttackTimer.Invalidate();
	}
}


void AZombieCharacter_2::TimerHandleFunc()
{
	//Timer함수. AttackTimer가 Invalidate 되지 않았다면, AttackCooltime 마다 ReTriggerAttack 함수를 실행함.
	GetWorldTimerManager().SetTimer(TimerHandle_AttackTimer, this, &AZombieCharacter_2::ReTriggerAttack, AttackCooltime, true);
}

UAnimInstance* AZombieCharacter_2::GetAttackAnimInstance() const { return AnimInstance; }

UAnimMontage* AZombieCharacter_2::GetAttackAnimMontage() const { return AttackAnimMontage; }