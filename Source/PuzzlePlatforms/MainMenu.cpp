// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"

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
			if(main_menu)
				join_button->OnPressed.AddDynamic(this, &UMainMenu::OpenJoinMenu);
		}
		
		if (back_button != nullptr)
		{
			back_button->OnPressed.AddDynamic(this, &UMainMenu::OpenMainMenu);
		}

		if (join_button_1 != nullptr)
		{
			join_button_1->OnPressed.AddDynamic(this, &UMainMenu::JoinServer);
		}
		

		return success;
	}

	return success;
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

	if (menu_interface != nullptr)
	{
		if(ip_address_field != nullptr)
		{ 
			menu_interface->Join(ip_address_field->GetText().ToString());
		}
	}
}



