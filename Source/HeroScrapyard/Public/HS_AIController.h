// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "HS_AIController.generated.h"

class AHS_PlayerState;
/**
 *
 */
UCLASS()
class HEROSCRAPYARD_API AHS_AIController : public AAIController
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<AHS_PlayerState> HSPlayerState;

	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	AHS_PlayerState *GetHSPlayerState() const { return HSPlayerState; }
};
