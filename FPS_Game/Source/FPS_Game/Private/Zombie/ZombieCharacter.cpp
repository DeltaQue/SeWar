// Fill out your copyright notice in the Description page of Project Settings.

#include "ZombieCharacter.h"
#include "ZombieAIController.h"
#include "BaseCharacter.h"



/* AI Include */
#include "Perception/PawnSensingComponent.h"

//DECLARE_DELEGATE_OneParam(ScreamTimerDelegate, APawn*)

// Sets default values
AZombieCharacter::AZombieCharacter(const class FObjectInitializer& ObjectInitializer)
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


	AudioLoopComp = CreateDefaultSubobject<UAudioComponent>(TEXT("ZombieLoopedSoundComp"));
	AudioLoopComp->bAutoActivate = false;
	AudioLoopComp->bAutoDestroy = false;
	AudioLoopComp->SetupAttachment(RootComponent);

	////Zombie HP bar widget
	//MyWidget = CreateDefaultSubobject<UWidgetComponent>("Widget");

	//static ConstructorHelpers::FClassFinder<UUserWidget> hudWidgetObj(TEXT("/Game/UserInterface/Zombie/HPBar"));
	//if (hudWidgetObj.Succeeded()) {
	//	hudWidgetObj.Class = hudWidgetObj.Class;

	//	MyWidget->SetWidgetSpace(EWidgetSpace::World);
	//	MyWidget->SetWidgetClass(hudWidgetObj.Class);
	//	MyWidget->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	//	MyWidget->SetDrawSize(FVector2D(100.0f, 20.0f));
	//	MyWidget->SetTwoSided(true);
	//	MyWidget->SetVisibility(true);
	//	MyWidget->RegisterComponent();
	//}
	//else {
	//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "SelectableActorHUD not found !");
	//	hudWidgetObj.Class = nullptr;
	//}



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

	AttackCooltime = 1.5f;

	//ZombieType = EZombieType::Passing;
}


void AZombieCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (PawnSensingComp)
	{
		PawnSensingComp->OnSeePawn.AddDynamic(this, &AZombieCharacter::OnSeePlayer);

		PawnSensingComp->OnHearNoise.AddDynamic(this, &AZombieCharacter::OnHearNoise);
	}
	if (AttackCollisionComp)
	{
		AttackCollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AZombieCharacter::OnAttackCollisionCompBeginOverlap);
	}

	DefaultMaxWalkSpeed = GetMovementComponent()->GetMaxSpeed();

	AudioLoopUpdate(bSensedTarget);

	//if (!MyWidget->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("HPBar_Sock")))
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Error Attach HP Bar"));
	//}
}


void AZombieCharacter::Tick(float DeltaSeconds)
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
			bPlayedScream = false;
			bHeardTarget = false;

			/* 타겟 리셋 */
			AIController->SetTargetEnemy(nullptr);

			AudioLoopUpdate(false);

			AIController->SetReconLocation(FVector(-1, -1, -1));

			Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = DefaultMaxWalkSpeed;
		}
	}

	IsDeath();
}



void AZombieCharacter::OnSeePlayer(APawn* Pawn)
{
	if (!IsAlive())
	{
		return;
	}

	if (!bSensedTarget)
	{
		AudioLoopUpdate(true);
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
		FTimerDelegate RespawnDelegate = FTimerDelegate::CreateUObject(this, &AZombieCharacter::TargetChase, Pawn);
		GetWorldTimerManager().SetTimer(UniqueHandle, RespawnDelegate, Duration, false);
	}
	
}

void AZombieCharacter::TargetChase(APawn* Pawn)
{
	//타겟을 발견 한 뒤 월드 시간을 받음
	LastSeenTime = GetWorld()->GetTimeSeconds();
	bSensedTarget = true;

	AZombieAIController* AIController = Cast<AZombieAIController>(GetController());
	ABaseCharacter* SensedPawn = Cast<ABaseCharacter>(Pawn);
	if (AIController && SensedPawn->IsAlive())
	{
		AIController->SetTargetEnemy(SensedPawn);


		Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = DefaultMaxWalkSpeed * 10.f;
	}
}

void AZombieCharacter::OnHearNoise(APawn* PawnInstigator, const FVector& Location, float Volume) {
	if (!IsAlive())
	{
		return;
	}

	if (!bSensedTarget)
	{
		AudioLoopUpdate(true);
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

void AZombieCharacter::SetZombieType(EZombieType NewType)
{
	ZombieType = NewType;

	AZombieAIController* ZombieController = Cast<AZombieAIController>(GetController());
	if (ZombieController)
	{
		ZombieController->SetBlackboardZombieType(NewType);
	}

	AudioLoopUpdate(bSensedTarget);
}


void AZombieCharacter::OnAttackCollisionCompBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor);
	//Timer Stop
	if (Player && this->Health > 0)
	{
		TimerHandle_AttackTimer.Invalidate();

		ScratchAttack(OtherActor);

		AZombieAIController* Controller = Cast<AZombieAIController>(GetController());
		Controller->SetIsAttackCollisionOverlap(true);

		//Timer함수. AttackTimer가 Invalidate 되지 않았다면, AttackCooltime 마다 ReTriggerAttack 함수를 실행함.
		GetWorldTimerManager().SetTimer(TimerHandle_AttackTimer, this, &AZombieCharacter::ReTriggerAttack, AttackCooltime, true);
		//TimerHandleFunc();
	}
}

void AZombieCharacter::OnAttackCollisionCompEndOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AZombieAIController* Controller = Cast<AZombieAIController>(GetController());

	Controller->SetIsAttackCollisionOverlap(false);
}

bool AZombieCharacter::DamageHit(uint8 damage)
{
	if (this->Health - damage > 0) {
		this->Health -= damage;
		if (this->IsAlive()) {
			return true;
		}

	}

	return false;
}

void AZombieCharacter::IsDeath()
{
	//if (!this->IsAlive())
		//Destroy();

}

void AZombieCharacter::PlayAttackMotion()
{
	if (AttackAnimMontage)
	{
		//AnimInstance->Montage_Play(AttackAnimMontage, 2.5f);
		this->PlayAnimMontage(AttackAnimMontage);
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


void AZombieCharacter::ScratchAttack(AActor* HitActor)
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

				if(AttackAnimMontage)
					this->PlayAnimMontage(AttackAnimMontage);
				//PlayAttackMotion();
			}

		}
	}
}


void AZombieCharacter::ReTriggerAttack()
{
	TArray<AActor*> OverlapActor;
	//Attack Collision에 Timer가 ReTriggerAttack을 실행 할 때 마다, Overlap된 액터를 집어넣음
	AttackCollisionComp->GetOverlappingActors(OverlapActor, ABaseCharacter::StaticClass());
	for (int32 i = 0; i < OverlapActor.Num(); i++)
	{
		ABaseCharacter* OverlappingPawn = Cast<ABaseCharacter>(OverlapActor[i]);
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

void AZombieCharacter::AudioLoopUpdate(bool bNewSensedTarget)
{
	if (bNewSensedTarget && bSensedTarget)
	{
		if (PlayerChaseSoundCue)
		{
			UGameplayStatics::SpawnSoundAttached(PlayerChaseSoundCue, RootComponent, NAME_None, FVector::ZeroVector, EAttachLocation::SnapToTarget, true);

			AudioLoopComp->SetSound(PlayerChaseSoundCue);
			AudioLoopComp->Play();
		}
	}
	else
	{
		if (ZombieType == EZombieType::Patrol)
		{
			AudioLoopComp->SetSound(PlayerWanderingSoundCue);
			AudioLoopComp->Play();
		}
		else
		{
			AudioLoopComp->SetSound(IdleSoundCue);
			AudioLoopComp->Play();
		}
	}
}


void AZombieCharacter::TimerHandleFunc()
{
	//Timer함수. AttackTimer가 Invalidate 되지 않았다면, AttackCooltime 마다 ReTriggerAttack 함수를 실행함.
	GetWorldTimerManager().SetTimer(TimerHandle_AttackTimer, this, &AZombieCharacter::ReTriggerAttack, AttackCooltime, true);
}

UAnimInstance* AZombieCharacter::GetAttackAnimInstance() const { return AnimInstance; }

UAnimMontage* AZombieCharacter::GetAttackAnimMontage() const { return AttackAnimMontage; }