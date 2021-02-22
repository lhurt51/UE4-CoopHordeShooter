// Fill out your copyright notice in the Description page of Project Settings.


#include "SGameInstance.h"

#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

#include "MenuSystem/MainMenu.h"
#include "MenuSystem/MenuWidget.h"

USGameInstance::USGameInstance(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/CoopHordeShooter/UI/MenuSystem/WBP_MainMenu"));
	if (!ensure(MenuBPClass.Class != nullptr)) return;

	MenuClass = MenuBPClass.Class;

	ConstructorHelpers::FClassFinder<UUserWidget> InGameMenuBPClass(TEXT("/Game/CoopHordeShooter/UI/MenuSystem/WBP_InGameMenu"));
	if (!ensure(InGameMenuBPClass.Class != nullptr)) return;

	InGameMenuClass = InGameMenuBPClass.Class;
}

void USGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Found Class %s"), *MenuClass->GetName());
}

void USGameInstance::LoadMenu()
{
	if (!ensure(MenuClass != nullptr)) return;
	MainMenu = CreateWidget<UMainMenu>(this, MenuClass);

	if (!ensure(MainMenu != nullptr)) return;
	MainMenu->Setup();
	MainMenu->SetMenuInterface(this);
}

void USGameInstance::InGameLoadMenu()
{
	if (!ensure(InGameMenuClass != nullptr)) return;
	UMenuWidget* InGameMenu = CreateWidget<UMenuWidget>(this, InGameMenuClass);

	if (!ensure(InGameMenu != nullptr)) return;
	InGameMenu->Setup();
	InGameMenu->SetMenuInterface(this);
}

void USGameInstance::Host()
{
	if (MainMenu != nullptr) MainMenu->TearDown();

	UEngine* Engine = GetEngine();

	if (!ensure(Engine != nullptr)) return;
	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();

	if (!ensure(World != nullptr)) return;
	World->ServerTravel("/Game/CoopHordeShooter/Environment/Maps/P_TestMap?listen");
}

void USGameInstance::Join(const FString& Address)
{
	if (MainMenu != nullptr) MainMenu->TearDown();

	UEngine* Engine = GetEngine();

	if (!ensure(Engine != nullptr)) return;
	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();

	if (!ensure(PlayerController != nullptr)) return;
	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}

void USGameInstance::LoadMainMenu()
{
	UEngine* Engine = GetEngine();

	if (!ensure(Engine != nullptr)) return;
	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Loading Menu"));

	APlayerController* PlayerController = GetFirstLocalPlayerController();

	if (!ensure(PlayerController != nullptr)) return;
	PlayerController->ClientTravel("/Game/CoopHordeShooter/UI/MenuSystem/Levels/MainMenu", ETravelType::TRAVEL_Absolute);
}
