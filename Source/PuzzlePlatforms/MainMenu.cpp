// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"

bool UMainMenu::Initialize()
{
	bool success = Super::Initialize();

	if (success)
	{
		if (host_button != nullptr)
		{
			host_button->OnPressed.AddDynamic(this, &UMainMenu::HostServer);
		}

		if (join_button != nullptr)
		{
			join_button->OnPressed.AddDynamic(this, &UMainMenu::OpenJoinMenu);
		}
		
		if (back_button != nullptr)
		{
			back_button->OnPressed.AddDynamic(this, &UMainMenu::OpenMainMenu);
		}
		

		return success;
	}

	return success;
}

void UMainMenu::SetMenuInterface(IMenuInterface* menu_in)
{
	this->menu_interface = menu_in;
}

void UMainMenu::SetUp()
{
	this->AddToViewport();

	UWorld* world = GetWorld();
	

	// FInputModeDataBase is a struct for setting input types. 
	// SetWidegetToFocus() takes in an "SWidget" type, so the widget object.TakeWidget() returns is SWidget type.
	FInputModeUIOnly input_data;
	input_data.SetWidgetToFocus(this->TakeWidget());
	input_data.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	if (world != nullptr)
	{ 
		APlayerController* player_controller = world->GetFirstPlayerController();
		player_controller->bShowMouseCursor = true;
		player_controller->SetInputMode(input_data);
	}
}


void UMainMenu::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);

	if(APlayerController* player_controller = GetWorld()->GetFirstPlayerController())
	{ 
		FInputModeGameOnly input_data;
		//FInputModeGameOnly.SetConsumeCaptureMouseDown(true);

		player_controller->bShowMouseCursor = false;
		player_controller->SetInputMode(input_data);
	}

	
}

void UMainMenu::HostServer()
{
	if (menu_interface != nullptr)
	{
		menu_interface->Host();
	}
}

void UMainMenu::OpenJoinMenu()
{
	menu_switcher->SetActiveWidget(join_menu);
}

void UMainMenu::OpenMainMenu()
{
	menu_switcher->SetActiveWidget(main_menu);
}

void UMainMenu::JoinServer()
{
	UE_LOG(LogTemp, Warning, TEXT("Join Server in MainMenu.cpp"));
}



