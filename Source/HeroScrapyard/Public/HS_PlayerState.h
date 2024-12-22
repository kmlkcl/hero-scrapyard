// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "HS_PlayerState.generated.h"

class AHS_Pawn;

/**
 * 
 */
UCLASS()
class HEROSCRAPYARD_API AHS_PlayerState : public APlayerState
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 DivineFavorAmount = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<TObjectPtr<AHS_Pawn>> Pawns;

public:
	UFUNCTION(BlueprintCallable)
	int32 GetDivineFavorAmount() const;

	UFUNCTION(BlueprintCallable)
	int32 GetPawnCount(bool bIncludeDead = false) const;
};
