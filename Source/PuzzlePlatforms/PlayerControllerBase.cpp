// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase.h"

#include "PauseMenu.h"

APlayerControllerBase::APlayerControllerBase()
{
	ConstructorHelpers::FClassFinder<UUserWidget>pause_bp(TEXT("/Game/aa_Widgets/WBP_PauseMenu"));

	pause_class = pause_bp.Class;
}

void APlayerControllerBase::Pause()
{
	if(pause_class)
	{
		pause_menu = CreateWidget<UPauseMenu>(this, pause_class);

			//GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, FString::Printf(TEXT("Pause")));
	
		pause_menu->Setup();
	}
}