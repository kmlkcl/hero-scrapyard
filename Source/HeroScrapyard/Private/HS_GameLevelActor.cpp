// Fill out your copyright notice in the Description page of Project Settings.


#include "HS_GameLevelActor.h"
#include "HS_GameMode.h"
#include "HS_ItemConfig.h"

void AHS_GameLevelActor::BeginPlay()
{
    Super::BeginPlay();

    HSGameMode = Cast<AHS_GameMode>(GetWorld()->GetAuthGameMode());

    if(!HSGameMode)
    {
        UE_LOG(LogTemp, Error, TEXT("HSGameMode is nullptr"));
        return;
    }

    HSGameMode->StartGame();
}

