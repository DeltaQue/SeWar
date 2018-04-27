// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/Zombie/ZombieCharacter_2.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZombieCharacter_2() {}
// Cross Module References
	RYZEN_API UClass* Z_Construct_UClass_AZombieCharacter_2_NoRegister();
	RYZEN_API UClass* Z_Construct_UClass_AZombieCharacter_2();
	RYZEN_API UClass* Z_Construct_UClass_ARyzenBaseCharacter();
	UPackage* Z_Construct_UPackage__Script_Ryzen();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UPawnSensingComponent_NoRegister();
// End Cross Module References
	void AZombieCharacter_2::StaticRegisterNativesAZombieCharacter_2()
	{
	}
	UClass* Z_Construct_UClass_AZombieCharacter_2_NoRegister()
	{
		return AZombieCharacter_2::StaticClass();
	}
	UClass* Z_Construct_UClass_AZombieCharacter_2()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_ARyzenBaseCharacter,
				(UObject* (*)())Z_Construct_UPackage__Script_Ryzen,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "Zombie/ZombieCharacter_2.h" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
				{ "ObjectInitializerConstructorDeclared", "" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActtackAnimMontage_MetaData[] = {
				{ "Category", "Attack" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActtackAnimMontage = { UE4CodeGen_Private::EPropertyClass::Object, "ActtackAnimMontage", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000010001, 1, nullptr, STRUCT_OFFSET(AZombieCharacter_2, ActtackAnimMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(NewProp_ActtackAnimMontage_MetaData, ARRAY_COUNT(NewProp_ActtackAnimMontage_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BehaviorTree_MetaData[] = {
				{ "Category", "AI" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
				{ "ToolTip", "Assigned at the Character level (instead of Controller) so we may use different zombie behaviors while re-using one controller." },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BehaviorTree = { UE4CodeGen_Private::EPropertyClass::Object, "BehaviorTree", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000010001, 1, nullptr, STRUCT_OFFSET(AZombieCharacter_2, BehaviorTree), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(NewProp_BehaviorTree_MetaData, ARRAY_COUNT(NewProp_BehaviorTree_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SenseTimeOut_MetaData[] = {
				{ "Category", "AI" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SenseTimeOut = { UE4CodeGen_Private::EPropertyClass::Float, "SenseTimeOut", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000010001, 1, nullptr, STRUCT_OFFSET(AZombieCharacter_2, SenseTimeOut), METADATA_PARAMS(NewProp_SenseTimeOut_MetaData, ARRAY_COUNT(NewProp_SenseTimeOut_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PawnSensingComp_MetaData[] = {
				{ "Category", "AI" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PawnSensingComp = { UE4CodeGen_Private::EPropertyClass::Object, "PawnSensingComp", RF_Public|RF_Transient|RF_MarkAsNative, 0x00400000000a0009, 1, nullptr, STRUCT_OFFSET(AZombieCharacter_2, PawnSensingComp), Z_Construct_UClass_UPawnSensingComponent_NoRegister, METADATA_PARAMS(NewProp_PawnSensingComp_MetaData, ARRAY_COUNT(NewProp_PawnSensingComp_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ActtackAnimMontage,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BehaviorTree,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SenseTimeOut,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PawnSensingComp,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AZombieCharacter_2>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AZombieCharacter_2::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				nullptr, 0,
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AZombieCharacter_2, 698576411);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AZombieCharacter_2(Z_Construct_UClass_AZombieCharacter_2, &AZombieCharacter_2::StaticClass, TEXT("/Script/Ryzen"), TEXT("AZombieCharacter_2"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AZombieCharacter_2);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
