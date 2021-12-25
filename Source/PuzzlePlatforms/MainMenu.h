// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:

	void SetMenuInterface(IMenuInterface* menu_in);
	void SetUp();
	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;

protected:
	virtual bool Initialize() override;

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* host_button;

	UPROPERTY(meta = (BindWidget))
	class UButton* join_button;

	UPROPERTY(meta = (BindWidget))
	class UButton* join_button_1;

	UPROPERTY(meta = (BindWidget))
	class UButton* back_button;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* menu_switcher;

	UPROPERTY(meta = (BindWidget))
	class UWidget* join_menu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* main_menu;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* ip_address_field;

	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void JoinServer();

	UFUNCTION()
	void OpenJoinMenu();

	UFUNCTION()
	void OpenMainMenu();

	IMenuInterface* menu_interface;

	
};
