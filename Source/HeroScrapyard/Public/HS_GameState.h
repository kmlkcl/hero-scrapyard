// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "HS_GameState.generated.h"

/**
 * 
 */
UCLASS()
class HEROSCRAPYARD_API AHS_GameState : public AGameStateBase
{
	GENERATED_BODY()


public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 CurrentTurn = 0;		
};
