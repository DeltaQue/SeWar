// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "RyzenHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRyzenHUD() {}
// Cross Module References
	RYZEN_API UClass* Z_Construct_UClass_ARyzenHUD_NoRegister();
	RYZEN_API UClass* Z_Construct_UClass_ARyzenHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_Ryzen();
// End Cross Module References
	void ARyzenHUD::StaticRegisterNativesARyzenHUD()
	{
	}
	UClass* Z_Construct_UClass_ARyzenHUD_NoRegister()
	{
		return ARyzenHUD::StaticClass();
	}
	UClass* Z_Construct_UClass_ARyzenHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AHUD,
				(UObject* (*)())Z_Construct_UPackage__Script_Ryzen,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Rendering Actor Input Replication" },
				{ "IncludePath", "RyzenHUD.h" },
				{ "ModuleRelativePath", "RyzenHUD.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ARyzenHUD>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ARyzenHUD::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x0090028Cu,
				nullptr, 0,
				nullptr, 0,
				"Game",
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ARyzenHUD, 337591636);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARyzenHUD(Z_Construct_UClass_ARyzenHUD, &ARyzenHUD::StaticClass, TEXT("/Script/Ryzen"), TEXT("ARyzenHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARyzenHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
