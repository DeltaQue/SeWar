// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "RyzenStateBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRyzenStateBase() {}
// Cross Module References
	RYZEN_API UClass* Z_Construct_UClass_ARyzenStateBase_NoRegister();
	RYZEN_API UClass* Z_Construct_UClass_ARyzenStateBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameStateBase();
	UPackage* Z_Construct_UPackage__Script_Ryzen();
	ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
// End Cross Module References
	void ARyzenStateBase::StaticRegisterNativesARyzenStateBase()
	{
	}
	UClass* Z_Construct_UClass_ARyzenStateBase_NoRegister()
	{
		return ARyzenStateBase::StaticClass();
	}
	UClass* Z_Construct_UClass_ARyzenStateBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AGameStateBase,
				(UObject* (*)())Z_Construct_UPackage__Script_Ryzen,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "RyzenStateBase.h" },
				{ "ModuleRelativePath", "RyzenStateBase.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemDB_MetaData[] = {
				{ "Category", "RyzenStateBase" },
				{ "ModuleRelativePath", "RyzenStateBase.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ItemDB = { UE4CodeGen_Private::EPropertyClass::Object, "ItemDB", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000010001, 1, nullptr, STRUCT_OFFSET(ARyzenStateBase, ItemDB), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(NewProp_ItemDB_MetaData, ARRAY_COUNT(NewProp_ItemDB_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ItemDB,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ARyzenStateBase>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ARyzenStateBase::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900280u,
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
	IMPLEMENT_CLASS(ARyzenStateBase, 855614846);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARyzenStateBase(Z_Construct_UClass_ARyzenStateBase, &ARyzenStateBase::StaticClass, TEXT("/Script/Ryzen"), TEXT("ARyzenStateBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARyzenStateBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
