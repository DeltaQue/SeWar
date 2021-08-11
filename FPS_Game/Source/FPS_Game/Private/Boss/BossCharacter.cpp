// Fill out your copyright notice in the Description page of Project Settings.

#include "BossCharacter.h"
#include "BossAIController.h"
#include "BaseCharacter.h"

/* AI Include */
#include "Perception/PawnSensingComponent.h"

ABossCharacter::ABossCharacter(const class FObjectInitializer& ObjectInitializer)
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

	bSensedTarget = false;
	bHeardTarget = false;
	bPlayedScream = false;

	//적을 타겟으로 감지하고 리셋하는데 걸리는 시간 2.5초
	SightSenseTimeOut = 2.5f;
	HearingSenseTimeOut = 6.0f;

	//현재 시간 저장용 변수
	LastSeenTime = 0.0f;
	LastHeardTime = 0.0f;

	DefaultMaxWalkSpeed = 0.0f;

	BossType = EBossType::Patrol;
}


void ABossCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (PawnSensingComp)
	{
		PawnSensingComp->OnSeePawn.AddDynamic(this, &ABossCharacter::OnSeePlayer);

		//PawnSensingComp->OnHearNoise.AddDynamic(this, &AZombieCharacter::OnHearNoise);
	}

	DefaultMaxWalkSpeed = GetMovementComponent()->GetMaxSpeed();
}


void ABossCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	/* 2.5초 동안 플레이어를 쫒다가 플레이어를 쫒지 못하면 타겟 초기화 */
	if (bSensedTarget && (GetWorld()->TimeSeconds - LastSeenTime) > SightSenseTimeOut
		&& (GetWorld()->TimeSeconds - LastHeardTime) > HearingSenseTimeOut)
	{
		ABossAIController* AIController = Cast<ABossAIController>(GetController());
		if (AIController)
		{
			bSensedTarget = false;
			bPlayedScream = false;
			bHeardTarget = false;

			/* 타겟 리셋 */
			AIController->SetTargetEnemy(nullptr);

			Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = DefaultMaxWalkSpeed;
		}
	}

}


void ABossCharacter::OnSeePlayer(APawn* Pawn)
{
	if (!IsAlive())
	{
		return;
	}

	if (!bSensedTarget)
	{
		//AudioLoopUpdate(true);
	}

	float Duration = 0.0f;

	if (ScreamAnimMontage && !bPlayedScream)
	{
		Duration = PlayAnimMontage(ScreamAnimMontage);
		bPlayedScream = true;

		if (Duration <= 0.f)
		{
			Duration = 0.5f;
		}

		FTimerHandle UniqueHandle;
		FTimerDelegate RespawnDelegate = FTimerDelegate::CreateUObject(this, &ABossCharacter::TargetChase, Pawn);
		GetWorldTimerManager().SetTimer(UniqueHandle, RespawnDelegate, Duration, false);
	}

	FTimerHandle UniqueHandle;
	FTimerDelegate RespawnDelegate = FTimerDelegate::CreateUObject(this, &ABossCharacter::TargetChase, Pawn);
	GetWorldTimerManager().SetTimer(UniqueHandle, RespawnDelegate, 1.f, false);
}

void ABossCharacter::TargetChase(APawn* Pawn)
{
	//타겟을 발견 한 뒤 월드 시간을 받음
	LastSeenTime = GetWorld()->GetTimeSeconds();
	bSensedTarget = true;

	ABossAIController* AIController = Cast<ABossAIController>(GetController());
	ABaseCharacter* SensedPawn = Cast<ABaseCharacter>(Pawn);

	if (AIController && SensedPawn->IsAlive())
	{
		AIController->SetTargetEnemy(SensedPawn);


		Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = DefaultMaxWalkSpeed * 2.f;
	}
}


float ABossCharacter::PlayAttackAnimMontage(int AttackType)
{
	float Duration = 0.f;

	switch (AttackType)
	{
	case 0:
		if (BiteAttackAnimMontage)
		{
			Duration = PlayAnimMontage(BiteAttackAnimMontage);
		}
		break;

	case 1:
		if (HookAttackAnimMontage)
		{
			Duration = PlayAnimMontage(HookAttackAnimMontage);
		}
		break;

	default:
		break;
	}
	
	return Duration;
}

float ABossCharacter::PlayAttackSound(int AttackType)
{
	float Duration = 0.f;

	if (AttackSound)
	{

	}

	return Duration;
}

void ABossCharacter::OnAttackCollisionCompBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->ActorHasTag("Player"))
	{
		APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor);

		//Timer Stop
		if (Player && this->Health > 0)
		{
			ABossAIController* Controller = Cast<ABossAIController>(GetController());

			Controller->SetAttackAble(true);
		}
	}
}

void ABossCharacter::OnAttackCollisionCompEndOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->ActorHasTag("Player"))
	{
		APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor);
		
		ABossAIController* Controller = Cast<ABossAIController>(GetController());

		Controller->SetAttackAble(false);
	}

}


















TSubclassOf<UDamageType> ABossCharacter::GetAttackDamageType() const
{
	if (AttackDamageType)
	{
		return AttackDamageType;
	}

	return nullptr;
}

float ABossCharacter::GetAttackDamage(int AttackType) const
{
	float AttackDamage = 0.0f;

	switch (AttackType)
	{
	case 0:
		AttackDamage = BiteAttackDamage;
		break;

	case 1:
		AttackDamage = HookAttackDamage;
		break;

	default:
		break;
	}

	return AttackDamage;
}