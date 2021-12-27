// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuBase.h"
#include "PauseMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPauseMenu : public UMenuBase
{
	GENERATED_BODY()

public:


protected:

	virtual bool Initialize() override;

private:
	
	UPROPERTY(meta = (BindWidget))
	class UButton* continue_button;

	UPROPERTY(meta = (BindWidget))
	class UButton* quit_button;

	UPROPERTY(meta = (BindWidget))
	class UButton* back_button;

	UFUNCTION()
	void OnPressContinue();

	UFUNCTION()
	void OnPressQuit();

	UFUNCTION()
	void OnPressReturn();

	
};
