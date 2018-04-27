// Fill out your copyright notice in the Description page of Project Settings.

#include "ManualPickup.h"
#include "RyzenController.h"
#include "Interactable.h"
#include "PlayerCharacter.h"

AManualPickup::AManualPickup()
{
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");
	RootComponent = Cast<USceneComponent>(PickupMesh);

	CollectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollectionSphere"));
	CollectionSphere->SetupAttachment(RootComponent);
	CollectionSphere->SetSphereRadius(200.f);

	CollectionSphere->OnComponentBeginOverlap.AddDynamic(this, &AManualPickup::OnBeginOverlap);
	CollectionSphere->OnComponentEndOverlap.AddDynamic(this, &AManualPickup::OnEndOverlap);

	
	ItemID = FName("No ID");

	Super::Name = "Item";
	Super::Action = "pickup";

}

void AManualPickup::Tick(float Deltatime)
{
	Super::Tick(Deltatime);

	//OverlapCheck();
}

void AManualPickup::Interact_Implementation(APlayerController* Controller)
{
	Super::Interact_Implementation(Controller);

	ARyzenController* RController = Cast<ARyzenController>(Controller);
	if (RController->AddItemToInventoryByID(ItemID))
		Destroy();
}

bool AManualPickup::OverlapCheck()
{
	

	return true;
}

void AManualPickup::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	/*ARyzenCharacter* RCharacter = Cast<ARyzenCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	AInteractable* Interact = Cast<AInteractable>(this);

	RCharacter->CheckForManualPickup(Interact);*/

	ARyzenController* RController = Cast<ARyzenController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	RController->CurrentInteractable = this;
}

void AManualPickup::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//ARyzenCharacter* RCharacter = Cast<ARyzenCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	ARyzenController* RController = Cast<ARyzenController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	//ARyzenController* RController = Cast<ARyzenController>(RCharacter->GetController());
	RController->CurrentInteractable = nullptr;
}
