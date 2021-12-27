// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

	APlayerControllerBase();
public:

	virtual void Pause();


protected:

	UPROPERTY()
	TSubclassOf<class UUserWidget> pause_class;

	UPROPERTY()
	class UPauseMenu* pause_menu;


	
};
