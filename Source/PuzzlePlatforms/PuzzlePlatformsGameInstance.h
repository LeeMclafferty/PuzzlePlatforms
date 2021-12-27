// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuInterface.h"
#include "PuzzlePlatformsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

	UPuzzlePlatformsGameInstance(const FObjectInitializer &ObjectInitalizer);
	virtual void Init() override;

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(FString ip_address);

	UFUNCTION(BlueprintCallable, Exec, Category = "UMG")
	void LoadMainMenu();

	UFUNCTION(Exec)
	void ReturnToMainMenu() override;


private:
	
		// This function is so I can put giving player control on a timer. 
	UFUNCTION()
	void HoldForRemoveUI();

	UPROPERTY()
	TSubclassOf<class UUserWidget> menu_class;

	class UMainMenu* main_menu;

	
};
