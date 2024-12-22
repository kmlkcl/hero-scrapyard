// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EHS_Rarity : uint8
{
	Common = 0 UMETA(DisplayName = "Common"),
	Uncommon = 1 UMETA(DisplayName = "Uncommon"),
	Rare = 2 UMETA(DisplayName = "Rare"),
	Epic = 3 UMETA(DisplayName = "Epic")
};
