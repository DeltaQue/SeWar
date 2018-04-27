// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "RyzenStatus.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRyzenStatus() {}
// Cross Module References
	RYZEN_API UClass* Z_Construct_UClass_URyzenStatus_NoRegister();
	RYZEN_API UClass* Z_Construct_UClass_URyzenStatus();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_Ryzen();
// End Cross Module References
	void URyzenStatus::StaticRegisterNativesURyzenStatus()
	{
	}
	UClass* Z_Construct_UClass_URyzenStatus_NoRegister()
	{
		return URyzenStatus::StaticClass();
	}
	UClass* Z_Construct_UClass_URyzenStatus()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UObject,
				(UObject* (*)())Z_Construct_UPackage__Script_Ryzen,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "RyzenStatus.h" },
				{ "ModuleRelativePath", "RyzenStatus.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Radiation_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Status" },
				{ "ModuleRelativePath", "RyzenStatus.h" },
				{ "ToolTip", "?????? ????, ?????? ??\xc4\xa1?? 100?? ?\xd1\xbe\xee\xbc\xad?? \xc3\xbc???? 2?\xca\xbf? ?\xd1\xb9??? \xc3\xbc?? ????\n               ?????? \xc3\xbc?? ???? ??\xc4\xa1/2s = 20 % ?????? ????" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Radiation = { UE4CodeGen_Private::EPropertyClass::Int, "Radiation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000020005, 1, nullptr, STRUCT_OFFSET(URyzenStatus, Radiation), METADATA_PARAMS(NewProp_Radiation_MetaData, ARRAY_COUNT(NewProp_Radiation_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Stamina_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Status" },
				{ "ModuleRelativePath", "RyzenStatus.h" },
				{ "ToolTip", "\xc3\xbc?? = Stamina * 10  if)Stamina : 15, \xc3\xbc?? : 150" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Stamina = { UE4CodeGen_Private::EPropertyClass::Int, "Stamina", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000020005, 1, nullptr, STRUCT_OFFSET(URyzenStatus, Stamina), METADATA_PARAMS(NewProp_Stamina_MetaData, ARRAY_COUNT(NewProp_Stamina_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Agility_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Status" },
				{ "ModuleRelativePath", "RyzenStatus.h" },
				{ "ToolTip", "???\xdd\xbc\xd3\xb5? = ??\xc3\xb8 * 0.5, ?\xe2\xba\xbb ???\xdd\xbc\xd3\xb5? : 0.5/s, 2?\xca\xb4? 1?? ?????\xd3\xb5?" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Agility = { UE4CodeGen_Private::EPropertyClass::Int, "Agility", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000020005, 1, nullptr, STRUCT_OFFSET(URyzenStatus, Agility), METADATA_PARAMS(NewProp_Agility_MetaData, ARRAY_COUNT(NewProp_Agility_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Strength_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Status" },
				{ "ModuleRelativePath", "RyzenStatus.h" },
				{ "ToolTip", "???\xdd\xb7? = ?? * 2, 1?\xdc\xb0? ?????? \xc3\xbc?? : 100," },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Strength = { UE4CodeGen_Private::EPropertyClass::Int, "Strength", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000020005, 1, nullptr, STRUCT_OFFSET(URyzenStatus, Strength), METADATA_PARAMS(NewProp_Strength_MetaData, ARRAY_COUNT(NewProp_Strength_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Radiation,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Stamina,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Agility,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Strength,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URyzenStatus>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URyzenStatus::StaticClass,
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
	IMPLEMENT_CLASS(URyzenStatus, 2878576044);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URyzenStatus(Z_Construct_UClass_URyzenStatus, &URyzenStatus::StaticClass, TEXT("/Script/Ryzen"), TEXT("URyzenStatus"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URyzenStatus);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
