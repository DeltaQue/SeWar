// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Interactable.h"
#include "ManualPickup.generated.h"

/**
 * 
 */
UCLASS()
class RYZEN_API AManualPickup : public AInteractable
{
	GENERATED_BODY()

private:
	UFUNCTION()
		bool OverlapCheck();

	//아이템 수집 반경체크 구체
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CollectionSphere", meta = (AllowPrivateAccess = "true"))
		class USphereComponent* CollectionSphere;

	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION()
		void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:
	AManualPickup();

	virtual void Tick(float DeltaTime) override;

	void Interact_Implementation(APlayerController* Controller) override;

protected:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* PickupMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ItemID;
	
	
		
		
	
};
