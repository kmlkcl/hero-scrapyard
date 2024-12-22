// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HS_Race.generated.h"

UENUM(BlueprintType)
enum class EHS_Race : uint8
{
	Human = 0 UMETA(DisplayName = "Human"),
	Elf = 1 UMETA(DisplayName = "Elf"),
	Dwarf = 2 UMETA(DisplayName = "Dwarf"),
	Orc = 3 UMETA(DisplayName = "Orc")
};

/**
 * 
 */
USTRUCT(BlueprintType)
struct HEROSCRAPYARD_API FHS_RaceConfig
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EHS_Race Race;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MightModifierMin;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MightModifierMax;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DexterityModifierMin;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DexterityModifierMax;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DefenseModifierMin;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DefenseModifierMax;

};
