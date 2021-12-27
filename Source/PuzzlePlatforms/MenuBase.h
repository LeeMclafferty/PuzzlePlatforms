// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MenuBase.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMenuBase : public UUserWidget
{
	GENERATED_BODY()

public:

	void Setup();
	void SetMenuInterface(IMenuInterface* menu_in);
	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;

protected:

	virtual bool Initialize() override;

	IMenuInterface* menu_interface;


private:
	




	
};
