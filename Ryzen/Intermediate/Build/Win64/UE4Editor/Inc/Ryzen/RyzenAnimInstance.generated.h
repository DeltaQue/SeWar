// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RYZEN_RyzenAnimInstance_generated_h
#error "RyzenAnimInstance.generated.h already included, missing '#pragma once' in RyzenAnimInstance.h"
#endif
#define RYZEN_RyzenAnimInstance_generated_h

#define Ryzen_Source_Ryzen_RyzenAnimInstance_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execUpdateAnimationProperties) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateAnimationProperties(); \
		P_NATIVE_END; \
	}


#define Ryzen_Source_Ryzen_RyzenAnimInstance_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execUpdateAnimationProperties) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->UpdateAnimationProperties(); \
		P_NATIVE_END; \
	}


#define Ryzen_Source_Ryzen_RyzenAnimInstance_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURyzenAnimInstance(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_URyzenAnimInstance(); \
public: \
	DECLARE_CLASS(URyzenAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(URyzenAnimInstance) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_RyzenAnimInstance_h_15_INCLASS \
private: \
	static void StaticRegisterNativesURyzenAnimInstance(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_URyzenAnimInstance(); \
public: \
	DECLARE_CLASS(URyzenAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(URyzenAnimInstance) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_RyzenAnimInstance_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URyzenAnimInstance(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URyzenAnimInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URyzenAnimInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URyzenAnimInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URyzenAnimInstance(URyzenAnimInstance&&); \
	NO_API URyzenAnimInstance(const URyzenAnimInstance&); \
public:


#define Ryzen_Source_Ryzen_RyzenAnimInstance_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URyzenAnimInstance(URyzenAnimInstance&&); \
	NO_API URyzenAnimInstance(const URyzenAnimInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URyzenAnimInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URyzenAnimInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(URyzenAnimInstance)


#define Ryzen_Source_Ryzen_RyzenAnimInstance_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__bIsFalling() { return STRUCT_OFFSET(URyzenAnimInstance, bIsFalling); } \
	FORCEINLINE static uint32 __PPO__MovementSpeed() { return STRUCT_OFFSET(URyzenAnimInstance, MovementSpeed); }


#define Ryzen_Source_Ryzen_RyzenAnimInstance_h_12_PROLOG
#define Ryzen_Source_Ryzen_RyzenAnimInstance_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_RyzenAnimInstance_h_15_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_RyzenAnimInstance_h_15_RPC_WRAPPERS \
	Ryzen_Source_Ryzen_RyzenAnimInstance_h_15_INCLASS \
	Ryzen_Source_Ryzen_RyzenAnimInstance_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Ryzen_Source_Ryzen_RyzenAnimInstance_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_RyzenAnimInstance_h_15_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_RyzenAnimInstance_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_RyzenAnimInstance_h_15_INCLASS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_RyzenAnimInstance_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Ryzen_Source_Ryzen_RyzenAnimInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
