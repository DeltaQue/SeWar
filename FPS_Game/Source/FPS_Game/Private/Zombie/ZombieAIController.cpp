// Fill out your copyright notice in the Description page of Project Settings.

#include "ZombieAIController.h"
#include "ZombieCharacter.h"
#include "BaseCharacter.h"




/* AI Specific includes */
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"


AZombieAIController::AZombieAIController(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	BehaviorComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
	BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));

	/* Blackboard 키값과 매칭 */
	PatrolLocationKeyName = "PatrolLocation";
	CurrentWaypointKeyName = "CurrentWaypoint";
	ZombieTypeKeyName = "ZombieType";
	TargetEnemyKeyName = "TargetEnemy";
	ReconLocationKeyName = "ReconLocation";
	EscapePointKeyName = "EscapePoint";
}


void AZombieAIController::Possess(class APawn* InPawn)
{
	Super::Possess(InPawn);

	AZombieCharacter* ZombieBot = Cast<AZombieCharacter>(InPawn);
	if (ZombieBot)
	{
		if (ZombieBot->BehaviorTree && ZombieBot->BehaviorTree->BlackboardAsset)
		{
			if (ZombieBot->BehaviorTree->BlackboardAsset)
			{
				BlackboardComp->InitializeBlackboard(*ZombieBot->BehaviorTree->BlackboardAsset);

				/* Make sure the Blackboard has the type of bot we possessed */
				SetBlackboardZombieType(ZombieBot->ZombieType);
			}

			BehaviorComp->StartTree(*ZombieBot->BehaviorTree);
		}
	}
}


void AZombieAIController::UnPossess()
{
	Super::UnPossess();

	/* Stop any behavior running as we no longer have a pawn to control */
	BehaviorComp->StopTree();
}


AWaypoint* AZombieAIController::GetWaypoint() const
{
	if (BlackboardComp)
	{
		return Cast<AWaypoint>(BlackboardComp->GetValueAsObject(CurrentWaypointKeyName));
	}

	return nullptr;
}

AEscapePoint* AZombieAIController::GetEscapePoint() const
{
	if (BlackboardComp)
	{
		return Cast<AEscapePoint>(BlackboardComp->GetValueAsObject(EscapePointKeyName));
	}

	return nullptr;
}

FVector AZombieAIController::GetReconLocation() const
{
	if (BlackboardComp)
	{
		return FVector(BlackboardComp->GetValueAsVector(ReconLocationKeyName));
	}

	return FVector(-1, -1, -1);
}

ABaseCharacter* AZombieAIController::GetTargetEnemy() const
{
	if (BlackboardComp)
	{
		return Cast<ABaseCharacter>(BlackboardComp->GetValueAsObject(TargetEnemyKeyName));
	}

	return nullptr;
}

bool AZombieAIController::GetIsAttackCollisionOverlap() const
{
	if (BlackboardComp)
	{
		return BlackboardComp->GetValueAsBool(IsAttackCollisionOverlapKeyName);
	}

	return false;
}



void AZombieAIController::SetWaypoint(AWaypoint* NewWaypoint)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(CurrentWaypointKeyName, NewWaypoint);
	}
}


void AZombieAIController::SetTargetEnemy(APawn* NewTarget)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(TargetEnemyKeyName, NewTarget);
	}
}

void AZombieAIController::SetBlackboardZombieType(EZombieType NewType)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsEnum(ZombieTypeKeyName, (uint8)NewType);
	}
}

void AZombieAIController::SetReconLocation(FVector vector)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsVector(ReconLocationKeyName, vector);
	}
}

void AZombieAIController::SetIsAttackCollisionOverlap(bool Overlaped)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsBool(IsAttackCollisionOverlapKeyName, Overlaped);
	}
}

void AZombieAIController::SetPatrolLocation(FVector Location)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsVector(PatrolLocationKeyName, Location);
	}
}

void AZombieAIController::SetEscapePoint(AEscapePoint* EscapeTarget)
{
	AZombieCharacter* Boss = Cast<AZombieCharacter>(this->GetPawn());

	if (Boss->GetIsBoss())
	{
		if (BlackboardComp)
		{
			BlackboardComp->SetValueAsObject(EscapePointKeyName, EscapeTarget);
		}
	}
}




void AZombieAIController::StopBehaviorTree()
{
	BehaviorComp->StopTree();
}

void AZombieAIController::StartBehaviorTree()
{
	AZombieCharacter *ZombieBot = Cast<AZombieCharacter>(GetPawn());
	BehaviorComp->StartTree(*ZombieBot->BehaviorTree);
}