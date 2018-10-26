// Fill out your copyright notice in the Description page of Project Settings.

#include "BossAIController.h"
#include "FPS_Game.h"
#include "BossCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"



ABossAIController::ABossAIController(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	BehaviorTreeComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
	BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));

	TargetEnemyKeyName = "Enemy";
}

void ABossAIController::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);

	ABossCharacter* BossBot = Cast<ABossCharacter>(InPawn);
	if (BossBot)
	{
		if (BehaviorTree)
		{
			BlackboardComp->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
			BehaviorTreeComp->StartTree(*BehaviorTree);
		}
	}

	BehaviorTreeComp->StartTree(*BossBot->BehaviorTree);
}

void ABossAIController::UnPossess()
{
	Super::UnPossess();

	BehaviorTreeComp->StopTree();
}

AActor* ABossAIController::GetSeeingPawn()
{
	//Return the seeing pawn
	UObject* object = BlackboardComp->GetValueAsObject(TargetEnemyKeyName);

	return object ? Cast<AActor>(object) : nullptr;
}



void ABossAIController::SetTargetEnemy(APawn* NewTarget)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(TargetEnemyKeyName, NewTarget);
	}
}