// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "HS_GameLevelActor.generated.h"

class AHS_GameMode;
struct FHS_ItemConfig;

/**
 * 
 */
UCLASS()
class HEROSCRAPYARD_API AHS_GameLevelActor : public ALevelScriptActor
{
	GENERATED_BODY()
	
protected:
	TObjectPtr<AHS_GameMode> HSGameMode;
		
public:
	virtual void BeginPlay() override;

};
