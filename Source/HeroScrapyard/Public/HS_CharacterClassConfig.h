// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HS_CharacterClass.h"
#include "HS_CharacterStats.h"
#include "HS_Rarity.h"
#include "HS_CharacterClassConfig.generated.h"

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
};