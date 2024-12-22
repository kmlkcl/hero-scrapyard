// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "HS_CharacterClass.h"
#include "HS_CharacterStats.h"
#include "HS_Rarity.h"
#include "HS_Pawn.generated.h"

UCLASS()
class HEROSCRAPYARD_API AHS_Pawn : public APawn
{
	GENERATED_BODY()

public:
	AHS_Pawn();

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FHS_CharacterStats CharacterStats;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EHS_CharacterClass CharacterClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EHS_Rarity Rarity;

public:
	UFUNCTION(BlueprintCallable)
	float GetInitiative() const;

	UFUNCTION(BlueprintCallable)
	bool IsDead() const { return CharacterStats.CurrentHP <= 0.f; }

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
