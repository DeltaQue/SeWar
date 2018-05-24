// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/RDamageType.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRDamageType() {}
// Cross Module References
	RYZEN_API UClass* Z_Construct_UClass_URDamageType_NoRegister();
	RYZEN_API UClass* Z_Construct_UClass_URDamageType();
	ENGINE_API UClass* Z_Construct_UClass_UDamageType();
	UPackage* Z_Construct_UPackage__Script_Ryzen();
// End Cross Module References
	void URDamageType::StaticRegisterNativesURDamageType()
	{
	}
	UClass* Z_Construct_UClass_URDamageType_NoRegister()
	{
		return URDamageType::StaticClass();
	}
	UClass* Z_Construct_UClass_URDamageType()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UDamageType,
				(UObject* (*)())Z_Construct_UPackage__Script_Ryzen,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "RDamageType.h" },
				{ "ModuleRelativePath", "Public/RDamageType.h" },
				{ "ObjectInitializerConstructorDeclared", "" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LimbDmgModifier_MetaData[] = {
				{ "Category", "RDamageType" },
				{ "ModuleRelativePath", "Public/RDamageType.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_LimbDmgModifier = { UE4CodeGen_Private::EPropertyClass::Float, "LimbDmgModifier", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000010011, 1, nullptr, STRUCT_OFFSET(URDamageType, LimbDmgModifier), METADATA_PARAMS(NewProp_LimbDmgModifier_MetaData, ARRAY_COUNT(NewProp_LimbDmgModifier_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HeadDmgModifier_MetaData[] = {
				{ "Category", "RDamageType" },
				{ "ModuleRelativePath", "Public/RDamageType.h" },
				{ "ToolTip", "Headshot ??????" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HeadDmgModifier = { UE4CodeGen_Private::EPropertyClass::Float, "HeadDmgModifier", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000010011, 1, nullptr, STRUCT_OFFSET(URDamageType, HeadDmgModifier), METADATA_PARAMS(NewProp_HeadDmgModifier_MetaData, ARRAY_COUNT(NewProp_HeadDmgModifier_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_LimbDmgModifier,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_HeadDmgModifier,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URDamageType>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URDamageType::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00110080u,
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
	IMPLEMENT_CLASS(URDamageType, 488429146);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URDamageType(Z_Construct_UClass_URDamageType, &URDamageType::StaticClass, TEXT("/Script/Ryzen"), TEXT("URDamageType"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URDamageType);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
