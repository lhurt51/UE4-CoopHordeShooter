// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "SGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class COOPSHOOTER_API USGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

private:

	TSubclassOf<class UUserWidget> MenuClass;

	TSubclassOf<class UUserWidget> InGameMenuClass;

	class UMainMenu* MainMenu;

public:
	
	// Constructor
	USGameInstance(const FObjectInitializer& ObjectInitializer);

	// Game instantiates initializer
	virtual void Init();

	UFUNCTION(BlueprintCallable)
	void LoadMenu();

	UFUNCTION(BlueprintCallable)
	void InGameLoadMenu();

	UFUNCTION(Exec)
	virtual void Host() override;

	UFUNCTION(Exec)
	virtual void Join(const FString& Address) override;

	UFUNCTION(Exec)
	virtual void LoadMainMenu() override;

};
