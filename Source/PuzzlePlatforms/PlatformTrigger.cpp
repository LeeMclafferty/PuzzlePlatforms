

#include "PlatformTrigger.h"
#include "UObject/Object.h"
#include "Components/BoxComponent.h" 
#include "Components/StaticMeshComponent.h"

#include "MovingPlatform.h"

// Sets default values
APlatformTrigger::APlatformTrigger()
{
	PrimaryActorTick.bCanEverTick = true;

	trigger_volume = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Volume"));
	if(trigger_volume)
		RootComponent = trigger_volume;

	trigger_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Trigger Mesh"));
	if(trigger_volume != nullptr)
	{ 
		trigger_mesh->SetupAttachment(RootComponent);
		trigger_volume->SetGenerateOverlapEvents(true);

	trigger_volume->OnComponentBeginOverlap.AddDynamic(this, &APlatformTrigger::OnOverlapBegin);
	trigger_volume->OnComponentEndOverlap.AddDynamic(this, &APlatformTrigger::OnOverlapEnd);
	}
}

void APlatformTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlatformTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatformTrigger::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	 //On begin overlap 
	for(AMovingPlatform* platform : platforms_to_trigger)
	{
		platform->AddActiveTrigger();
	}
}

void APlatformTrigger::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, FString::Printf(TEXT("Deactivated")));

	for (AMovingPlatform* platform : platforms_to_trigger)
	{
		platform->RemoveActiveTrigger();
	}
}
