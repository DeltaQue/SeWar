// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/Player/RyzenBaseCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRyzenBaseCharacter() {}
// Cross Module References
	RYZEN_API UClass* Z_Construct_UClass_ARyzenBaseCharacter_NoRegister();
	RYZEN_API UClass* Z_Construct_UClass_ARyzenBaseCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_Ryzen();
	RYZEN_API UFunction* Z_Construct_UFunction_ARyzenBaseCharacter_GetAimOffsets();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	RYZEN_API UFunction* Z_Construct_UFunction_ARyzenBaseCharacter_GetHealth();
	RYZEN_API UFunction* Z_Construct_UFunction_ARyzenBaseCharacter_GetMaxHealth();
	RYZEN_API UFunction* Z_Construct_UFunction_ARyzenBaseCharacter_IsAlive();
	ENGINE_API UClass* Z_Construct_UClass_USoundCue_NoRegister();
// End Cross Module References
	void ARyzenBaseCharacter::StaticRegisterNativesARyzenBaseCharacter()
	{
		UClass* Class = ARyzenBaseCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAimOffsets", &ARyzenBaseCharacter::execGetAimOffsets },
			{ "GetHealth", &ARyzenBaseCharacter::execGetHealth },
			{ "GetMaxHealth", &ARyzenBaseCharacter::execGetMaxHealth },
			{ "IsAlive", &ARyzenBaseCharacter::execIsAlive },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ARyzenBaseCharacter_GetAimOffsets()
	{
		struct RyzenBaseCharacter_eventGetAimOffsets_Parms
		{
			FRotator ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RyzenBaseCharacter_eventGetAimOffsets_Parms, ReturnValue), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Targeting" },
				{ "ModuleRelativePath", "Public/Player/RyzenBaseCharacter.h" },
				{ "ToolTip", "???? \xc4\xab?\xde\xb6??? Pitch/Yaw ?\xcb\xbb?" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARyzenBaseCharacter, "GetAimOffsets", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54820401, sizeof(RyzenBaseCharacter_eventGetAimOffsets_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARyzenBaseCharacter_GetHealth()
	{
		struct RyzenBaseCharacter_eventGetHealth_Parms
		{
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RyzenBaseCharacter_eventGetHealth_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "PlayerCondition" },
				{ "ModuleRelativePath", "Public/Player/RyzenBaseCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARyzenBaseCharacter, "GetHealth", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(RyzenBaseCharacter_eventGetHealth_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARyzenBaseCharacter_GetMaxHealth()
	{
		struct RyzenBaseCharacter_eventGetMaxHealth_Parms
		{
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RyzenBaseCharacter_eventGetMaxHealth_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "PlayerCondition" },
				{ "ModuleRelativePath", "Public/Player/RyzenBaseCharacter.h" },
				{ "ToolTip", "\xc4\xb3???? ???????\xcd\xbd?" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARyzenBaseCharacter, "GetMaxHealth", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(RyzenBaseCharacter_eventGetMaxHealth_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARyzenBaseCharacter_IsAlive()
	{
		struct RyzenBaseCharacter_eventIsAlive_Parms
		{
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RyzenBaseCharacter_eventIsAlive_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RyzenBaseCharacter_eventIsAlive_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "PlayerCondition" },
				{ "ModuleRelativePath", "Public/Player/RyzenBaseCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARyzenBaseCharacter, "IsAlive", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(RyzenBaseCharacter_eventIsAlive_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ARyzenBaseCharacter_NoRegister()
	{
		return ARyzenBaseCharacter::StaticClass();
	}
	UClass* Z_Construct_UClass_ARyzenBaseCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_ACharacter,
				(UObject* (*)())Z_Construct_UPackage__Script_Ryzen,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ARyzenBaseCharacter_GetAimOffsets, "GetAimOffsets" }, // 338231466
				{ &Z_Construct_UFunction_ARyzenBaseCharacter_GetHealth, "GetHealth" }, // 3443479899
				{ &Z_Construct_UFunction_ARyzenBaseCharacter_GetMaxHealth, "GetMaxHealth" }, // 3337617404
				{ &Z_Construct_UFunction_ARyzenBaseCharacter_IsAlive, "IsAlive" }, // 4231189134
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "Player/RyzenBaseCharacter.h" },
				{ "ModuleRelativePath", "Public/Player/RyzenBaseCharacter.h" },
				{ "ObjectInitializerConstructorDeclared", "" },
				{ "ToolTip", "UCLASS(ABSTRACT)?? ?? \xc5\xac?????? ?\xdf\xbb? \xc5\xac?????\xcc\xb9\xc7\xb7? ??\xc3\xbc\xc8\xad ?? ?? ???\xd9\xb4? ???\xcc\xb4?." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[] = {
				{ "Category", "PlayerCondition" },
				{ "ModuleRelativePath", "Public/Player/RyzenBaseCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Health = { UE4CodeGen_Private::EPropertyClass::Float, "Health", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000010001, 1, nullptr, STRUCT_OFFSET(ARyzenBaseCharacter, Health), METADATA_PARAMS(NewProp_Health_MetaData, ARRAY_COUNT(NewProp_Health_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SoundDeath_MetaData[] = {
				{ "Category", "Sound" },
				{ "ModuleRelativePath", "Public/Player/RyzenBaseCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SoundDeath = { UE4CodeGen_Private::EPropertyClass::Object, "SoundDeath", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000010001, 1, nullptr, STRUCT_OFFSET(ARyzenBaseCharacter, SoundDeath), Z_Construct_UClass_USoundCue_NoRegister, METADATA_PARAMS(NewProp_SoundDeath_MetaData, ARRAY_COUNT(NewProp_SoundDeath_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SoundTakeHit_MetaData[] = {
				{ "Category", "Sound" },
				{ "ModuleRelativePath", "Public/Player/RyzenBaseCharacter.h" },
				{ "ToolTip", "\xc4\xb3???? ?????? ????," },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SoundTakeHit = { UE4CodeGen_Private::EPropertyClass::Object, "SoundTakeHit", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000010001, 1, nullptr, STRUCT_OFFSET(ARyzenBaseCharacter, SoundTakeHit), Z_Construct_UClass_USoundCue_NoRegister, METADATA_PARAMS(NewProp_SoundTakeHit_MetaData, ARRAY_COUNT(NewProp_SoundTakeHit_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Health,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SoundDeath,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SoundTakeHit,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ARyzenBaseCharacter>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ARyzenBaseCharacter::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900081u,
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
	IMPLEMENT_CLASS(ARyzenBaseCharacter, 1138511152);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARyzenBaseCharacter(Z_Construct_UClass_ARyzenBaseCharacter, &ARyzenBaseCharacter::StaticClass, TEXT("/Script/Ryzen"), TEXT("ARyzenBaseCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARyzenBaseCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
