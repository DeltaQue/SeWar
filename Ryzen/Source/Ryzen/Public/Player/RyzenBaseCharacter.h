// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Character.h"
#include "RyzenBaseCharacter.generated.h"

//UCLASS(ABSTRACT)는 이 클래스는 추상 클래스이므로 객체화 할 수 없다는 뜻이다.
UCLASS(ABSTRACT)
class RYZEN_API ARyzenBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARyzenBaseCharacter(const class FObjectInitializer& ObjectInitializer);
	


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


protected:
	UPROPERTY(EditDefaultsOnly, Category = "PlayerCondition")
		float Health;

	bool bisDying;

public:
	/* 현재 카메라의 Pitch/Yaw 검색 */
	UFUNCTION(BlueprintCallable, Category = "Targeting")
		FRotator GetAimOffsets() const;


};
