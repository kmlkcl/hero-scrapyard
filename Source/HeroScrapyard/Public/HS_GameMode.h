// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HS_ItemConfig.h"
#include "HS_Race.h"
#include "HS_ConsumeableConfig.h"
#include "HS_CharacterClassConfig.h"
#include "HS_GameMode.generated.h"

/**
 *
 */
UCLASS()
class HEROSCRAPYARD_API AHS_GameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FHS_CharacterClassConfig> CharacterConfigs;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FHS_ItemConfig> ItemConfigs;	

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FHS_ConsumeableConfig> Consumeables;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FHS_RaceConfig> Races;
};
