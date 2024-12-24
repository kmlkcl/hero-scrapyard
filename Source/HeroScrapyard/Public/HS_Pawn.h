// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "HS_CharacterClassConfig.h"
#include "HS_ItemConfig.h"
#include "HS_Action.h"
#include "HS_Pawn.generated.h"

enum class EHS_CharacterClass : uint8;
enum class EHS_Rarity : uint8;
enum class EHS_Race : uint8;
struct FHS_CharacterStats;
struct FHS_Effect;

UCLASS()
class HEROSCRAPYARD_API AHS_Pawn : public APawn
{
	GENERATED_BODY()

public:
	AHS_Pawn();

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EHS_CharacterClass CharacterClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EHS_Rarity Rarity;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EHS_Race Race;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FHS_CharacterStats CharacterStats;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FHS_ItemConfig> Items;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Level;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FHS_Action> Actions;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 CurrentInitDelay;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FHS_Effect> ActiveEffects;

protected:
	UFUNCTION(BlueprintCallable)
	int32 GetWeaponIndex() const;

	UFUNCTION(BlueprintCallable)
	bool IsCriticalHit() const;

	UFUNCTION(BlueprintCallable)
	float GetInitiative() const;

	UFUNCTION(BlueprintCallable)
	float CalculateRawAttackDamage(const AHS_Pawn *Target) const;

	UFUNCTION(BlueprintCallable)
	float RawToCritDamage(float RawDamage) const;

	UFUNCTION(BlueprintCallable)
	void CastAction(int ActionIndex, TArray<AHS_Pawn *> Targets);

	UFUNCTION(BlueprintCallable)
	void ApplyEffect(const FHS_Effect &Effect);

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	bool IsDead() const { return CharacterStats.CurrentHP <= 0.f; }
};
