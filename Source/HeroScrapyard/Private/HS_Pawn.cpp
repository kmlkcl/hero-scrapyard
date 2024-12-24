// Fill out your copyright notice in the Description page of Project Settings.


#include "HS_Pawn.h"

// Sets default values
AHS_Pawn::AHS_Pawn()
{
 	PrimaryActorTick.bCanEverTick = true;
}

float AHS_Pawn::GetInitiative() const
{
	//TODO: Implement this function
	return 0.f;
}

float AHS_Pawn::CalculateRawAttackDamage() const
{
	return 0.f;
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

