// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HS_Effect.h"
#include "HS_Action.generated.h"


USTRUCT(BlueprintType)
struct HEROSCRAPYARD_API FHS_EffectTargets
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 EffectIndex;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<int32> TargetIndices;
};

/**
 *
 */
USTRUCT(BlueprintType)
struct HEROSCRAPYARD_API FHS_Action
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Description;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FHS_Effect> Effects;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FHS_EffectTargets> EffectTargets;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TimeCost;
};
