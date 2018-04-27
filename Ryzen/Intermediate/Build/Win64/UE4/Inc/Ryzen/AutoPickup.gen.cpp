// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "AutoPickup.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAutoPickup() {}
// Cross Module References
	RYZEN_API UClass* Z_Construct_UClass_AAutoPickup_NoRegister();
	RYZEN_API UClass* Z_Construct_UClass_AAutoPickup();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Ryzen();
	RYZEN_API UFunction* Z_Construct_UFunction_AAutoPickup_Collect();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	static FName NAME_AAutoPickup_Collect = FName(TEXT("Collect"));
	void AAutoPickup::Collect(APlayerController* Controller)
	{
		AutoPickup_eventCollect_Parms Parms;
		Parms.Controller=Controller;
		ProcessEvent(FindFunctionChecked(NAME_AAutoPickup_Collect),&Parms);
	}
	void AAutoPickup::StaticRegisterNativesAAutoPickup()
	{
		UClass* Class = AAutoPickup::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Collect", &AAutoPickup::execCollect },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_AAutoPickup_Collect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Controller = { UE4CodeGen_Private::EPropertyClass::Object, "Controller", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AutoPickup_eventCollect_Parms, Controller), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Controller,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "AutoPickup.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AAutoPickup, "Collect", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020C00, sizeof(AutoPickup_eventCollect_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AAutoPickup_NoRegister()
	{
		return AAutoPickup::StaticClass();
	}
	UClass* Z_Construct_UClass_AAutoPickup()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_Ryzen,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_AAutoPickup_Collect, "Collect" }, // 1410173655
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "AutoPickup.h" },
				{ "ModuleRelativePath", "AutoPickup.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemID_MetaData[] = {
				{ "Category", "AutoPickup" },
				{ "ModuleRelativePath", "AutoPickup.h" },
			};
#endif
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_ItemID = { UE4CodeGen_Private::EPropertyClass::Name, "ItemID", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000005, 1, nullptr, STRUCT_OFFSET(AAutoPickup, ItemID), METADATA_PARAMS(NewProp_ItemID_MetaData, ARRAY_COUNT(NewProp_ItemID_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PickupMesh_MetaData[] = {
				{ "Category", "AutoPickup" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "AutoPickup.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PickupMesh = { UE4CodeGen_Private::EPropertyClass::Object, "PickupMesh", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000080009, 1, nullptr, STRUCT_OFFSET(AAutoPickup, PickupMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(NewProp_PickupMesh_MetaData, ARRAY_COUNT(NewProp_PickupMesh_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ItemID,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PickupMesh,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AAutoPickup>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AAutoPickup::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
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
	IMPLEMENT_CLASS(AAutoPickup, 2843926550);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AAutoPickup(Z_Construct_UClass_AAutoPickup, &AAutoPickup::StaticClass, TEXT("/Script/Ryzen"), TEXT("AAutoPickup"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAutoPickup);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
