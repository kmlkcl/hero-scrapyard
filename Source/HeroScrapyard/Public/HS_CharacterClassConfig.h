// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HS_CharacterStats.h"
#include "HS_Action.h"
#include "HS_CharacterClassConfig.generated.h"

enum class EHS_CharacterClass : uint8;
enum class EHS_Rarity : uint8;

/**
 *
 */
USTRUCT(BlueprintType)
struct HEROSCRAPYARD_API FHS_CharacterClassConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EHS_CharacterClass CharacterClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EHS_Rarity Rarity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FHS_CharacterStats CharacterStats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MightGrowth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DexterityGrowth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DefenseGrowth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HPGrowthMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HPGrowthMax;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FHS_Action> Actions;
};
