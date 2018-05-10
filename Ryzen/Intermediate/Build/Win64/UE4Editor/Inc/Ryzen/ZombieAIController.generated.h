// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RYZEN_ZombieAIController_generated_h
#error "ZombieAIController.generated.h already included, missing '#pragma once' in ZombieAIController.h"
#endif
#define RYZEN_ZombieAIController_generated_h

#define Ryzen_Source_Ryzen_Public_Zombie_ZombieAIController_h_18_RPC_WRAPPERS
#define Ryzen_Source_Ryzen_Public_Zombie_ZombieAIController_h_18_RPC_WRAPPERS_NO_PURE_DECLS
#define Ryzen_Source_Ryzen_Public_Zombie_ZombieAIController_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZombieAIController(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_AZombieAIController(); \
public: \
	DECLARE_CLASS(AZombieAIController, AAIController, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(AZombieAIController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define Ryzen_Source_Ryzen_Public_Zombie_ZombieAIController_h_18_INCLASS \
private: \
	static void StaticRegisterNativesAZombieAIController(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_AZombieAIController(); \
public: \
	DECLARE_CLASS(AZombieAIController, AAIController, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(AZombieAIController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define Ryzen_Source_Ryzen_Public_Zombie_ZombieAIController_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AZombieAIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AZombieAIController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZombieAIController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZombieAIController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZombieAIController(AZombieAIController&&); \
	NO_API AZombieAIController(const AZombieAIController&); \
public:


#define Ryzen_Source_Ryzen_Public_Zombie_ZombieAIController_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZombieAIController(AZombieAIController&&); \
	NO_API AZombieAIController(const AZombieAIController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZombieAIController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZombieAIController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AZombieAIController)


#define Ryzen_Source_Ryzen_Public_Zombie_ZombieAIController_h_18_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__TargetEnemyKeyName() { return STRUCT_OFFSET(AZombieAIController, TargetEnemyKeyName); } \
	FORCEINLINE static uint32 __PPO__PatrolLocationKeyName() { return STRUCT_OFFSET(AZombieAIController, PatrolLocationKeyName); } \
	FORCEINLINE static uint32 __PPO__CurrentWaypointKeyName() { return STRUCT_OFFSET(AZombieAIController, CurrentWaypointKeyName); } \
	FORCEINLINE static uint32 __PPO__BotTypeKeyName() { return STRUCT_OFFSET(AZombieAIController, BotTypeKeyName); } \
	FORCEINLINE static uint32 __PPO__ReconnaissanceLocationKeyName() { return STRUCT_OFFSET(AZombieAIController, ReconnaissanceLocationKeyName); }


#define Ryzen_Source_Ryzen_Public_Zombie_ZombieAIController_h_15_PROLOG
#define Ryzen_Source_Ryzen_Public_Zombie_ZombieAIController_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_Public_Zombie_ZombieAIController_h_18_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_Public_Zombie_ZombieAIController_h_18_RPC_WRAPPERS \
	Ryzen_Source_Ryzen_Public_Zombie_ZombieAIController_h_18_INCLASS \
	Ryzen_Source_Ryzen_Public_Zombie_ZombieAIController_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Ryzen_Source_Ryzen_Public_Zombie_ZombieAIController_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_Public_Zombie_ZombieAIController_h_18_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_Public_Zombie_ZombieAIController_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_Public_Zombie_ZombieAIController_h_18_INCLASS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_Public_Zombie_ZombieAIController_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Ryzen_Source_Ryzen_Public_Zombie_ZombieAIController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
