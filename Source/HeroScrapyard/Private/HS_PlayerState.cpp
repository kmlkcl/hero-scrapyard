// Fill out your copyright notice in the Description page of Project Settings.


#include "HS_PlayerState.h"
#include "HS_Pawn.h"

int32 AHS_PlayerState::GetDivineFavorAmount() const
{
    return DivineFavorAmount;
}

int32 AHS_PlayerState::GetPawnCount(bool bIncludeDead) const
{
    int32 Count = 0;
    for (const auto& Pawn : Pawns)
    {
        if (bIncludeDead || !Pawn->IsDead())
        {
            Count++;
        }
    }
    return Count;
}

void AHS_PlayerState::AddTimeDelayToPawns(int32 TimeDelay)
{
    for (const auto& Pawn : Pawns)
    {
        Pawn->AddTimeDelay(TimeDelay);
    }
}