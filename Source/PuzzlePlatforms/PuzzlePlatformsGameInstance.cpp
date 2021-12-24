// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformsGameInstance.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

#include "PlatformTrigger.h"
#include "MainMenu.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitalizer)
{
		//Gets a reference to the BP class for the main menu.
	ConstructorHelpers::FClassFinder<UUserWidget> menu_bp_class(TEXT("/Game/aa_Widgets/WBP_MainMenu"));
		//Save Reference of the class to a TSubClassOf
	menu_class = menu_bp_class.Class;

}

void UPuzzlePlatformsGameInstance::Init()
{
	
	if (menu_class != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found class: %s"), *menu_class->GetName());
	}

}

void UPuzzlePlatformsGameInstance::Host()
{

	UWorld* world = GetWorld();
	if (world != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::Printf(TEXT("Host")));
		world->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
	}

}

void UPuzzlePlatformsGameInstance::Join(FString ip_address)
{
	
	APlayerController* player_controller = GetFirstLocalPlayerController();
	if (player_controller != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::Printf(TEXT(" Joining IP: %s"), *ip_address));
		player_controller->ClientTravel(ip_address, ETravelType::TRAVEL_Absolute);
	}
}

	//Load Menu is being called in the Level BP.
void UPuzzlePlatformsGameInstance::LoadMenu()
{
	if(menu_class != nullptr)
	{
			//Takes the widget class and makes it into an object. 
		UMainMenu* menu = CreateWidget<UMainMenu>(this, menu_class);
		menu->AddToViewport();
	

		APlayerController* player_controller = GetFirstLocalPlayerController();
			// FInputModeDataBase is a struct for setting input types. 
			// SetWidegetToFocus() takes in an "SWidget" type, so the widget object.TakeWidget() returns is SWidget type.
		FInputModeUIOnly input_data;
		input_data.SetWidgetToFocus(menu->TakeWidget());
		input_data.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		player_controller->bShowMouseCursor = true;
		player_controller->SetInputMode(input_data);

		menu->SetMenuInterface(this);
	}
	
}
