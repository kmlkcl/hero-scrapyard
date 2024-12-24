// Fill out your copyright notice in the Description page of Project Settings.

#include "HS_GameMode.h"
#include "HS_AIController.h"
#include "HS_Pawn.h"
#include "HS_Race.h"
#include "HS_CharacterClassConfig.h"

void AHS_GameMode::StartGame() const
{
    // Create starting hero count amount of HS_Pawn for player and AI randomly

    if(CharacterConfigs.Num() == 0 || Races.Num() == 0)
    {
        UE_LOG(LogTemp, Error, TEXT("GameMode has no CharacterConfigs or Races"));
        return;
    }

    AHS_AIController* AIController = GetWorld()->SpawnActor<AHS_AIController>(AHS_AIController::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);
    
    for (int32 i = 0; i < StartingHeroCount * 2; i++)
    {
        int32 RandomCharacterClassConfigIndex = FMath::RandRange(0, CharacterConfigs.Num() - 1);
        int32 RandomRaceConfigIndex = FMath::RandRange(0, Races.Num() - 1);

        AHS_Pawn* NewPawn = GetWorld()->SpawnActor<AHS_Pawn>(DefaultPawnClass, FVector::ZeroVector, FRotator::ZeroRotator);

        const FHS_CharacterClassConfig& CharacterConfig = CharacterConfigs[RandomCharacterClassConfigIndex];
        const FHS_RaceConfig& RaceConfig = Races[RandomRaceConfigIndex];

        NewPawn->InitializePawn(1, CharacterConfig, RaceConfig); 
    }
}