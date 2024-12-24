// Fill out your copyright notice in the Description page of Project Settings.

#include "HS_AIController.h"
#include "HS_GameMode.h"
#include "HS_PlayerState.h"

void AHS_AIController::BeginPlay()
{
    Super::BeginPlay();

    AHS_GameMode *GameMode = Cast<AHS_GameMode>(GetWorld()->GetAuthGameMode());

    if (GameMode)
    {
        HSPlayerState = GetWorld()->SpawnActor<AHS_PlayerState>(GameMode->PlayerStateClass, FVector::ZeroVector, FRotator::ZeroRotator);
    }
}