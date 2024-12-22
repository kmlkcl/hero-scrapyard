// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EHS_CharacterClass : uint8
{
	Fighter = 0 UMETA(DisplayName = "Fighter"),
	Barbarian = 1 UMETA(DisplayName = "Barbarian"),
	Cleric = 2 UMETA(DisplayName = "Cleric"),
	Rogue = 3 UMETA(DisplayName = "Rogue"),
	Wizard = 4 UMETA(DisplayName = "Wizard"),
	Ranger = 5 UMETA(DisplayName = "Ranger"),
	Druid = 6 UMETA(DisplayName = "Druid")
};
