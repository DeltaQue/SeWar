// Fill out your copyright notice in the Description page of Project Settings.

#include "RyzenBaseCharacter.h"


// Sets default values
ARyzenBaseCharacter::ARyzenBaseCharacter(const class FObjectInitializer& ObjectInitializer)
{

	NoiseEmitterComp = CreateDefaultSubobject<UPawnNoiseEmitterComponent>(TEXT("NoiseEmitterComp"));
}

bool ARyzenBaseCharacter::IsAlive() const{
	if (Health > 0)
		return true;
	else
		return false;
}

float ARyzenBaseCharacter::GetHealth() const{
	return Health;
}

float ARyzenBaseCharacter::GetMaxHealth() const{
	return 100.0f;
}

FRotator ARyzenBaseCharacter::GetAimOffsets() const{
	/*GetBaseAimRotation()은Pawn의 타겟 회전을 돌려줍니다. 
	컨트롤러가있는 경우, 기본적으로 AI의 Pawn rotation과 
	인간 플레이어의 카메라 (크로스헤어) 회전 인 플레이어의 '시선'방향을 목표로한다.*/
	const FVector AimDirWS = GetBaseAimRotation().Vector();
	const FVector AimDirLS = ActorToWorld().InverseTransformVectorNoScale(AimDirWS);
	const FRotator AimRotLS = AimDirLS.Rotation();

	return AimRotLS;
}

float ARyzenBaseCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	if (Health < 0.0f) 
	{
		return -1.0f;
	}

	//상속받은 자식 클래스에서 TakeDamage로 인자를 넘겨받아 Pawn Class의 TakeDamage로 데미지 계산함
	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	if (ActualDamage > 0.0f)
	{
		Health -= ActualDamage;
		if (Health <= 0.0f)
		{
			
		}
	}

	return ActualDamage;
}

bool ARyzenBaseCharacter::CanDie(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer, AActor* DamageCauser) const
{
	if (bisDying || IsPendingKill() || GetWorld()->GetAuthGameMode() == nullptr)
	{
		return true;
	}

	return true;
}

bool ARyzenBaseCharacter::Die(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer, AActor* DamageCauser)
{
	if (!CanDie(KillingDamage, DamageEvent, Killer, DamageCauser))
	{
		return false;
	}

	Health = 0.0f;



	return true;
}

void ARyzenBaseCharacter::OnDeath(float KillingDamage, FDamageEvent const& DamageEvent, APawn* PawnInstigator, AActor* DamageCauser)
{
	if (bisDying)
	{
		return;
	}

}