// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RYZEN_Waypoint_generated_h
#error "Waypoint.generated.h already included, missing '#pragma once' in Waypoint.h"
#endif
#define RYZEN_Waypoint_generated_h

#define Ryzen_Source_Ryzen_Public_Zombie_Waypoint_h_15_RPC_WRAPPERS
#define Ryzen_Source_Ryzen_Public_Zombie_Waypoint_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define Ryzen_Source_Ryzen_Public_Zombie_Waypoint_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAWaypoint(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_AWaypoint(); \
public: \
	DECLARE_CLASS(AWaypoint, ATargetPoint, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(AWaypoint) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_Public_Zombie_Waypoint_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAWaypoint(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_AWaypoint(); \
public: \
	DECLARE_CLASS(AWaypoint, ATargetPoint, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(AWaypoint) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_Public_Zombie_Waypoint_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AWaypoint(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AWaypoint) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWaypoint); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWaypoint); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWaypoint(AWaypoint&&); \
	NO_API AWaypoint(const AWaypoint&); \
public:


#define Ryzen_Source_Ryzen_Public_Zombie_Waypoint_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AWaypoint(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWaypoint(AWaypoint&&); \
	NO_API AWaypoint(const AWaypoint&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWaypoint); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWaypoint); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AWaypoint)


#define Ryzen_Source_Ryzen_Public_Zombie_Waypoint_h_15_PRIVATE_PROPERTY_OFFSET
#define Ryzen_Source_Ryzen_Public_Zombie_Waypoint_h_12_PROLOG
#define Ryzen_Source_Ryzen_Public_Zombie_Waypoint_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_Public_Zombie_Waypoint_h_15_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_Public_Zombie_Waypoint_h_15_RPC_WRAPPERS \
	Ryzen_Source_Ryzen_Public_Zombie_Waypoint_h_15_INCLASS \
	Ryzen_Source_Ryzen_Public_Zombie_Waypoint_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Ryzen_Source_Ryzen_Public_Zombie_Waypoint_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_Public_Zombie_Waypoint_h_15_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_Public_Zombie_Waypoint_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_Public_Zombie_Waypoint_h_15_INCLASS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_Public_Zombie_Waypoint_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Ryzen_Source_Ryzen_Public_Zombie_Waypoint_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
