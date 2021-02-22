// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuSystem/MenuWidget.h"
#include "InGameMenu.generated.h"

class UButton;

/**
 * 
 */
UCLASS()
class COOPSHOOTER_API UInGameMenu : public UMenuWidget
{
	GENERATED_BODY()
	
private:

	UPROPERTY(meta = (BindWidget))
	UButton* QuitButton;

	UPROPERTY(meta = (BindWidget))
	UButton* CancelButton;

protected:

	virtual bool Initialize();

private:

	UFUNCTION()
	void CancelButtonPressed();

	UFUNCTION()
	void QuitButtonPressed();

};
