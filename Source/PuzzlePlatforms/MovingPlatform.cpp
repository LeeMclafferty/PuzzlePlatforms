// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
	speed = 20.f;

}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	global_start_location = GetActorLocation();
	global_target_location = GetTransform().TransformPosition(target_location);;

}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(HasAuthority())
	{ 
		FVector location = GetActorLocation();
		float travel_length = (global_target_location - global_start_location).Size();
		float travled = (location - global_start_location).Size();

		if (travled >= travel_length)
		{
			FVector swap = global_start_location;
			global_start_location = global_target_location;
			global_target_location = swap;
		}
		FVector direction = (global_target_location - location).GetSafeNormal();
		location += speed * DeltaTime * direction;
		SetActorLocation(location);
	}
	

}
