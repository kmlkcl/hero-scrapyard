// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "HS_Pawn.generated.h"

UCLASS()
class HEROSCRAPYARD_API AHS_Pawn : public APawn
{
	GENERATED_BODY()

public:
	AHS_Pawn();

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxHP;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CurrentHP;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Stat1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Stat2;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Stat3;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Stat4;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
