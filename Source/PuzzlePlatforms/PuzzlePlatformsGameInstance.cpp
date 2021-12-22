// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformsGameInstance.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitalizer)
{

}

void UPuzzlePlatformsGameInstance::Init()
{

}

void UPuzzlePlatformsGameInstance::Host()
{

	UWorld* world = GetWorld();
	if (world != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::Printf(TEXT("Host")));
		world->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
	}

}

void UPuzzlePlatformsGameInstance::Join(FString ip_address)
{
	
	APlayerController* player_controller = GetFirstLocalPlayerController();
	if (player_controller != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::Printf(TEXT(" Joining IP: %s"), *ip_address));
		player_controller->ClientTravel(ip_address, ETravelType::TRAVEL_Absolute);
	}
}
