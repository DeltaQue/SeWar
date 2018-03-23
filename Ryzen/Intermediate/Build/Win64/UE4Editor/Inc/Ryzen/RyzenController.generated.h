// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RYZEN_RyzenController_generated_h
#error "RyzenController.generated.h already included, missing '#pragma once' in RyzenController.h"
#endif
#define RYZEN_RyzenController_generated_h

#define Ryzen_Source_Ryzen_RyzenController_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAddItemToInventoryByID) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_ID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->AddItemToInventoryByID(Z_Param_ID); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetInventoryWeight) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetInventoryWeight(); \
		P_NATIVE_END; \
	}


#define Ryzen_Source_Ryzen_RyzenController_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAddItemToInventoryByID) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_ID); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->AddItemToInventoryByID(Z_Param_ID); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetInventoryWeight) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetInventoryWeight(); \
		P_NATIVE_END; \
	}


#define Ryzen_Source_Ryzen_RyzenController_h_17_EVENT_PARMS
#define Ryzen_Source_Ryzen_RyzenController_h_17_CALLBACK_WRAPPERS
#define Ryzen_Source_Ryzen_RyzenController_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARyzenController(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_ARyzenController(); \
public: \
	DECLARE_CLASS(ARyzenController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(ARyzenController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_RyzenController_h_17_INCLASS \
private: \
	static void StaticRegisterNativesARyzenController(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_ARyzenController(); \
public: \
	DECLARE_CLASS(ARyzenController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(ARyzenController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_RyzenController_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARyzenController(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARyzenController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARyzenController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARyzenController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARyzenController(ARyzenController&&); \
	NO_API ARyzenController(const ARyzenController&); \
public:


#define Ryzen_Source_Ryzen_RyzenController_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARyzenController(ARyzenController&&); \
	NO_API ARyzenController(const ARyzenController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARyzenController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARyzenController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ARyzenController)


#define Ryzen_Source_Ryzen_RyzenController_h_17_PRIVATE_PROPERTY_OFFSET
#define Ryzen_Source_Ryzen_RyzenController_h_14_PROLOG \
	Ryzen_Source_Ryzen_RyzenController_h_17_EVENT_PARMS


#define Ryzen_Source_Ryzen_RyzenController_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_RyzenController_h_17_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_RyzenController_h_17_RPC_WRAPPERS \
	Ryzen_Source_Ryzen_RyzenController_h_17_CALLBACK_WRAPPERS \
	Ryzen_Source_Ryzen_RyzenController_h_17_INCLASS \
	Ryzen_Source_Ryzen_RyzenController_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Ryzen_Source_Ryzen_RyzenController_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_RyzenController_h_17_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_RyzenController_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_RyzenController_h_17_CALLBACK_WRAPPERS \
	Ryzen_Source_Ryzen_RyzenController_h_17_INCLASS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_RyzenController_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Ryzen_Source_Ryzen_RyzenController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
