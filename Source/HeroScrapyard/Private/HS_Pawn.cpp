// Fill out your copyright notice in the Description page of Project Settings.

#include "HS_Pawn.h"
#include "HS_CharacterStats.h"
#include "HS_CharacterClass.h"
#include "HS_ItemType.h"
#include "HS_ItemConfig.h"
#include "HS_Action.h"
#include "HS_Effect.h"
#include "HS_Race.h"

// Sets default values
AHS_Pawn::AHS_Pawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

//Returns init value
int32 AHS_Pawn::InitializePawn(int32 Lvl, const FHS_CharacterClassConfig &CharacterClassConfig, const FHS_RaceConfig &RaceConfig)
{
	CharacterClass = CharacterClassConfig.CharacterClass;
	Rarity = CharacterClassConfig.Rarity;
	Race = RaceConfig.Race;

	CharacterStats.MaxHP = CharacterClassConfig.CharacterStats.MaxHP;
	CharacterStats.CurrentHP = CharacterStats.MaxHP;
	CharacterStats.Might = CharacterClassConfig.CharacterStats.Might;
	CharacterStats.Dexterity = CharacterClassConfig.CharacterStats.Dexterity;
	CharacterStats.Defense = CharacterClassConfig.CharacterStats.Defense;

	CharacterStats.Might += FMath::RandRange(RaceConfig.MightModifierMin, RaceConfig.MightModifierMax);
	CharacterStats.Dexterity += FMath::RandRange(RaceConfig.DexterityModifierMin, RaceConfig.DexterityModifierMax);
	CharacterStats.Defense += FMath::RandRange(RaceConfig.DefenseModifierMin, RaceConfig.DefenseModifierMax);

	for (int32 i = 1; i <= Lvl; i++)
	{
		Level = i;
		CharacterStats.MaxHP += FMath::RandRange(CharacterClassConfig.HPGrowthMin, CharacterClassConfig.HPGrowthMax);
		CharacterStats.Might += CharacterClassConfig.MightGrowth;
		CharacterStats.Dexterity += CharacterClassConfig.DexterityGrowth;
		CharacterStats.Defense += CharacterClassConfig.DefenseGrowth;
	}	

	Actions = CharacterClassConfig.Actions;

	CurrentInitDelay = GetInitiative();

	return CurrentInitDelay; 
}

float AHS_Pawn::GetInitiative() const
{
	float d100 = FMath::RandRange(1, 100);

	return CharacterStats.Dexterity * 2 + d100;
}

int32 AHS_Pawn::GetWeaponIndex() const
{
	for (int32 i = 0; i < Items.Num(); i++)
	{
		if (Items[i].ItemType == EHS_ItemType::Weapon1H || Items[i].ItemType == EHS_ItemType::Weapon2H)
		{
			return i;
		}
	}

	return -1;
}

void AHS_Pawn::CastAction(int ActionIndex, TArray<AHS_Pawn *> Targets)
{
	const FHS_Action &Action = Actions[ActionIndex];

	for (const FHS_EffectTargets &EffectTarget : Action.EffectTargets)
	{
		const FHS_Effect &Effect = Action.Effects[EffectTarget.EffectIndex];

		for (int32 TargetIndex : EffectTarget.TargetIndices)
		{
			AHS_Pawn *Target = Targets[TargetIndex];

			Target->ApplyEffect(Effect);
		}
	}

	CurrentInitDelay += Action.TimeCost;
}

void AHS_Pawn::ApplyEffect(const FHS_Effect &Effect)
{
	FHS_Effect NewEffect = Effect;
	ActiveEffects.Add(NewEffect);
}

float AHS_Pawn::CalculateRawAttackDamage(const AHS_Pawn *Target) const
{
	const FHS_ItemConfig &Weapon = Items[GetWeaponIndex()];

	float RandomDamage = FMath::RandRange(Weapon.DamageMin, Weapon.DamageMax);

	return (RandomDamage + CharacterStats.Might * Weapon.MightFactor) * (Level * 10) / (Target->Level * 10 + Target->CharacterStats.Defense);
}

float AHS_Pawn::RawToCritDamage(float RawDamage) const
{
	const FHS_ItemConfig &Weapon = Items[GetWeaponIndex()];

	return RawDamage * (Weapon.CritFactor + CharacterStats.Dexterity / 100.f);
}

bool AHS_Pawn::IsCriticalHit() const
{
	const FHS_ItemConfig &Weapon = Items[GetWeaponIndex()];

	float d100 = FMath::RandRange(1, 100);

	return Weapon.CritChance + CharacterStats.Dexterity <= d100;
}

// Called when the game starts or when spawned
void AHS_Pawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHS_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
