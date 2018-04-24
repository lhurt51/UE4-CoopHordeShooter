// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SGameMode.generated.h"

/**
 * 
 */
UCLASS()
class COOPSHOOTER_API ASGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	ASGameMode();

	virtual void StartPlay() override;

protected:

	FTimerHandle TimerHandle_BotSpawner;

	// Number of bots to spawn in current wave
	int32 NumOfBotsToSpawn;

	int32 WaveCount;

	UPROPERTY(EditDefaultsOnly, Category = "GameMode")
	float TimeBetweenWaves;

	// Hook for BP to spawn a single bot
	UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
	void SpawnNewBot();

	void SpawnBotTimerElapsed();

	// Start Spawning Bots
	void StartWave();

	// Stop spawning bots
	void EndWave();

	// Set timer for next start wave
	void PrepareForNextWave();


};
