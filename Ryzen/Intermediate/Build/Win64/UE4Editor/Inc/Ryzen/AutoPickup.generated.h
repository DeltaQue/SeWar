// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APlayerController;
#ifdef RYZEN_AutoPickup_generated_h
#error "AutoPickup.generated.h already included, missing '#pragma once' in AutoPickup.h"
#endif
#define RYZEN_AutoPickup_generated_h

#define Ryzen_Source_Ryzen_AutoPickup_h_12_RPC_WRAPPERS \
	virtual void Collect_Implementation(APlayerController* Controller); \
 \
	DECLARE_FUNCTION(execCollect) \
	{ \
		P_GET_OBJECT(APlayerController,Z_Param_Controller); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Collect_Implementation(Z_Param_Controller); \
		P_NATIVE_END; \
	}


#define Ryzen_Source_Ryzen_AutoPickup_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCollect) \
	{ \
		P_GET_OBJECT(APlayerController,Z_Param_Controller); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Collect_Implementation(Z_Param_Controller); \
		P_NATIVE_END; \
	}


#define Ryzen_Source_Ryzen_AutoPickup_h_12_EVENT_PARMS \
	struct AutoPickup_eventCollect_Parms \
	{ \
		APlayerController* Controller; \
	};


#define Ryzen_Source_Ryzen_AutoPickup_h_12_CALLBACK_WRAPPERS
#define Ryzen_Source_Ryzen_AutoPickup_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAutoPickup(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_AAutoPickup(); \
public: \
	DECLARE_CLASS(AAutoPickup, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(AAutoPickup) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_AutoPickup_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAAutoPickup(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_AAutoPickup(); \
public: \
	DECLARE_CLASS(AAutoPickup, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(AAutoPickup) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_AutoPickup_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AAutoPickup(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AAutoPickup) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAutoPickup); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAutoPickup); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAutoPickup(AAutoPickup&&); \
	NO_API AAutoPickup(const AAutoPickup&); \
public:


#define Ryzen_Source_Ryzen_AutoPickup_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAutoPickup(AAutoPickup&&); \
	NO_API AAutoPickup(const AAutoPickup&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAutoPickup); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAutoPickup); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AAutoPickup)


#define Ryzen_Source_Ryzen_AutoPickup_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__PickupMesh() { return STRUCT_OFFSET(AAutoPickup, PickupMesh); } \
	FORCEINLINE static uint32 __PPO__ItemID() { return STRUCT_OFFSET(AAutoPickup, ItemID); }


#define Ryzen_Source_Ryzen_AutoPickup_h_9_PROLOG \
	Ryzen_Source_Ryzen_AutoPickup_h_12_EVENT_PARMS


#define Ryzen_Source_Ryzen_AutoPickup_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_AutoPickup_h_12_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_AutoPickup_h_12_RPC_WRAPPERS \
	Ryzen_Source_Ryzen_AutoPickup_h_12_CALLBACK_WRAPPERS \
	Ryzen_Source_Ryzen_AutoPickup_h_12_INCLASS \
	Ryzen_Source_Ryzen_AutoPickup_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Ryzen_Source_Ryzen_AutoPickup_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_AutoPickup_h_12_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_AutoPickup_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_AutoPickup_h_12_CALLBACK_WRAPPERS \
	Ryzen_Source_Ryzen_AutoPickup_h_12_INCLASS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_AutoPickup_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Ryzen_Source_Ryzen_AutoPickup_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
