// Fill out your copyright notice in the Description page of Project Settings.


#include "HS_Item.h"

// Sets default values
AHS_Item::AHS_Item()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHS_Item::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHS_Item::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

