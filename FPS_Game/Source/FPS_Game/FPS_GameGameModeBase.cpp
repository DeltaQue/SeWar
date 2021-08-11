// Fill out your copyright notice in the Description page of Project Settings.

#include "FPS_GameGameModeBase.h"
#include "FPS_Game.h"
#include "UObject/ConstructorHelpers.h"

void AFPS_GameGameModeBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	//FString GameInfojsonstr;	// Recive load json text
	//FFileHelper::LoadFileToString(GameInfojsonstr, *JsonFilePath);	// Load json to filePath

	//TSharedRef<TJsonReader<TCHAR>> GameInforeader = TJsonReaderFactory<TCHAR>::Create(GameInfojsonstr);
	//TSharedPtr<FJsonObject> GameInfojsonObj = MakeShareable(new FJsonObject());

	//if (FJsonSerializer::Deserialize(GameInforeader, GameInfojsonObj) && GameInfojsonObj.IsValid())
	//{
	//	LoadLocation = FVector(GameInfojsonObj->GetIntegerField("Location X"), GameInfojsonObj->GetIntegerField("Location Y"), GameInfojsonObj->GetIntegerField("Location Z"));
	//	LoadHP = (int32)(GameInfojsonObj->GetIntegerField("Current HP"));
	//	LoadQuestNum = GameInfojsonObj->GetStringField("");
	//	LoadKillpoint;
	//	LoadLoadedAmmo;
	//	LoadedRemainingAmmo;
	//}


}

void AFPS_GameGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	FString jsonstr;	// Recive load json text
	FFileHelper::LoadFileToString(jsonstr, *QuestFilePath);	// Load json to filePath

	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(jsonstr);
	TSharedPtr<FJsonObject> jsonObj = MakeShareable(new FJsonObject());

	if (FJsonSerializer::Deserialize(reader, jsonObj) && jsonObj.IsValid())
	{
		TSharedPtr<FJsonObject> Quest = jsonObj->GetObjectField("Quest");
		TArray<TSharedPtr<FJsonValue>> QuestScript = jsonObj->GetObjectField("Quest")->GetArrayField("Script");

		TArray <TSharedPtr <FJsonValue >> TutorialScriptArray = QuestScript[0]->AsArray();
		Tutorial_Quest_Script_Max = TutorialScriptArray.Max();

		TArray <TSharedPtr <FJsonValue >> Quest1ScriptArray = QuestScript[1]->AsArray();
		Stage1_Quest_Script_Max = Quest1ScriptArray.Max();

		TArray <TSharedPtr <FJsonValue >> Quest2ScriptArray = QuestScript[2]->AsArray();
		Stage2_Quest_Script_Max = Quest2ScriptArray.Max();

		TArray <TSharedPtr <FJsonValue >> HealScriptArray = QuestScript[3]->AsArray();
		Heal_Script_Max = HealScriptArray.Max();

		TArray <TSharedPtr <FJsonValue >> AmmoScriptArray = QuestScript[4]->AsArray();
		Ammo_Script_Max = AmmoScriptArray.Max();
	}


	

	SetZombieSpawnPoint();
	

	QuestScriptNum = 0;
	QuestNum = 0;

	NPCScriptNum = 0;
	NPCNum = 0;

	
}

void AFPS_GameGameModeBase::SetPlayerSpawnTransform(FTransform& SpawnTransform)
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


void AFPS_GameGameModeBase::SpawnZombie()
{
	//Spawn Zombie Array 
	//0: Tutorial Zombie
	//1: Stage1 Zombie
	//2: Stage2 Zombie
	//3: Boss Zombie
	if (SpawnZombieArray.Num() > 0)
	{
		switch (QuestNum)
		{
		//Tutorial Zombie Spawn
		case 0:
			if (ZombieSpawnCheck[QuestNum] == false)
			{
				if (SpawnZombieArray[0])
				{
					FVector SpawnLoc(ZombieSpawnPoint[0]);
					FRotator SpawnRot(0.f, 0.f, 0.f);
					FActorSpawnParameters SpawnInfo;
					SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
					SpawnInfo.bAllowDuringConstructionScript = true;
					//AZombieCharacter* NewZombie = GetWorld()->SpawnActor<AZombieCharacter>(SpawnZombieArray[i], SpawnLoc, SpawnRot, SpawnInfo);
					StoreSpawnZombie.Add(GetWorld()->SpawnActor<AZombieCharacter>(SpawnZombieArray[0], SpawnLoc, SpawnRot, SpawnInfo));

					ZombieSpawnCheck[QuestNum] = true;
				}
			}
			break;
		
		//Stage1 Zombie Spawn, 5마리
		case 1:
			if (ZombieSpawnCheck[QuestNum] == false)
			{
				for (int32 i = 1; i < 6; i++)
				{
					if (SpawnZombieArray[1])
					{
						FVector SpawnLoc(ZombieSpawnPoint[i]);
						FRotator SpawnRot(0.f, 0.f, 0.f);
						FActorSpawnParameters SpawnInfo;
						SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
						SpawnInfo.bAllowDuringConstructionScript = true;
						//AZombieCharacter* NewZombie = GetWorld()->SpawnActor<AZombieCharacter>(SpawnZombieArray[i], SpawnLoc, SpawnRot, SpawnInfo);
						StoreSpawnZombie.Add(GetWorld()->SpawnActor<AZombieCharacter>(SpawnZombieArray[1], SpawnLoc, SpawnRot, SpawnInfo));
					}
				}
				ZombieSpawnCheck[QuestNum] = true;
			}
			break;

		//Stage2 Zombie Spawn, 16마리
		case 2:
			if (ZombieSpawnCheck[QuestNum] == false)
			{
				for (int32 i = 6; i < 22; i++)
				{
					if (SpawnZombieArray[2])
					{
						FVector SpawnLoc(ZombieSpawnPoint[i]);
						FRotator SpawnRot(0.f, 0.f, 0.f);
						FActorSpawnParameters SpawnInfo;
						SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
						SpawnInfo.bAllowDuringConstructionScript = true;
						//AZombieCharacter* NewZombie = GetWorld()->SpawnActor<AZombieCharacter>(Stage2SpawnZombieArray, SpawnLoc, SpawnRot, SpawnInfo);
						StoreSpawnZombie.Add(GetWorld()->SpawnActor<AZombieCharacter>(SpawnZombieArray[2], SpawnLoc, SpawnRot, SpawnInfo));
					}
				}
				ZombieSpawnCheck[QuestNum] = true;

				// + Boss Zombie Spawn
				if (SpawnZombieArray[3])
				{
					FVector SpawnLoc(ZombieSpawnPoint[22]);
					FRotator SpawnRot(0.f, 0.f, 0.f);
					FActorSpawnParameters SpawnInfo;
					SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
					SpawnInfo.bAllowDuringConstructionScript = true;

					StoreSpawnZombie.Add(GetWorld()->SpawnActor<AZombieCharacter>(SpawnZombieArray[3], SpawnLoc, SpawnRot, SpawnInfo));
				}
			}
			break;

		default:
			break;
		}
	}
}

bool AFPS_GameGameModeBase::SetClearCheckPoint()
{
	FString jsonstr;
	TSharedRef<TJsonWriter<TCHAR>> jsonObj = TJsonWriterFactory<>::Create(&jsonstr);


	jsonObj->WriteObjectStart();
	jsonObj->WriteValue("Location X", -5);	// Value type : bool, int, float, string
	jsonObj->WriteValue("Location Y", -1958);
	jsonObj->WriteValue("Location Z", 200);
	jsonObj->WriteValue("Current Quest", 0);
	jsonObj->WriteValue("Current HP", 100);
	jsonObj->WriteValue("LoadedAmmo", 30);
	jsonObj->WriteValue("RemainingAmmo", 30);
	jsonObj->WriteValue("Killpoint", 0);
	jsonObj->WriteObjectEnd();
	jsonObj->Close();

	FFileHelper::SaveStringToFile(*jsonstr, *JsonFilePath);	// Save json to filePath

	return true;
}

bool AFPS_GameGameModeBase::SetCheckPoint(const FVector Location, const float HP, const int32 LoadedAmmo, const int32 RemainingAmmo, const int32 Killpoint)
{
	if (Location == FVector::ZeroVector)
		return false;

	FString jsonstr;
	TSharedRef<TJsonWriter<TCHAR>> jsonObj = TJsonWriterFactory<>::Create(&jsonstr);

	int32 LocationX = static_cast<int32>(Location.X);
	int32 LocationY = static_cast<int32>(Location.Y);
	int32 LocationZ = static_cast<int32>(Location.Z);
	
	int32 Health = static_cast<int32>(HP);

	jsonObj->WriteObjectStart();
	jsonObj->WriteValue("Location X", LocationX);	// Value type : bool, int, float, string
	jsonObj->WriteValue("Location Y", LocationY);
	jsonObj->WriteValue("Location Z", LocationZ);
	jsonObj->WriteValue("Current Quest", QuestNum);
	jsonObj->WriteValue("Current HP", Health);
	jsonObj->WriteValue("LoadedAmmo", LoadedAmmo);
	jsonObj->WriteValue("RemainingAmmo", RemainingAmmo);
	jsonObj->WriteValue("Killpoint", Killpoint);
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
		return FVector(jsonObj->GetIntegerField("Location X"), jsonObj->GetIntegerField("Location Y"), jsonObj->GetIntegerField("Location Z"));
	}
	return CheckPointLocation;
}

float AFPS_GameGameModeBase::GetLoadHP()
{
	float LoadHP = 100;

	FString jsonstr;	// Recive load json text
	FFileHelper::LoadFileToString(jsonstr, *JsonFilePath);	// Load json to filePath

	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(jsonstr);
	TSharedPtr<FJsonObject> jsonObj = MakeShareable(new FJsonObject());

	if (FJsonSerializer::Deserialize(reader, jsonObj) && jsonObj.IsValid())
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString::Printf(TEXT("Load HP data : %d"), (int32)(jsonObj->GetIntegerField("Current HP"))));
		return (int32)(jsonObj->GetIntegerField("Current HP"));
	}

	return LoadHP;
}

int32 AFPS_GameGameModeBase::GetLoadKillpoint()
{
	int LoadKillpoint = 0;

	FString jsonstr;	// Recive load json text
	FFileHelper::LoadFileToString(jsonstr, *JsonFilePath);	// Load json to filePath

	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(jsonstr);
	TSharedPtr<FJsonObject> jsonObj = MakeShareable(new FJsonObject());

	if (FJsonSerializer::Deserialize(reader, jsonObj) && jsonObj.IsValid())
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString::Printf(TEXT("killpoint : %d"), jsonObj->GetIntegerField("Killpoint")));
		return jsonObj->GetIntegerField("Killpoint");
	}

	return LoadKillpoint;
}

int32 AFPS_GameGameModeBase::GetLoadQuest()
{
	int LoadQuestNum = 0;

	FString jsonstr;	// Recive load json text
	FFileHelper::LoadFileToString(jsonstr, *JsonFilePath);	// Load json to filePath

	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(jsonstr);
	TSharedPtr<FJsonObject> jsonObj = MakeShareable(new FJsonObject());

	if (FJsonSerializer::Deserialize(reader, jsonObj) && jsonObj.IsValid())
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString::Printf(TEXT("QuestNum : %d"), jsonObj->GetIntegerField("Current Quest")));
		return jsonObj->GetIntegerField("Current Quest");
	}

	return LoadQuestNum;
}

int32 AFPS_GameGameModeBase::GetLoadLoadedAmmo()
{
	int LoadLoadedAmmo = 0;

	FString jsonstr;	// Recive load json text
	FFileHelper::LoadFileToString(jsonstr, *JsonFilePath);	// Load json to filePath

	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(jsonstr);
	TSharedPtr<FJsonObject> jsonObj = MakeShareable(new FJsonObject());

	if (FJsonSerializer::Deserialize(reader, jsonObj) && jsonObj.IsValid())
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString::Printf(TEXT("LoadedAmmo : %d"), jsonObj->GetIntegerField("LoadedAmmo")));
		return jsonObj->GetIntegerField("LoadedAmmo");
	}

	return LoadLoadedAmmo;
}

int32 AFPS_GameGameModeBase::GetLoadRemainingAmmo()
{
	int LoadRemainingAmmo = 0;

	FString jsonstr;	// Recive load json text
	FFileHelper::LoadFileToString(jsonstr, *JsonFilePath);	// Load json to filePath

	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(jsonstr);
	TSharedPtr<FJsonObject> jsonObj = MakeShareable(new FJsonObject());

	if (FJsonSerializer::Deserialize(reader, jsonObj) && jsonObj.IsValid())
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString::Printf(TEXT("RemainingAmmo : %d"), jsonObj->GetIntegerField("RemainingAmmo")));
		return jsonObj->GetIntegerField("RemainingAmmo");
	}

	return LoadRemainingAmmo;
}

FText AFPS_GameGameModeBase::GetQuestScript()
{
	FString jsonstr;	// Recive load json text
	FFileHelper::LoadFileToString(jsonstr, *QuestFilePath);	// Load json to filePath

	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(jsonstr);
	TSharedPtr<FJsonObject> jsonObj = MakeShareable(new FJsonObject());

	if (FJsonSerializer::Deserialize(reader, jsonObj) && jsonObj.IsValid())
	{
		TSharedPtr<FJsonObject> Quest = jsonObj->GetObjectField("Quest");
		TArray<TSharedPtr<FJsonValue>> QuestScript = jsonObj->GetObjectField("Quest")->GetArrayField("Script");

		TArray <TSharedPtr <FJsonValue >> ScriptArray = QuestScript[QuestNum]->AsArray();

		return FText::FromString(ScriptArray[QuestScriptNum]->AsString());
	}

	return FText::FromString(TEXT("Fale"));
}

FText AFPS_GameGameModeBase::GetQuestData(int DataNum)
{

	FString jsonstr;	// Recive load json text
	FFileHelper::LoadFileToString(jsonstr, *QuestDataFilePath);	// Load json to filePath

	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(jsonstr);
	TSharedPtr<FJsonObject> jsonObj = MakeShareable(new FJsonObject());

	if (FJsonSerializer::Deserialize(reader, jsonObj) && jsonObj.IsValid())
	{
		//Get Quest Data
		TArray<TSharedPtr<FJsonValue>> QuestData = jsonObj->GetObjectField("QuestData")->GetArrayField("Script");
		TArray <TSharedPtr <FJsonValue >> QuestData_Array = QuestData[QuestNum]->AsArray();

		//DataNum
		//0 : 퀘스트 이름
		//1 : 퀘스트 내용
		//2 : 퀘스트 목표
		return FText::FromString(QuestData_Array[DataNum]->AsString());
	}

	return FText::FromString(TEXT("Fale"));
}


FText AFPS_GameGameModeBase::GetNPCScript(int32 NPCType)
{
	FString jsonstr;	// Recive load json text
	FFileHelper::LoadFileToString(jsonstr, *QuestFilePath);	// Load json to filePath

	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(jsonstr);
	TSharedPtr<FJsonObject> jsonObj = MakeShareable(new FJsonObject());

	if (FJsonSerializer::Deserialize(reader, jsonObj) && jsonObj.IsValid())
	{
		TSharedPtr<FJsonObject> Quest = jsonObj->GetObjectField("Quest");
		TArray<TSharedPtr<FJsonValue>> QuestScript = jsonObj->GetObjectField("Quest")->GetArrayField("Script");

		TArray <TSharedPtr <FJsonValue >> ScriptArray = QuestScript[NPCType]->AsArray();

		return FText::FromString(ScriptArray[QuestScriptNum]->AsString());
	}

	return FText::FromString(TEXT("Fale"));
}


void AFPS_GameGameModeBase::NextQuestScript()
{
	//QuestNum : 0  => Tutorial Script
	//QuestNum : 1  => Stage1 Quest Script
	//QuestNum : 2  => Stage2 Quest Script
	if (QuestNum == 0)
	{
		if (QuestScriptNum < Tutorial_Quest_Script_Max-1)
			QuestScriptNum++;
	}
	else if (QuestNum == 1)
	{
		if (QuestScriptNum < Stage1_Quest_Script_Max - 1)
			QuestScriptNum++;
	}
	else if (QuestNum == 2)
	{
		if (QuestScriptNum < Stage2_Quest_Script_Max - 1)
			QuestScriptNum++;
	}


}

void AFPS_GameGameModeBase::NextNPCScript(int32 NPCNum)
{
	//NPCNum
	//0 : Quest NPC
	//1 : Heal NPC
	//2 : Ammo NPC
	switch (NPCNum)
	{
	case 0:
		break;

	case 1:
		if (NPCScriptNum < Heal_Script_Max - 1)
			NPCScriptNum++;
		break;

	case 2:
		if (NPCScriptNum < Ammo_Script_Max - 1)
			NPCScriptNum++;
		break;

	default:
		break;
	}
}

void AFPS_GameGameModeBase::NextQuest()
{
	//QuestNum : 0  => Tutorial Script
	//QuestNum : 1  => Stage1 Quest Script
	//QuestNum : 2  => Stage2 Quest Script
	if (QuestNum == 0)
	{
		QuestNum++;
		QuestScriptNum = 0;
	}
	else if (QuestNum == 1)
	{
		QuestNum++;
		QuestScriptNum = 0;
	}
}

void AFPS_GameGameModeBase::ClearQuest()
{
	QuestScriptNum = 0;
}

void AFPS_GameGameModeBase::ClearNPCScript()
{
	NPCScriptNum = 0;
}

int32 AFPS_GameGameModeBase::GetQuestScriptNum() const
{
	return QuestScriptNum;
}

int32 AFPS_GameGameModeBase::GetQuestNum() const
{
	return QuestNum;
}

int32 AFPS_GameGameModeBase::GetNPCScriptNum() const
{
	return NPCScriptNum;
}

int32 AFPS_GameGameModeBase::GetQuestScriptMaxSize(int32 QuestNum) const
{
	switch (QuestNum)
	{
	case 0:
		return Tutorial_Quest_Script_Max;

		break;

	case 1:
		return Stage1_Quest_Script_Max;

		break;

	case 2:
		return Stage2_Quest_Script_Max;

		break;


	default:
		return -1;
		break;
	}

}

int32 AFPS_GameGameModeBase::GetNPCScriptMaxSize(int32 NPCType) const
{

	//NPCType
	//0 : Quest NPC
	//1 : Heal NPC
	//2 : Ammo NPC
	switch (QuestNum)
	{
	case 1:
		return Heal_Script_Max;
		break;

	case 2:
		return Ammo_Script_Max;
		break;

	case 0:
	default:
		return -1;
		break;
	}
}

void AFPS_GameGameModeBase::SetCompleteQuest(int32 QuestNum)
{
	switch (QuestNum)
	{
	case 0:
		Complete_Quest[0] = true;
		NextQuest();
		break;

	case 1:
		Complete_Quest[1] = true;
		NextQuest();
		break;

	case 2:
		Complete_Quest[2] = true;
		break;

	default:
		break;
	}
}


void AFPS_GameGameModeBase::SetZombieSpawnPoint()
{
	//튜토리얼 좀비(1마리)
	ZombieSpawnPoint.Add(FVector(23.0f, 398.0f, 250.0f));

	//스테이지1 좀비(5마리)
	ZombieSpawnPoint.Add(FVector(386.0f, 948.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(1222.0f, 1414.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(1666.0f, 686.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(2518.0f, -22.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(2518.0f, -2981.0f, 250.0f));

	//스테이지2 시작 좀비 스폰
	ZombieSpawnPoint.Add(FVector(15609.0f, -7202.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(13706.0f, -7202.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(13706.0f, -4912.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(13706.0f, -3838.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(12568.0f, -3838.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(12568.0f, -4311.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(12568.0f, -2463.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(12568.0f, 441.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(13212.0f, 441.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(13212.0f, 1328.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(14224.0f, 1328.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(16338.0f, 1328.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(16338.0f, 2662.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(16680.0f, -1488.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(14119.0f, 2801.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(13348.0f, 3293.0f, 250.0f));

	//보스 좀비 스폰
	ZombieSpawnPoint.Add(FVector(13291.0f, -3559.0f, 242.837448f));

	//스테이지2 좀비 스포너 포인트
	ZombieSpawnPoint.Add(FVector(9248.0f, -7563.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(18127.0f, -7642.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(13869.0f, -1311.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(16587.0f, 3676.0f, 250.0f));
	ZombieSpawnPoint.Add(FVector(10135.0f, 3110.0f, 250.0f));
}


TArray<class AZombieCharacter*> AFPS_GameGameModeBase::GetSpawnZombie()
{
	return StoreSpawnZombie;
}


void AFPS_GameGameModeBase::SpawnZombieKill(class AZombieCharacter* Zombie)
{
	int Index = 0;
	Index = StoreSpawnZombie.Find(Zombie);

	StoreSpawnZombie.RemoveAt(Index);
}


void AFPS_GameGameModeBase::SetQuest(int NewQuestNum)
{
	if(NewQuestNum < 3)
		QuestNum = NewQuestNum;
}

void AFPS_GameGameModeBase::RestartPlayer(class AController* NewPlayer)
{
	FVector SpawnOrigin = FVector::ZeroVector;
	FRotator StartRotation = FRotator::ZeroRotator;

	if (GetCheckPoint() != FVector::ZeroVector)
	{
		SpawnOrigin = GetCheckPoint();
	}

	if (NewPlayer->GetPawn() == nullptr && GetDefaultPawnClassForController(NewPlayer) != nullptr)
	{
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.Instigator = Instigator;
		APawn* ResultPawn = GetWorld()->SpawnActor<APawn>(GetDefaultPawnClassForController(NewPlayer), SpawnOrigin, StartRotation, SpawnInfo);
		if (ResultPawn == nullptr)
		{
			// faile
		}
		NewPlayer->SetPawn(ResultPawn);
	}


	if (NewPlayer->GetPawn() == nullptr)
	{
		NewPlayer->FailedToSpawnPawn();
	}
	else
	{
		NewPlayer->Possess(NewPlayer->GetPawn());

		if (NewPlayer->GetPawn() == nullptr)
		{
			NewPlayer->FailedToSpawnPawn();
		}
		else
		{
			NewPlayer->ClientSetRotation(NewPlayer->GetPawn()->GetActorRotation(), true);

			FRotator NewControllerRot = StartRotation;
			NewControllerRot.Roll = 0.f;
			NewPlayer->SetControlRotation(NewControllerRot);

			SetPlayerDefaults(NewPlayer->GetPawn());
		}
	}

}