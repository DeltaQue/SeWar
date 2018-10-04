// Fill out your copyright notice in the Description page of Project Settings.

#include "FPS_GameGameModeBase.h"
#include "FPS_Game.h"
#include "UObject/ConstructorHelpers.h"



void AFPS_GameGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	
}

void AFPS_GameGameModeBase::SetPlayerSpawnTransform(FTransform SpawnTransform)
{
	PlayerSpawnTransform = SpawnTransform;
}

FTransform AFPS_GameGameModeBase::GetPlayerSpawnTransform() const
{
	return PlayerSpawnTransform;
}

float AFPS_GameGameModeBase::DamageCalc(float Damage, AActor * DamagedActor, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser) const
{
	float ActualDamage = Damage;

	ABaseCharacter* DamagedPawn = Cast<ABaseCharacter>(DamagedActor);
	if (DamagedPawn && EventInstigator)
	{

	}
	return ActualDamage;
}


bool AFPS_GameGameModeBase::SetCheckPoint(const FVector Location)
{
	if (Location == FVector::ZeroVector)
		return false;

	FString jsonstr;
	TSharedRef<TJsonWriter<TCHAR>> jsonObj = TJsonWriterFactory<>::Create(&jsonstr);

	int32 LocationX = static_cast<int32>(Location.X);
	int32 LocationY = static_cast<int32>(Location.Y);
	int32 LocationZ = static_cast<int32>(Location.Z);

	jsonObj->WriteObjectStart();
	jsonObj->WriteValue("Location X", LocationX);	// Value type : bool, int, float, string
	jsonObj->WriteValue("Location Y", LocationY);
	jsonObj->WriteValue("Location Z", LocationZ);
	jsonObj->WriteObjectEnd();
	jsonObj->Close();

	FFileHelper::SaveStringToFile(*jsonstr, *JsonFilePath);	// Save json to filePath

	return true;
}


FVector AFPS_GameGameModeBase::GetCheckPoint()
{
	FVector CheckPointLocation = FVector::ZeroVector;

	FString jsonstr;	// Recive load json text
	FFileHelper::LoadFileToString(jsonstr, *JsonFilePath);	// Load json to filePath

	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(jsonstr);
	TSharedPtr<FJsonObject> jsonObj = MakeShareable(new FJsonObject());

	if (FJsonSerializer::Deserialize(reader, jsonObj) && jsonObj.IsValid())
	{
		//CheckPointLocation.X = jsonObj->GetIntegerField("Location X");
		//CheckPointLocation.Y = jsonObj->GetIntegerField("Location Y");
		//CheckPointLocation.Z = jsonObj->GetIntegerField("Location Z");

		return FVector(jsonObj->GetIntegerField("Location X"), jsonObj->GetIntegerField("Location Y"), jsonObj->GetIntegerField("Location Z"));
	}

	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("CheckPointLocation: %d, %d, %d"), jsonObj->GetIntegerField("Location X"), jsonObj->GetIntegerField("Location Y"), jsonObj->GetIntegerField("Location Z")));

	return CheckPointLocation;
}