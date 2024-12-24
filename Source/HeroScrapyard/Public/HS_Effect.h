// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HS_Effect.generated.h"

UENUM(BlueprintType)
enum class EHS_EffectSubject : uint8
{
	HP = 0 UMETA(DisplayName = "HP"),
	Initiative = 1 UMETA(DisplayName = "Initiative"),
	Defense = 2 UMETA(DisplayName = "Defense"),
	Might = 3 UMETA(DisplayName = "Might"),
	Dexterity = 4 UMETA(DisplayName = "Dexterity"),
	Damage = 5 UMETA(DisplayName = "Damage")
};

UENUM(BlueprintType)
enum class EHS_EffectTarget : uint8
{
	Self = 0 UMETA(DisplayName = "Self"),
	Ally = 1 UMETA(DisplayName = "Ally"),
	Enemy = 2 UMETA(DisplayName = "Enemy"),
	Any = 3 UMETA(DisplayName = "Any")
};

/**
 * 
 */
USTRUCT(BlueprintType)
struct HEROSCRAPYARD_API FHS_Effect
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EHS_EffectSubject Subject;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ValueMin;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ValueMax;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<float, EHS_EffectSubject> ModifierCalculations;	// 3.2 * Might, 0.5 * Dexterity, etc.

	// 0 means permanent
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Duration; 

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 TurnOffset;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<EHS_EffectTarget> Targets;
		
};
