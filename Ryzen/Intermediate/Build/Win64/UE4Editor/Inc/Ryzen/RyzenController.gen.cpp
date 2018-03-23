// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "RyzenController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRyzenController() {}
// Cross Module References
	RYZEN_API UClass* Z_Construct_UClass_ARyzenController_NoRegister();
	RYZEN_API UClass* Z_Construct_UClass_ARyzenController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_Ryzen();
	RYZEN_API UFunction* Z_Construct_UFunction_ARyzenController_AddItemToInventoryByID();
	RYZEN_API UFunction* Z_Construct_UFunction_ARyzenController_GetInventoryWeight();
	RYZEN_API UFunction* Z_Construct_UFunction_ARyzenController_ReloadInventory();
	RYZEN_API UScriptStruct* Z_Construct_UScriptStruct_FInventoryItem();
	RYZEN_API UClass* Z_Construct_UClass_AInteractable_NoRegister();
// End Cross Module References
	static FName NAME_ARyzenController_ReloadInventory = FName(TEXT("ReloadInventory"));
	void ARyzenController::ReloadInventory()
	{
		ProcessEvent(FindFunctionChecked(NAME_ARyzenController_ReloadInventory),NULL);
	}
	void ARyzenController::StaticRegisterNativesARyzenController()
	{
		UClass* Class = ARyzenController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddItemToInventoryByID", &ARyzenController::execAddItemToInventoryByID },
			{ "GetInventoryWeight", &ARyzenController::execGetInventoryWeight },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ARyzenController_AddItemToInventoryByID()
	{
		struct RyzenController_eventAddItemToInventoryByID_Parms
		{
			FName ID;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RyzenController_eventAddItemToInventoryByID_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RyzenController_eventAddItemToInventoryByID_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_ID = { UE4CodeGen_Private::EPropertyClass::Name, "ID", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RyzenController_eventAddItemToInventoryByID_Parms, ID), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ID,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Utils" },
				{ "ModuleRelativePath", "RyzenController.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARyzenController, "AddItemToInventoryByID", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(RyzenController_eventAddItemToInventoryByID_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARyzenController_GetInventoryWeight()
	{
		struct RyzenController_eventGetInventoryWeight_Parms
		{
			int32 ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RyzenController_eventGetInventoryWeight_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Utils" },
				{ "ModuleRelativePath", "RyzenController.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARyzenController, "GetInventoryWeight", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(RyzenController_eventGetInventoryWeight_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARyzenController_ReloadInventory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "RyzenController.h" },
				{ "ToolTip", "????????\xc6\xae ?????? \xc8\xa3???? ?\xd4\xbc?, BlueprintImplementableEvent\n?\xce\xba??\xe4\xb8\xae ?????? ??\xc8\xbf?????? ?\xc7\xb4??\xd8\xbe??\xcf\xb4\xc2\xb5? ?\xda\xb5? ?????? ?\xc7\xbd\xc3\xb0? ?????? ??\xc8\xbf???? ?\xc7\xb4??\xcf\xb1? ?????? ????????\xc6\xae?? ??" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARyzenController, "ReloadInventory", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ARyzenController_NoRegister()
	{
		return ARyzenController::StaticClass();
	}
	UClass* Z_Construct_UClass_ARyzenController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_APlayerController,
				(UObject* (*)())Z_Construct_UPackage__Script_Ryzen,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ARyzenController_AddItemToInventoryByID, "AddItemToInventoryByID" }, // 1687951120
				{ &Z_Construct_UFunction_ARyzenController_GetInventoryWeight, "GetInventoryWeight" }, // 1410034531
				{ &Z_Construct_UFunction_ARyzenController_ReloadInventory, "ReloadInventory" }, // 4063942661
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "RyzenController.h" },
				{ "ModuleRelativePath", "RyzenController.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InventoryWeightLimit_MetaData[] = {
				{ "Category", "RyzenController" },
				{ "ModuleRelativePath", "RyzenController.h" },
				{ "ToolTip", "???? ???? ?\xd1\xb0?" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_InventoryWeightLimit = { UE4CodeGen_Private::EPropertyClass::Int, "InventoryWeightLimit", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ARyzenController, InventoryWeightLimit), METADATA_PARAMS(NewProp_InventoryWeightLimit_MetaData, ARRAY_COUNT(NewProp_InventoryWeightLimit_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InventorySlotLimit_MetaData[] = {
				{ "Category", "RyzenController" },
				{ "ModuleRelativePath", "RyzenController.h" },
				{ "ToolTip", "???? ???? ?\xd1\xb0?" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_InventorySlotLimit = { UE4CodeGen_Private::EPropertyClass::Int, "InventorySlotLimit", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ARyzenController, InventorySlotLimit), METADATA_PARAMS(NewProp_InventorySlotLimit_MetaData, ARRAY_COUNT(NewProp_InventorySlotLimit_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Money_MetaData[] = {
				{ "Category", "RyzenController" },
				{ "ModuleRelativePath", "RyzenController.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Money = { UE4CodeGen_Private::EPropertyClass::Int, "Money", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000020005, 1, nullptr, STRUCT_OFFSET(ARyzenController, Money), METADATA_PARAMS(NewProp_Money_MetaData, ARRAY_COUNT(NewProp_Money_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Inventory_MetaData[] = {
				{ "Category", "RyzenController" },
				{ "ModuleRelativePath", "RyzenController.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Inventory = { UE4CodeGen_Private::EPropertyClass::Array, "Inventory", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000020005, 1, nullptr, STRUCT_OFFSET(ARyzenController, Inventory), METADATA_PARAMS(NewProp_Inventory_MetaData, ARRAY_COUNT(NewProp_Inventory_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Inventory_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Inventory", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000020000, 1, nullptr, 0, Z_Construct_UScriptStruct_FInventoryItem, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentInteractable_MetaData[] = {
				{ "Category", "RyzenController" },
				{ "ModuleRelativePath", "RyzenController.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CurrentInteractable = { UE4CodeGen_Private::EPropertyClass::Object, "CurrentInteractable", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000020005, 1, nullptr, STRUCT_OFFSET(ARyzenController, CurrentInteractable), Z_Construct_UClass_AInteractable_NoRegister, METADATA_PARAMS(NewProp_CurrentInteractable_MetaData, ARRAY_COUNT(NewProp_CurrentInteractable_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_InventoryWeightLimit,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_InventorySlotLimit,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Money,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Inventory,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Inventory_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CurrentInteractable,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ARyzenController>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ARyzenController::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900284u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
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
	IMPLEMENT_CLASS(ARyzenController, 4288969759);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARyzenController(Z_Construct_UClass_ARyzenController, &ARyzenController::StaticClass, TEXT("/Script/Ryzen"), TEXT("ARyzenController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARyzenController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
