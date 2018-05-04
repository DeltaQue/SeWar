// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/StructClass.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStructClass() {}
// Cross Module References
	RYZEN_API UEnum* Z_Construct_UEnum_Ryzen_EZombieType();
	UPackage* Z_Construct_UPackage__Script_Ryzen();
// End Cross Module References
	static UEnum* EZombieType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Ryzen_EZombieType, Z_Construct_UPackage__Script_Ryzen(), TEXT("EZombieType"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EZombieType(EZombieType_StaticEnum, TEXT("/Script/Ryzen"), TEXT("EZombieType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Ryzen_EZombieType_CRC() { return 3435179160U; }
	UEnum* Z_Construct_UEnum_Ryzen_EZombieType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Ryzen();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EZombieType"), 0, Get_Z_Construct_UEnum_Ryzen_EZombieType_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EZombieType::Pssing", (int64)EZombieType::Pssing },
				{ "EZombieType::Patrol", (int64)EZombieType::Patrol },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/StructClass.h" },
				{ "Patrol.ToolTip", "?\xc3\xb7??\xcc\xbe\xee\xb8\xa6 ?\xdf\xb0??\xcf\xb1? ???? \xc5\xbd???\xcf\xb4? ????" },
				{ "Pssing.ToolTip", "?????? ?????? ?\xd6\xb4? ????" },
				{ "ToolTip", "#include \"StructClass.generated.h\"" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Ryzen,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EZombieType",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EZombieType",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
