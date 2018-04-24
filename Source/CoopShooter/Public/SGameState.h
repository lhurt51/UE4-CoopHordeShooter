// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SGameState.generated.h"

UENUM(BlueprintType)
enum class EWaveState : uint8
{
	WaitingToStart,
	WaveInProgress,
	// No longer spawning new bots, waiting for players to kill remaining enemies
	WaitingToComplete,
	GameOver,
};

/**
 * 
 */
UCLASS()
class COOPSHOOTER_API ASGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WaveState, Category = "GameState")
	EWaveState WaveState;

protected:

	UFUNCTION()
	void OnRep_WaveState(EWaveState OldState);

	UFUNCTION(BlueprintImplementableEvent, Category = "GameState")
	void WaveStateChanged(EWaveState NewState, EWaveState OldState);
	
	
};
