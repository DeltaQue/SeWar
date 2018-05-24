// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/Zombie/ZombieAIController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZombieAIController() {}
// Cross Module References
	RYZEN_API UClass* Z_Construct_UClass_AZombieAIController_NoRegister();
	RYZEN_API UClass* Z_Construct_UClass_AZombieAIController();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_Ryzen();
// End Cross Module References
	void AZombieAIController::StaticRegisterNativesAZombieAIController()
	{
	}
	UClass* Z_Construct_UClass_AZombieAIController_NoRegister()
	{
		return AZombieAIController::StaticClass();
	}
	UClass* Z_Construct_UClass_AZombieAIController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AAIController,
				(UObject* (*)())Z_Construct_UPackage__Script_Ryzen,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "Zombie/ZombieAIController.h" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieAIController.h" },
				{ "ObjectInitializerConstructorDeclared", "" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsAttackCollisionOverlapKeyName_MetaData[] = {
				{ "Category", "AI" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieAIController.h" },
			};
#endif
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_IsAttackCollisionOverlapKeyName = { UE4CodeGen_Private::EPropertyClass::Name, "IsAttackCollisionOverlapKeyName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000010001, 1, nullptr, STRUCT_OFFSET(AZombieAIController, IsAttackCollisionOverlapKeyName), METADATA_PARAMS(NewProp_IsAttackCollisionOverlapKeyName_MetaData, ARRAY_COUNT(NewProp_IsAttackCollisionOverlapKeyName_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsArriveKeyName_MetaData[] = {
				{ "Category", "AI" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieAIController.h" },
			};
#endif
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_IsArriveKeyName = { UE4CodeGen_Private::EPropertyClass::Name, "IsArriveKeyName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000010001, 1, nullptr, STRUCT_OFFSET(AZombieAIController, IsArriveKeyName), METADATA_PARAMS(NewProp_IsArriveKeyName_MetaData, ARRAY_COUNT(NewProp_IsArriveKeyName_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReconLocationKeyName_MetaData[] = {
				{ "Category", "AI" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieAIController.h" },
			};
#endif
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_ReconLocationKeyName = { UE4CodeGen_Private::EPropertyClass::Name, "ReconLocationKeyName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000010001, 1, nullptr, STRUCT_OFFSET(AZombieAIController, ReconLocationKeyName), METADATA_PARAMS(NewProp_ReconLocationKeyName_MetaData, ARRAY_COUNT(NewProp_ReconLocationKeyName_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BotTypeKeyName_MetaData[] = {
				{ "Category", "AI" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieAIController.h" },
			};
#endif
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_BotTypeKeyName = { UE4CodeGen_Private::EPropertyClass::Name, "BotTypeKeyName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000010001, 1, nullptr, STRUCT_OFFSET(AZombieAIController, BotTypeKeyName), METADATA_PARAMS(NewProp_BotTypeKeyName_MetaData, ARRAY_COUNT(NewProp_BotTypeKeyName_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentWaypointKeyName_MetaData[] = {
				{ "Category", "AI" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieAIController.h" },
			};
#endif
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_CurrentWaypointKeyName = { UE4CodeGen_Private::EPropertyClass::Name, "CurrentWaypointKeyName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000010001, 1, nullptr, STRUCT_OFFSET(AZombieAIController, CurrentWaypointKeyName), METADATA_PARAMS(NewProp_CurrentWaypointKeyName_MetaData, ARRAY_COUNT(NewProp_CurrentWaypointKeyName_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PatrolLocationKeyName_MetaData[] = {
				{ "Category", "AI" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieAIController.h" },
			};
#endif
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_PatrolLocationKeyName = { UE4CodeGen_Private::EPropertyClass::Name, "PatrolLocationKeyName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000010001, 1, nullptr, STRUCT_OFFSET(AZombieAIController, PatrolLocationKeyName), METADATA_PARAMS(NewProp_PatrolLocationKeyName_MetaData, ARRAY_COUNT(NewProp_PatrolLocationKeyName_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetEnemyKeyName_MetaData[] = {
				{ "Category", "AI" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieAIController.h" },
			};
#endif
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_TargetEnemyKeyName = { UE4CodeGen_Private::EPropertyClass::Name, "TargetEnemyKeyName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000010001, 1, nullptr, STRUCT_OFFSET(AZombieAIController, TargetEnemyKeyName), METADATA_PARAMS(NewProp_TargetEnemyKeyName_MetaData, ARRAY_COUNT(NewProp_TargetEnemyKeyName_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_IsAttackCollisionOverlapKeyName,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_IsArriveKeyName,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReconLocationKeyName,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BotTypeKeyName,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CurrentWaypointKeyName,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PatrolLocationKeyName,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetEnemyKeyName,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AZombieAIController>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AZombieAIController::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900280u,
				nullptr, 0,
				PropPointers, ARRAY_COUNT(PropPointers),
				"Game",
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AZombieAIController, 1313337084);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AZombieAIController(Z_Construct_UClass_AZombieAIController, &AZombieAIController::StaticClass, TEXT("/Script/Ryzen"), TEXT("AZombieAIController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AZombieAIController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
