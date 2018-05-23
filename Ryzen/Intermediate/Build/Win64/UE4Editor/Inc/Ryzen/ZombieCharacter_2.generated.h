// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAnimMontage;
class UAnimInstance;
class APawn;
struct FVector;
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef RYZEN_ZombieCharacter_2_generated_h
#error "ZombieCharacter_2.generated.h already included, missing '#pragma once' in ZombieCharacter_2.h"
#endif
#define RYZEN_ZombieCharacter_2_generated_h

#define Ryzen_Source_Ryzen_Public_Zombie_ZombieCharacter_2_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetAttackAnimMontage) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAnimMontage**)Z_Param__Result=P_THIS->GetAttackAnimMontage(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAttackAnimInstance) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAnimInstance**)Z_Param__Result=P_THIS->GetAttackAnimInstance(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetOverlapAttackCollision) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetOverlapAttackCollision(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnHearNoise) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_PawnInstigator); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHearNoise(Z_Param_PawnInstigator,Z_Param_Out_Location,Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnSeePlayer) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_pawn); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnSeePlayer(Z_Param_pawn); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnAttackCollisionCompEndOverlap) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnAttackCollisionCompEndOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnAttackCollisionCompBeginOverlap) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnAttackCollisionCompBeginOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define Ryzen_Source_Ryzen_Public_Zombie_ZombieCharacter_2_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetAttackAnimMontage) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAnimMontage**)Z_Param__Result=P_THIS->GetAttackAnimMontage(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAttackAnimInstance) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAnimInstance**)Z_Param__Result=P_THIS->GetAttackAnimInstance(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetOverlapAttackCollision) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetOverlapAttackCollision(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnHearNoise) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_PawnInstigator); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Volume); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHearNoise(Z_Param_PawnInstigator,Z_Param_Out_Location,Z_Param_Volume); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnSeePlayer) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_pawn); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnSeePlayer(Z_Param_pawn); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnAttackCollisionCompEndOverlap) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnAttackCollisionCompEndOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnAttackCollisionCompBeginOverlap) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnAttackCollisionCompBeginOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define Ryzen_Source_Ryzen_Public_Zombie_ZombieCharacter_2_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZombieCharacter_2(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_AZombieCharacter_2(); \
public: \
	DECLARE_CLASS(AZombieCharacter_2, ARyzenBaseCharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(AZombieCharacter_2) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_Public_Zombie_ZombieCharacter_2_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAZombieCharacter_2(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_AZombieCharacter_2(); \
public: \
	DECLARE_CLASS(AZombieCharacter_2, ARyzenBaseCharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(AZombieCharacter_2) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_Public_Zombie_ZombieCharacter_2_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AZombieCharacter_2(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AZombieCharacter_2) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZombieCharacter_2); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZombieCharacter_2); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZombieCharacter_2(AZombieCharacter_2&&); \
	NO_API AZombieCharacter_2(const AZombieCharacter_2&); \
public:


#define Ryzen_Source_Ryzen_Public_Zombie_ZombieCharacter_2_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZombieCharacter_2(AZombieCharacter_2&&); \
	NO_API AZombieCharacter_2(const AZombieCharacter_2&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZombieCharacter_2); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZombieCharacter_2); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AZombieCharacter_2)


#define Ryzen_Source_Ryzen_Public_Zombie_ZombieCharacter_2_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__PawnSensingComp() { return STRUCT_OFFSET(AZombieCharacter_2, PawnSensingComp); } \
	FORCEINLINE static uint32 __PPO__SightSenseTimeOut() { return STRUCT_OFFSET(AZombieCharacter_2, SightSenseTimeOut); } \
	FORCEINLINE static uint32 __PPO__HearingSenseTimeOut() { return STRUCT_OFFSET(AZombieCharacter_2, HearingSenseTimeOut); } \
	FORCEINLINE static uint32 __PPO__AttackCollisionComp() { return STRUCT_OFFSET(AZombieCharacter_2, AttackCollisionComp); } \
	FORCEINLINE static uint32 __PPO__AttackAnimMontage() { return STRUCT_OFFSET(AZombieCharacter_2, AttackAnimMontage); } \
	FORCEINLINE static uint32 __PPO__AnimInstance() { return STRUCT_OFFSET(AZombieCharacter_2, AnimInstance); }


#define Ryzen_Source_Ryzen_Public_Zombie_ZombieCharacter_2_h_10_PROLOG
#define Ryzen_Source_Ryzen_Public_Zombie_ZombieCharacter_2_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_Public_Zombie_ZombieCharacter_2_h_13_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_Public_Zombie_ZombieCharacter_2_h_13_RPC_WRAPPERS \
	Ryzen_Source_Ryzen_Public_Zombie_ZombieCharacter_2_h_13_INCLASS \
	Ryzen_Source_Ryzen_Public_Zombie_ZombieCharacter_2_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Ryzen_Source_Ryzen_Public_Zombie_ZombieCharacter_2_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_Public_Zombie_ZombieCharacter_2_h_13_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_Public_Zombie_ZombieCharacter_2_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_Public_Zombie_ZombieCharacter_2_h_13_INCLASS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_Public_Zombie_ZombieCharacter_2_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Ryzen_Source_Ryzen_Public_Zombie_ZombieCharacter_2_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
