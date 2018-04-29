// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "StructClass.generated.h"

UENUM()
enum class EZombieType : uint8 {
	//좀비가 정지해 있는 상태
	Pssing,

	//플레이어를 발견하기 위해 탐색하는 상태
	Ptrol
};