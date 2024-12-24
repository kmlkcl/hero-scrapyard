// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HS_Effect.h"
#include "HS_ConsumeableConfig.generated.h"

enum class EHS_Rarity : uint8;

/**
 * 
 */
USTRUCT(BlueprintType)
struct HEROSCRAPYARD_API FHS_ConsumeableConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Description;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EHS_Rarity Rarity;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FHS_Effect> Effects;
};
