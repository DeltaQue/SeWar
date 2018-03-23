// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "ManualPickup.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeManualPickup() {}
// Cross Module References
	RYZEN_API UClass* Z_Construct_UClass_AManualPickup_NoRegister();
	RYZEN_API UClass* Z_Construct_UClass_AManualPickup();
	RYZEN_API UClass* Z_Construct_UClass_AInteractable();
	UPackage* Z_Construct_UPackage__Script_Ryzen();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AManualPickup::StaticRegisterNativesAManualPickup()
	{
	}
	UClass* Z_Construct_UClass_AManualPickup_NoRegister()
	{
		return AManualPickup::StaticClass();
	}
	UClass* Z_Construct_UClass_AManualPickup()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AInteractable,
				(UObject* (*)())Z_Construct_UPackage__Script_Ryzen,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "ManualPickup.h" },
				{ "ModuleRelativePath", "ManualPickup.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemID_MetaData[] = {
				{ "Category", "ManualPickup" },
				{ "ModuleRelativePath", "ManualPickup.h" },
			};
#endif
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_ItemID = { UE4CodeGen_Private::EPropertyClass::Name, "ItemID", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000005, 1, nullptr, STRUCT_OFFSET(AManualPickup, ItemID), METADATA_PARAMS(NewProp_ItemID_MetaData, ARRAY_COUNT(NewProp_ItemID_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PickupMesh_MetaData[] = {
				{ "Category", "ManualPickup" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "ManualPickup.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PickupMesh = { UE4CodeGen_Private::EPropertyClass::Object, "PickupMesh", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000080009, 1, nullptr, STRUCT_OFFSET(AManualPickup, PickupMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(NewProp_PickupMesh_MetaData, ARRAY_COUNT(NewProp_PickupMesh_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ItemID,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PickupMesh,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AManualPickup>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AManualPickup::StaticClass,
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
	IMPLEMENT_CLASS(AManualPickup, 3433393836);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AManualPickup(Z_Construct_UClass_AManualPickup, &AManualPickup::StaticClass, TEXT("/Script/Ryzen"), TEXT("AManualPickup"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AManualPickup);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
