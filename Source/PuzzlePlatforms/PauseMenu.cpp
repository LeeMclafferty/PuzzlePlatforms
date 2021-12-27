// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseMenu.h"
#include "Engine/World.h"
#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"

#include <PuzzlePlatforms/PlayerControllerBase.h>

bool UPauseMenu::Initialize()
{
	bool success = Super::Initialize();

	if (continue_button != nullptr)
	{
		continue_button->OnPressed.AddDynamic(this, &UPauseMenu::OnPressContinue);
	}
	if (quit_button != nullptr)
	{
		quit_button->OnPressed.AddDynamic(this, &UPauseMenu::OnPressQuit);
	}

	if (back_button)
	{
		back_button->OnPressed.AddDynamic(this, &UPauseMenu::OnPressReturn);
	}

	return success;
}

void UPauseMenu::OnPressContinue()
{
	this->RemoveFromViewport();

	APlayerControllerBase* pc = Cast<APlayerControllerBase>(GetWorld()->GetFirstPlayerController());
	FInputModeGameOnly input_mode;
	
	pc->SetShowMouseCursor(false);
	pc->SetInputMode(input_mode);
}

void UPauseMenu::OnPressQuit()
{
	APlayerControllerBase* pc = Cast<APlayerControllerBase>(GetWorld()->GetFirstPlayerController());

	UKismetSystemLibrary::QuitGame(pc->GetOwner(), pc, EQuitPreference::Quit, false);
}

void UPauseMenu::OnPressReturn()
{
	GetGameInstance()->ReturnToMainMenu();
}

