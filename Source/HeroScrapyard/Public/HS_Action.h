// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HS_Effect.h"
#include "HS_Action.generated.h"
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
	float TimeCost;
};
