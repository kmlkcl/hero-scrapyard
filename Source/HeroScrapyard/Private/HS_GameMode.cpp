// Fill out your copyright notice in the Description page of Project Settings.

#include "HS_GameMode.h"
#include "HS_Pawn.h"
#include "HS_CharacterClassConfig.h"

void AHS_GameMode::StartGame() const
{
    // Create starting hero count amount of HS_Pawn for player and AI randomly

    for (int32 i = 0; i < StartingHeroCount * 2; i++)
    {
        int32 RandomCharacterClassConfigIndex = FMath::RandRange(0, CharacterConfigs.Num() - 1);
        int32 RandomRaceConfigIndex = FMath::RandRange(0, Races.Num() - 1);

        AHS_Pawn* NewPawn = GetWorld()->SpawnActor<AHS_Pawn>(AHS_Pawn::StaticClass());

        const FHS_CharacterClassConfig& CharacterConfig = CharacterConfigs[RandomCharacterClassConfigIndex];
    }
}