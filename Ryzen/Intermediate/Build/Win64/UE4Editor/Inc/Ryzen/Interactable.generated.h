// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APlayerController;
#ifdef RYZEN_Interactable_generated_h
#error "Interactable.generated.h already included, missing '#pragma once' in Interactable.h"
#endif
#define RYZEN_Interactable_generated_h

#define Ryzen_Source_Ryzen_Interactable_h_12_RPC_WRAPPERS \
	virtual void Interact_Implementation(APlayerController* Controller); \
 \
	DECLARE_FUNCTION(execGetInteractText) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetInteractText(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInteract) \
	{ \
		P_GET_OBJECT(APlayerController,Z_Param_Controller); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Interact_Implementation(Z_Param_Controller); \
		P_NATIVE_END; \
	}


#define Ryzen_Source_Ryzen_Interactable_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetInteractText) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetInteractText(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInteract) \
	{ \
		P_GET_OBJECT(APlayerController,Z_Param_Controller); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Interact_Implementation(Z_Param_Controller); \
		P_NATIVE_END; \
	}


#define Ryzen_Source_Ryzen_Interactable_h_12_EVENT_PARMS \
	struct Interactable_eventInteract_Parms \
	{ \
		APlayerController* Controller; \
	};


#define Ryzen_Source_Ryzen_Interactable_h_12_CALLBACK_WRAPPERS
#define Ryzen_Source_Ryzen_Interactable_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAInteractable(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_AInteractable(); \
public: \
	DECLARE_CLASS(AInteractable, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(AInteractable) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_Interactable_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAInteractable(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_AInteractable(); \
public: \
	DECLARE_CLASS(AInteractable, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(AInteractable) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_Interactable_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AInteractable(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AInteractable) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AInteractable); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AInteractable); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AInteractable(AInteractable&&); \
	NO_API AInteractable(const AInteractable&); \
public:


#define Ryzen_Source_Ryzen_Interactable_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AInteractable(AInteractable&&); \
	NO_API AInteractable(const AInteractable&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AInteractable); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AInteractable); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AInteractable)


#define Ryzen_Source_Ryzen_Interactable_h_12_PRIVATE_PROPERTY_OFFSET
#define Ryzen_Source_Ryzen_Interactable_h_9_PROLOG \
	Ryzen_Source_Ryzen_Interactable_h_12_EVENT_PARMS


#define Ryzen_Source_Ryzen_Interactable_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_Interactable_h_12_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_Interactable_h_12_RPC_WRAPPERS \
	Ryzen_Source_Ryzen_Interactable_h_12_CALLBACK_WRAPPERS \
	Ryzen_Source_Ryzen_Interactable_h_12_INCLASS \
	Ryzen_Source_Ryzen_Interactable_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Ryzen_Source_Ryzen_Interactable_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_Interactable_h_12_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_Interactable_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_Interactable_h_12_CALLBACK_WRAPPERS \
	Ryzen_Source_Ryzen_Interactable_h_12_INCLASS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_Interactable_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Ryzen_Source_Ryzen_Interactable_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
