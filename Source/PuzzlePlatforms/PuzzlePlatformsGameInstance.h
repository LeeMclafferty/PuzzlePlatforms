// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PuzzlePlatformsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance
{
	GENERATED_BODY()

	UPuzzlePlatformsGameInstance(const FObjectInitializer &ObjectInitalizer);
	virtual void Init() override;

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(FString ip_address);

	UPROPERTY()
	TSubclassOf<class UUserWidget> menu_class;

	UFUNCTION(BlueprintCallable, Exec, Category = "UMG")
	void LoadMenu();

	
};
