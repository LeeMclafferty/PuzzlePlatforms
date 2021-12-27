// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"
#include "Kismet/KismetSystemLibrary.h"

#include "PlayerControllerBase.h"

bool UMainMenu::Initialize()
{
	bool success = Super::Initialize();

	if (success)
	{
		if (host_button)
		{
			host_button->OnPressed.AddDynamic(this, &UMainMenu::HostServer);
		}

		if (join_button)
		{
			if(main_menu)
				join_button->OnPressed.AddDynamic(this, &UMainMenu::OpenJoinMenu);
		}
		
		if (back_button)
		{
			back_button->OnPressed.AddDynamic(this, &UMainMenu::OpenMainMenu);
		}

		if (join_button_1)
		{
			join_button_1->OnPressed.AddDynamic(this, &UMainMenu::JoinServer);
		}

		if (quit_button)
		{
			quit_button->OnPressed.AddDynamic(this, &UMainMenu::OnPressQuit);
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

void UMainMenu::OnPressQuit()
{
	APlayerControllerBase* pc = Cast<APlayerControllerBase>(GetWorld()->GetFirstPlayerController());

	UKismetSystemLibrary::QuitGame(pc->GetOwner(), pc, EQuitPreference::Quit, false);
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



