// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RYZEN_PlayerHUD_generated_h
#error "PlayerHUD.generated.h already included, missing '#pragma once' in PlayerHUD.h"
#endif
#define RYZEN_PlayerHUD_generated_h

#define Ryzen_Source_Ryzen_Public_UI_PlayerHUD_h_11_RPC_WRAPPERS
#define Ryzen_Source_Ryzen_Public_UI_PlayerHUD_h_11_RPC_WRAPPERS_NO_PURE_DECLS
#define Ryzen_Source_Ryzen_Public_UI_PlayerHUD_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlayerHUD(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_APlayerHUD(); \
public: \
	DECLARE_CLASS(APlayerHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(APlayerHUD) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_Public_UI_PlayerHUD_h_11_INCLASS \
private: \
	static void StaticRegisterNativesAPlayerHUD(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_APlayerHUD(); \
public: \
	DECLARE_CLASS(APlayerHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(APlayerHUD) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_Public_UI_PlayerHUD_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlayerHUD(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlayerHUD) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerHUD); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerHUD(APlayerHUD&&); \
	NO_API APlayerHUD(const APlayerHUD&); \
public:


#define Ryzen_Source_Ryzen_Public_UI_PlayerHUD_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerHUD(APlayerHUD&&); \
	NO_API APlayerHUD(const APlayerHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerHUD); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlayerHUD)


#define Ryzen_Source_Ryzen_Public_UI_PlayerHUD_h_11_PRIVATE_PROPERTY_OFFSET
#define Ryzen_Source_Ryzen_Public_UI_PlayerHUD_h_8_PROLOG
#define Ryzen_Source_Ryzen_Public_UI_PlayerHUD_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_Public_UI_PlayerHUD_h_11_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_Public_UI_PlayerHUD_h_11_RPC_WRAPPERS \
	Ryzen_Source_Ryzen_Public_UI_PlayerHUD_h_11_INCLASS \
	Ryzen_Source_Ryzen_Public_UI_PlayerHUD_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Ryzen_Source_Ryzen_Public_UI_PlayerHUD_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_Public_UI_PlayerHUD_h_11_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_Public_UI_PlayerHUD_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_Public_UI_PlayerHUD_h_11_INCLASS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_Public_UI_PlayerHUD_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Ryzen_Source_Ryzen_Public_UI_PlayerHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
