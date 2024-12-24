// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HS_GameMode.generated.h"

struct FHS_CharacterClassConfig;
struct FHS_ItemConfig;
struct FHS_ConsumeableConfig;
struct FHS_RaceConfig;

/**
 *
 */
UCLASS(Blueprintable)
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

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 StartingHeroCount;

public:
	UFUNCTION(BlueprintCallable)
	void StartGame() const;

};
