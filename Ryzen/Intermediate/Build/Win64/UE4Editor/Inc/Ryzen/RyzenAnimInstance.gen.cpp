// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "RyzenAnimInstance.h"
#include "Classes/Components/SkeletalMeshComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRyzenAnimInstance() {}
// Cross Module References
	RYZEN_API UClass* Z_Construct_UClass_URyzenAnimInstance_NoRegister();
	RYZEN_API UClass* Z_Construct_UClass_URyzenAnimInstance();
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	UPackage* Z_Construct_UPackage__Script_Ryzen();
	RYZEN_API UFunction* Z_Construct_UFunction_URyzenAnimInstance_UpdateAnimationProperties();
// End Cross Module References
	void URyzenAnimInstance::StaticRegisterNativesURyzenAnimInstance()
	{
		UClass* Class = URyzenAnimInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "UpdateAnimationProperties", &URyzenAnimInstance::execUpdateAnimationProperties },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_URyzenAnimInstance_UpdateAnimationProperties()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "UpdateAnimationProperties" },
				{ "ModuleRelativePath", "RyzenAnimInstance.h" },
				{ "ToolTip", "Updates the above properties" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URyzenAnimInstance, "UpdateAnimationProperties", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04080401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_URyzenAnimInstance_NoRegister()
	{
		return URyzenAnimInstance::StaticClass();
	}
	UClass* Z_Construct_UClass_URyzenAnimInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UAnimInstance,
				(UObject* (*)())Z_Construct_UPackage__Script_Ryzen,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_URyzenAnimInstance_UpdateAnimationProperties, "UpdateAnimationProperties" }, // 1470498385
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "AnimInstance" },
				{ "IncludePath", "RyzenAnimInstance.h" },
				{ "ModuleRelativePath", "RyzenAnimInstance.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MovementSpeed_MetaData[] = {
				{ "Category", "RyzenAnimInstance" },
				{ "ModuleRelativePath", "RyzenAnimInstance.h" },
				{ "ToolTip", "Holds the current speed of our character" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MovementSpeed = { UE4CodeGen_Private::EPropertyClass::Float, "MovementSpeed", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000015, 1, nullptr, STRUCT_OFFSET(URyzenAnimInstance, MovementSpeed), METADATA_PARAMS(NewProp_MovementSpeed_MetaData, ARRAY_COUNT(NewProp_MovementSpeed_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsFalling_MetaData[] = {
				{ "Category", "RyzenAnimInstance" },
				{ "ModuleRelativePath", "RyzenAnimInstance.h" },
				{ "ToolTip", "True means that we're currently in air - or falling" },
			};
#endif
			auto NewProp_bIsFalling_SetBit = [](void* Obj){ ((URyzenAnimInstance*)Obj)->bIsFalling = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsFalling = { UE4CodeGen_Private::EPropertyClass::Bool, "bIsFalling", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000015, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(URyzenAnimInstance), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bIsFalling_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bIsFalling_MetaData, ARRAY_COUNT(NewProp_bIsFalling_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MovementSpeed,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bIsFalling,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URyzenAnimInstance>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URyzenAnimInstance::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900088u,
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
	IMPLEMENT_CLASS(URyzenAnimInstance, 3026689877);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URyzenAnimInstance(Z_Construct_UClass_URyzenAnimInstance, &URyzenAnimInstance::StaticClass, TEXT("/Script/Ryzen"), TEXT("URyzenAnimInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URyzenAnimInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
