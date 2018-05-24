// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Character.h"
#include "StructClass.h"
#include "RyzenBaseCharacter.generated.h"

//UCLASS(ABSTRACT)는 이 클래스는 추상 클래스이므로 객체화 할 수 없다는 뜻이다.
UCLASS(ABSTRACT)
class RYZEN_API ARyzenBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARyzenBaseCharacter(const class FObjectInitializer& ObjectInitializer);
	
private:
	//Pawn에서 Sound체크하기 위한 컴포넌트
	UPawnNoiseEmitterComponent* NoiseEmitterComp;

public:
	//캐릭터 사운드 관련, 
	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundCue* SoundTakeHit;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundCue* SoundDeath;

	//캐릭터 스테이터스
	UFUNCTION(BlueprintCallable, Category = "PlayerCondition")
		float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable, Category = "PlayerCondition")
		float GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "PlayerCondition")
		bool IsAlive() const;

	/* 현재 카메라의 Pitch/Yaw 검색 */
	UFUNCTION(BlueprintCallable, Category = "Targeting")
		FRotator GetAimOffsets() const;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "PlayerCondition")
		float Health;

	bool bisDying;
	
	//자식 클래스(Character or AI)에서 데미지 이벤트 처리
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;

	virtual bool CanDie(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer, AActor* DamageCauser) const;

	virtual bool Die(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer, AActor* DamageCauser);

	virtual void OnDeath(float KillingDamage, FDamageEvent const& DamageEvent, APawn* PawnInstigator, AActor* DamageCauser);

};
