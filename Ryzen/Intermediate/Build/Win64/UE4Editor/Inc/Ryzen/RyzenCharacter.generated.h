// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RYZEN_RyzenCharacter_generated_h
#error "RyzenCharacter.generated.h already included, missing '#pragma once' in RyzenCharacter.h"
#endif
#define RYZEN_RyzenCharacter_generated_h

#define Ryzen_Source_Ryzen_RyzenCharacter_h_12_RPC_WRAPPERS
#define Ryzen_Source_Ryzen_RyzenCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define Ryzen_Source_Ryzen_RyzenCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARyzenCharacter(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_ARyzenCharacter(); \
public: \
	DECLARE_CLASS(ARyzenCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(ARyzenCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_RyzenCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesARyzenCharacter(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_ARyzenCharacter(); \
public: \
	DECLARE_CLASS(ARyzenCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(ARyzenCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_RyzenCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARyzenCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARyzenCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARyzenCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARyzenCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARyzenCharacter(ARyzenCharacter&&); \
	NO_API ARyzenCharacter(const ARyzenCharacter&); \
public:


#define Ryzen_Source_Ryzen_RyzenCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARyzenCharacter(ARyzenCharacter&&); \
	NO_API ARyzenCharacter(const ARyzenCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARyzenCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARyzenCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ARyzenCharacter)


#define Ryzen_Source_Ryzen_RyzenCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(ARyzenCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(ARyzenCharacter, FollowCamera); } \
	FORCEINLINE static uint32 __PPO__CollectionSphere() { return STRUCT_OFFSET(ARyzenCharacter, CollectionSphere); }


#define Ryzen_Source_Ryzen_RyzenCharacter_h_9_PROLOG
#define Ryzen_Source_Ryzen_RyzenCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_RyzenCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_RyzenCharacter_h_12_RPC_WRAPPERS \
	Ryzen_Source_Ryzen_RyzenCharacter_h_12_INCLASS \
	Ryzen_Source_Ryzen_RyzenCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Ryzen_Source_Ryzen_RyzenCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_RyzenCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_RyzenCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_RyzenCharacter_h_12_INCLASS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_RyzenCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Ryzen_Source_Ryzen_RyzenCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
