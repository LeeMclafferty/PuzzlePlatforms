// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformsGameInstance.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "TimerManager.h"

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
	

}

void UPuzzlePlatformsGameInstance::Host()
{

	UWorld* world = GetWorld();
	//if (main_menu != nullptr)
	//{
	//	FTimerHandle ui_timer;
	//	//world->GetTimerManager().SetTimer(ui_timer, this, &UPuzzlePlatformsGameInstance::HoldForRemoveUI, 5, false);
	//}
	if (world != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::Printf(TEXT("Host")));
		world->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
	}

}

void UPuzzlePlatformsGameInstance::Join(FString ip_address)
{
	if (main_menu != nullptr)
	{
		main_menu->OnLevelRemovedFromWorld(GetWorld()->GetLevel(0), GetWorld());
	}
	 
	APlayerController* player_controller = GetFirstLocalPlayerController();
	if (player_controller != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, FString::Printf(TEXT(" Joining IP: %s"), *ip_address));
		player_controller->ClientTravel(ip_address, ETravelType::TRAVEL_Absolute);
	}
}

	//Load Menu is being called in the Level BP.
void UPuzzlePlatformsGameInstance::LoadMainMenu()
{
	if(menu_class != nullptr)
	{
			//Takes the widget class and makes it into an object. 
		main_menu = CreateWidget<UMainMenu>(this, menu_class);
	

		main_menu->SetMenuInterface(this);
		main_menu->Setup();
	}

}

void UPuzzlePlatformsGameInstance::HoldForRemoveUI()
{
	main_menu->OnLevelRemovedFromWorld(GetWorld()->GetLevel(0), GetWorld());
}
