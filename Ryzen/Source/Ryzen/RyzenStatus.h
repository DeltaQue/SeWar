// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RyzenStatus.generated.h"

/**
 * 
 */
UCLASS()
class RYZEN_API URyzenStatus : public UObject
{
	GENERATED_BODY()
	
	
	/* 캐릭터 스테이터스 */
	//힘, 민첩, 체력, 방사능내성, 공격력, 공격속도, 체력, 방사능 수치, 경험치

	//공격력 = 힘 * 2, 1단계 감염자 체력 : 100, 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Status", meta = (AllowPrivateAccess = "true"))
		int32 Strength;; //힘, 공격력 상승 기본 Status : 10

	//공격속도 = 민첩 * 0.5, 기본 공격속도 : 0.5/s, 2초당 1발 연사속도
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Status", meta = (AllowPrivateAccess = "true"))
		int32 Agility; //민첩, 공격속도 상승  기본 Status : 10

	//체력 = Stamina * 10  if)Stamina : 15, 체력 : 150
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Status", meta = (AllowPrivateAccess = "true"))
		int32 Stamina; //체력, 체력 상승  기본 Status : 10 

	/*방사능 내성, 방사능 수치가 100을 넘어서면 체력이 2초에 한번씩 체력 감소
		방사능 체력 감소 수치/2s = 20 % 방사능 내성  */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Status", meta = (AllowPrivateAccess = "true"))
		int32 Radiation; //방사능 내성, 방사능 노출에 의해 감소되는 체력 감소 ,기본 Status : 5

	
public:
	int32 GetStr() const { return Strength; }
	int32 GetAgr() const { return Agility; }
	int32 GetStm() const { return Stamina; }
	int32 GetRdt() const { return Radiation; }
};
