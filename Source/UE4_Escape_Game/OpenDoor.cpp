// Copyright Zakhar Hurov, Poznan, 2020


#include "OpenDoor.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitialYaw;
	TargetYaw = InitialYaw;
	TargetYaw += InitialYaw; //TargetYaw = TargetYaw + InitialYaw;
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentYaw = FMath::Lerp(CurrentYaw, TargetYaw, DeltaTime * 0.3f);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);

	// float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	// FRotator OpenDoor(0.f,TargetYaw, 0.f);
	// OpenDoor.Yaw = FMath::Lerp(CurrentYaw, TargetYaw, 0.01f);
	// GetOwner()->SetActorRotation(OpenDoor);
}

