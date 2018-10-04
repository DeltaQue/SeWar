// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPS_GameGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FPS_GAME_API AFPS_GameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	
private:
	UPROPERTY()
		FTransform PlayerSpawnTransform;

	const FString JsonFilePath = FPaths::ProjectContentDir() + "/Data/LoadData.json";
	FString JsonString; //Json converted to FString

	TSharedPtr<FJsonObject> JsonObject;

	TArray<TSharedPtr<FJsonValue>> ObjArray;

protected:
	virtual void BeginPlay() override;

public:
	void SetPlayerSpawnTransform(FTransform SpawnTransform);

	FTransform GetPlayerSpawnTransform() const;

	float DamageCalc(float Damage, AActor* DamagedActor, struct FDamageEvent const &DamageEvent, AController* EventInstigator, AActor* DamageCauser) const;

	bool SetCheckPoint(const FVector Location);

	FVector GetCheckPoint();
};
