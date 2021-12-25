// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseMenu.h"

bool UPauseMenu::Initialize()
{
	bool success = Super::Initialize();

	return success;
}

void UPauseMenu::SetUp()
{
	this->AddToViewport();

	UWorld* world = GetWorld();


		// FInputModeDataBase is a struct for setting input types. 
		// SetWidegetToFocus() takes in an "SWidget" type, so the widget object.TakeWidget() returns is SWidget type.
	FInputModeUIOnly input_data;
	input_data.SetWidgetToFocus(this->TakeWidget());
	input_data.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
}

