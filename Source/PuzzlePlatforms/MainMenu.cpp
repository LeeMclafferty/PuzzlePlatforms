// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"

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
			join_button->OnPressed.AddDynamic(this, &UMainMenu::JoinServer);
		}
		

		return success;
	}

	return success;
}

void UMainMenu::SetMenuInterface(IMenuInterface* menu_in)
{
	this->menu_interface = menu_in;
}

void UMainMenu::HostServer()
{
	if (menu_interface != nullptr)
	{
		menu_interface->Host();
	}
}

void UMainMenu::JoinServer()
{
	UE_LOG(LogTemp, Warning, TEXT("Join Server in MainMenu.cpp"));
}



