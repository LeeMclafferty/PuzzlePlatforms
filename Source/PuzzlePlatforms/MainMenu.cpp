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

		if (host_button != nullptr)
		{
			host_button->OnPressed.AddDynamic(this, &UMainMenu::JoinServer);
		}
		

		return success;
	}

	return success;
}

void UMainMenu::HostServer()
{
	UE_LOG(LogTemp, Warning, TEXT("Host Server in MainMenu.cpp"));
}

void UMainMenu::JoinServer()
{
	UE_LOG(LogTemp, Warning, TEXT("Join Server in MainMenu.cpp"));
}
