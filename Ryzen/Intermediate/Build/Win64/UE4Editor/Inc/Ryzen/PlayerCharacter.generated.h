// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RYZEN_PlayerCharacter_generated_h
#error "PlayerCharacter.generated.h already included, missing '#pragma once' in PlayerCharacter.h"
#endif
#define RYZEN_PlayerCharacter_generated_h

#define Ryzen_Source_Ryzen_Public_Player_PlayerCharacter_h_15_RPC_WRAPPERS
#define Ryzen_Source_Ryzen_Public_Player_PlayerCharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define Ryzen_Source_Ryzen_Public_Player_PlayerCharacter_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlayerCharacter(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_APlayerCharacter(); \
public: \
	DECLARE_CLASS(APlayerCharacter, ARyzenBaseCharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(APlayerCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define Ryzen_Source_Ryzen_Public_Player_PlayerCharacter_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAPlayerCharacter(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_APlayerCharacter(); \
public: \
	DECLARE_CLASS(APlayerCharacter, ARyzenBaseCharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(APlayerCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define Ryzen_Source_Ryzen_Public_Player_PlayerCharacter_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlayerCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlayerCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerCharacter(APlayerCharacter&&); \
	NO_API APlayerCharacter(const APlayerCharacter&); \
public:


#define Ryzen_Source_Ryzen_Public_Player_PlayerCharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerCharacter(APlayerCharacter&&); \
	NO_API APlayerCharacter(const APlayerCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerCharacter); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlayerCharacter)


#define Ryzen_Source_Ryzen_Public_Player_PlayerCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(APlayerCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(APlayerCharacter, FollowCamera); } \
	FORCEINLINE static uint32 __PPO__CollectionSphere() { return STRUCT_OFFSET(APlayerCharacter, CollectionSphere); } \
	FORCEINLINE static uint32 __PPO__MuzzleLocation() { return STRUCT_OFFSET(APlayerCharacter, MuzzleLocation); }


#define Ryzen_Source_Ryzen_Public_Player_PlayerCharacter_h_12_PROLOG
#define Ryzen_Source_Ryzen_Public_Player_PlayerCharacter_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_Public_Player_PlayerCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_Public_Player_PlayerCharacter_h_15_RPC_WRAPPERS \
	Ryzen_Source_Ryzen_Public_Player_PlayerCharacter_h_15_INCLASS \
	Ryzen_Source_Ryzen_Public_Player_PlayerCharacter_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Ryzen_Source_Ryzen_Public_Player_PlayerCharacter_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_Public_Player_PlayerCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_Public_Player_PlayerCharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_Public_Player_PlayerCharacter_h_15_INCLASS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_Public_Player_PlayerCharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Ryzen_Source_Ryzen_Public_Player_PlayerCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
