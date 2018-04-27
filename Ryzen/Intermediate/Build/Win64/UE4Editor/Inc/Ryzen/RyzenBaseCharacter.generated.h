// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FRotator;
#ifdef RYZEN_RyzenBaseCharacter_generated_h
#error "RyzenBaseCharacter.generated.h already included, missing '#pragma once' in RyzenBaseCharacter.h"
#endif
#define RYZEN_RyzenBaseCharacter_generated_h

#define Ryzen_Source_Ryzen_Public_Player_RyzenBaseCharacter_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetAimOffsets) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FRotator*)Z_Param__Result=P_THIS->GetAimOffsets(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsAlive) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsAlive(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetHealth) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetHealth(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMaxHealth) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetMaxHealth(); \
		P_NATIVE_END; \
	}


#define Ryzen_Source_Ryzen_Public_Player_RyzenBaseCharacter_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetAimOffsets) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FRotator*)Z_Param__Result=P_THIS->GetAimOffsets(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsAlive) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsAlive(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetHealth) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetHealth(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMaxHealth) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetMaxHealth(); \
		P_NATIVE_END; \
	}


#define Ryzen_Source_Ryzen_Public_Player_RyzenBaseCharacter_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARyzenBaseCharacter(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_ARyzenBaseCharacter(); \
public: \
	DECLARE_CLASS(ARyzenBaseCharacter, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(ARyzenBaseCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_Public_Player_RyzenBaseCharacter_h_13_INCLASS \
private: \
	static void StaticRegisterNativesARyzenBaseCharacter(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_ARyzenBaseCharacter(); \
public: \
	DECLARE_CLASS(ARyzenBaseCharacter, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(ARyzenBaseCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_Public_Player_RyzenBaseCharacter_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARyzenBaseCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARyzenBaseCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARyzenBaseCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARyzenBaseCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARyzenBaseCharacter(ARyzenBaseCharacter&&); \
	NO_API ARyzenBaseCharacter(const ARyzenBaseCharacter&); \
public:


#define Ryzen_Source_Ryzen_Public_Player_RyzenBaseCharacter_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARyzenBaseCharacter(ARyzenBaseCharacter&&); \
	NO_API ARyzenBaseCharacter(const ARyzenBaseCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARyzenBaseCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARyzenBaseCharacter); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARyzenBaseCharacter)


#define Ryzen_Source_Ryzen_Public_Player_RyzenBaseCharacter_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Health() { return STRUCT_OFFSET(ARyzenBaseCharacter, Health); }


#define Ryzen_Source_Ryzen_Public_Player_RyzenBaseCharacter_h_10_PROLOG
#define Ryzen_Source_Ryzen_Public_Player_RyzenBaseCharacter_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_Public_Player_RyzenBaseCharacter_h_13_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_Public_Player_RyzenBaseCharacter_h_13_RPC_WRAPPERS \
	Ryzen_Source_Ryzen_Public_Player_RyzenBaseCharacter_h_13_INCLASS \
	Ryzen_Source_Ryzen_Public_Player_RyzenBaseCharacter_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Ryzen_Source_Ryzen_Public_Player_RyzenBaseCharacter_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_Public_Player_RyzenBaseCharacter_h_13_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_Public_Player_RyzenBaseCharacter_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_Public_Player_RyzenBaseCharacter_h_13_INCLASS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_Public_Player_RyzenBaseCharacter_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Ryzen_Source_Ryzen_Public_Player_RyzenBaseCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
