// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EHS_ItemType : uint8
{
	Armor = 0 UMETA(DisplayName = "Armor"),
	Shield = 1 UMETA(DisplayName = "Shield"),
	Weapon1H = 2 UMETA(DisplayName = "One Handed Weapon"),
	Weapon2H = 3 UMETA(DisplayName = "Two Handed Weapon"),
	Consumable = 4 UMETA(DisplayName = "Consumable")
};
