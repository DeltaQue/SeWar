// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/Zombie/BTTask_FindPatrolLocation.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTTask_FindPatrolLocation() {}
// Cross Module References
	RYZEN_API UClass* Z_Construct_UClass_UBTTask_FindPatrolLocation_NoRegister();
	RYZEN_API UClass* Z_Construct_UClass_UBTTask_FindPatrolLocation();
	AIMODULE_API UClass* Z_Construct_UClass_UBTTask_BlackboardBase();
	UPackage* Z_Construct_UPackage__Script_Ryzen();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	void UBTTask_FindPatrolLocation::StaticRegisterNativesUBTTask_FindPatrolLocation()
	{
	}
	UClass* Z_Construct_UClass_UBTTask_FindPatrolLocation_NoRegister()
	{
		return UBTTask_FindPatrolLocation::StaticClass();
	}
	UClass* Z_Construct_UClass_UBTTask_FindPatrolLocation()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UBTTask_BlackboardBase,
				(UObject* (*)())Z_Construct_UPackage__Script_Ryzen,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "Zombie/BTTask_FindPatrolLocation.h" },
				{ "ModuleRelativePath", "Public/Zombie/BTTask_FindPatrolLocation.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Distance_MetaData[] = {
				{ "ModuleRelativePath", "Public/Zombie/BTTask_FindPatrolLocation.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Distance = { UE4CodeGen_Private::EPropertyClass::Float, "Distance", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000000, 1, nullptr, STRUCT_OFFSET(UBTTask_FindPatrolLocation, Distance), METADATA_PARAMS(NewProp_Distance_MetaData, ARRAY_COUNT(NewProp_Distance_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CharacterLocation_MetaData[] = {
				{ "ModuleRelativePath", "Public/Zombie/BTTask_FindPatrolLocation.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_CharacterLocation = { UE4CodeGen_Private::EPropertyClass::Struct, "CharacterLocation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000000, 1, nullptr, STRUCT_OFFSET(UBTTask_FindPatrolLocation, CharacterLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(NewProp_CharacterLocation_MetaData, ARRAY_COUNT(NewProp_CharacterLocation_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Distance,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CharacterLocation,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UBTTask_FindPatrolLocation>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UBTTask_FindPatrolLocation::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00100080u,
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
	IMPLEMENT_CLASS(UBTTask_FindPatrolLocation, 4235986364);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UBTTask_FindPatrolLocation(Z_Construct_UClass_UBTTask_FindPatrolLocation, &UBTTask_FindPatrolLocation::StaticClass, TEXT("/Script/Ryzen"), TEXT("UBTTask_FindPatrolLocation"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTTask_FindPatrolLocation);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
