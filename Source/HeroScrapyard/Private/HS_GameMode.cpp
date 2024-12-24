// Fill out your copyright notice in the Description page of Project Settings.

#include "HS_GameMode.h"
#include "HS_AIController.h"
#include "HS_PlayerController.h"
#include "HS_PlayerState.h"
#include "HS_Pawn.h"
#include "HS_Race.h"
#include "HS_CharacterClassConfig.h"

void AHS_GameMode::StartGame() const
{
    // Create starting hero count amount of HS_Pawn for player and AI randomly

    if (CharacterConfigs.Num() == 0 || Races.Num() == 0)
    {
        UE_LOG(LogTemp, Error, TEXT("GameMode has no CharacterConfigs or Races"));
        return;
    }

    AHS_AIController *AIController = GetWorld()->SpawnActor<AHS_AIController>(AHS_AIController::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);
    AHS_PlayerState *AIHSPlayerState = AIController->GetHSPlayerState();

    AHS_PlayerController *HSPlayerController = Cast<AHS_PlayerController>(GetWorld()->GetFirstPlayerController());
    AHS_PlayerState *HSPlayerState = Cast<AHS_PlayerState>(HSPlayerController->PlayerState);

    int32 MaxInitRoll = 0;

    for (int32 i = 0; i < StartingHeroCount * 2; i++)
    {
        int32 RandomCharacterClassConfigIndex = FMath::RandRange(0, CharacterConfigs.Num() - 1);
        int32 RandomRaceConfigIndex = FMath::RandRange(0, Races.Num() - 1);

        AHS_Pawn *NewPawn = GetWorld()->SpawnActor<AHS_Pawn>(DefaultPawnClass, FVector::ZeroVector, FRotator::ZeroRotator);

        const FHS_CharacterClassConfig &CharacterConfig = CharacterConfigs[RandomCharacterClassConfigIndex];
        const FHS_RaceConfig &RaceConfig = Races[RandomRaceConfigIndex];

        int32 InitRoll = NewPawn->InitializePawn(1, CharacterConfig, RaceConfig);

        if (InitRoll > MaxInitRoll)
        {
            MaxInitRoll = InitRoll;
        }

        TObjectPtr<AHS_PlayerState> PState = i % 2 == 0 ? AIHSPlayerState : HSPlayerState;
        PState->AddPawn(NewPawn);
    }

    AIHSPlayerState->AddTimeDelayToPawns(-MaxInitRoll);
    HSPlayerState->AddTimeDelayToPawns(-MaxInitRoll);

}

TArray<FHS_ItemConfig> AHS_GameMode::ProduceRandomItems(int32 Count) const
{
    TArray<FHS_ItemConfig> RandomItems;
    
    for (int32 i = 0; i < Count; i++)
    {
        int32 RandomItemIndex = FMath::RandRange(0, ItemConfigs.Num() - 1);
        RandomItems.Add(ItemConfigs[RandomItemIndex]);
    }

    return RandomItems;
}