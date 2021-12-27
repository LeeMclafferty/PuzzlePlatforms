// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuBase.h"

#include "PlayerControllerBase.h"

	bool UMenuBase::Initialize()
	{
		bool success = Super::Initialize();
		

		return success;

	}

	void UMenuBase::Setup()
	{
		this->AddToViewport();

		UWorld* world = GetWorld();

		/* Casting to my first person controller.I have to cast because world->GetFirstPersonPlayerController()
		 returns a APlayerController, not an APlayerControllerBase*/

		APlayerControllerBase* pc = Cast<APlayerControllerBase>(world->GetFirstPlayerController());

		// FInputModeDataBase is a struct for setting input types. 
		// SetWidegetToFocus() takes in an "SWidget" type, so the widget object.TakeWidget() returns is SWidget type.

		FInputModeUIOnly input_data;
		input_data.SetWidgetToFocus(this->TakeWidget());
		input_data.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

		// Using Casted variable to call functions on the player controller
		if(pc != nullptr)
		{ 
			pc->SetInputMode(input_data);
			pc->bShowMouseCursor = true;
		}
	}

	void UMenuBase::SetMenuInterface(IMenuInterface* menu_in)
	{
		this->menu_interface = menu_in;
	}

	void UMenuBase::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
	{
		Super::OnLevelRemovedFromWorld(InLevel, InWorld);
	
		if (APlayerController* player_controller = GetWorld()->GetFirstPlayerController())
		{
			FInputModeGameOnly input_data;
			//FInputModeGameOnly.SetConsumeCaptureMouseDown(true);

			player_controller->bShowMouseCursor = false;
			player_controller->SetInputMode(input_data);
		}

	}
