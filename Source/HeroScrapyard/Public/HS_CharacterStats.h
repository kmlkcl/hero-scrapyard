// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HS_CharacterStats.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct HEROSCRAPYARD_API FHS_CharacterStats
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxHP;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CurrentHP;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Might;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Dexterity;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Defense;

};
