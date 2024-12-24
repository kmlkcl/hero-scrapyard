// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HS_ItemConfig.generated.h"

enum class EHS_ItemType : uint8;
enum class EHS_Rarity : uint8;
enum class EHS_CharacterClass : uint8;

/**
 * 
 */
USTRUCT(BlueprintType)
struct HEROSCRAPYARD_API FHS_ItemConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EHS_ItemType ItemType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EHS_Rarity Rarity;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DamageMin;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DamageMax;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CritChance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CritFactor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MightFactor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float InitiativeTimeCost;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MightBonus;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DexterityBonus;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DefenseBonus;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<EHS_CharacterClass> WearableBy;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bHasBasicAttack;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bHasOtherActions;

};
