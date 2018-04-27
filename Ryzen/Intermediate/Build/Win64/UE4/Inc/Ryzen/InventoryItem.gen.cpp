// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "InventoryItem.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryItem() {}
// Cross Module References
	RYZEN_API UScriptStruct* Z_Construct_UScriptStruct_FInventoryItem();
	UPackage* Z_Construct_UPackage__Script_Ryzen();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
// End Cross Module References
class UScriptStruct* FInventoryItem::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern RYZEN_API uint32 Get_Z_Construct_UScriptStruct_FInventoryItem_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FInventoryItem, Z_Construct_UPackage__Script_Ryzen(), TEXT("InventoryItem"), sizeof(FInventoryItem), Get_Z_Construct_UScriptStruct_FInventoryItem_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FInventoryItem(FInventoryItem::StaticStruct, TEXT("/Script/Ryzen"), TEXT("InventoryItem"), false, nullptr, nullptr);
static struct FScriptStruct_Ryzen_StaticRegisterNativesFInventoryItem
{
	FScriptStruct_Ryzen_StaticRegisterNativesFInventoryItem()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("InventoryItem")),new UScriptStruct::TCppStructOps<FInventoryItem>);
	}
} ScriptStruct_Ryzen_StaticRegisterNativesFInventoryItem;
	UScriptStruct* Z_Construct_UScriptStruct_FInventoryItem()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FInventoryItem_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Ryzen();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("InventoryItem"), sizeof(FInventoryItem), Get_Z_Construct_UScriptStruct_FInventoryItem_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "InventoryItem.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FInventoryItem>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
				{ "Category", "InventoryItem" },
				{ "ModuleRelativePath", "InventoryItem.h" },
			};
#endif
			static const UE4CodeGen_Private::FTextPropertyParams NewProp_Description = { UE4CodeGen_Private::EPropertyClass::Text, "Description", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FInventoryItem, Description), METADATA_PARAMS(NewProp_Description_MetaData, ARRAY_COUNT(NewProp_Description_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Thumbnail_MetaData[] = {
				{ "Category", "InventoryItem" },
				{ "ModuleRelativePath", "InventoryItem.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Thumbnail = { UE4CodeGen_Private::EPropertyClass::Object, "Thumbnail", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FInventoryItem, Thumbnail), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(NewProp_Thumbnail_MetaData, ARRAY_COUNT(NewProp_Thumbnail_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
				{ "Category", "InventoryItem" },
				{ "ModuleRelativePath", "InventoryItem.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Value = { UE4CodeGen_Private::EPropertyClass::Int, "Value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FInventoryItem, Value), METADATA_PARAMS(NewProp_Value_MetaData, ARRAY_COUNT(NewProp_Value_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Weight_MetaData[] = {
				{ "Category", "InventoryItem" },
				{ "ModuleRelativePath", "InventoryItem.h" },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_Weight = { UE4CodeGen_Private::EPropertyClass::Int, "Weight", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FInventoryItem, Weight), METADATA_PARAMS(NewProp_Weight_MetaData, ARRAY_COUNT(NewProp_Weight_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
				{ "Category", "InventoryItem" },
				{ "ModuleRelativePath", "InventoryItem.h" },
			};
#endif
			static const UE4CodeGen_Private::FTextPropertyParams NewProp_Name = { UE4CodeGen_Private::EPropertyClass::Text, "Name", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FInventoryItem, Name), METADATA_PARAMS(NewProp_Name_MetaData, ARRAY_COUNT(NewProp_Name_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemID_MetaData[] = {
				{ "Category", "InventoryItem" },
				{ "ModuleRelativePath", "InventoryItem.h" },
			};
#endif
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_ItemID = { UE4CodeGen_Private::EPropertyClass::Name, "ItemID", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FInventoryItem, ItemID), METADATA_PARAMS(NewProp_ItemID_MetaData, ARRAY_COUNT(NewProp_ItemID_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Description,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Thumbnail,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Value,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Weight,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Name,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ItemID,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_Ryzen,
				Z_Construct_UScriptStruct_FTableRowBase,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"InventoryItem",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FInventoryItem),
				alignof(FInventoryItem),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FInventoryItem_CRC() { return 886806852U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
