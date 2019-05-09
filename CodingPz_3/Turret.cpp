// Fill out your copyright notice in the Description page of Project Settings.

#include "Turret.h"


// Sets default values
ATurret::ATurret()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TurretBody = CreateDefaultSubobject<UStaticMeshComponent>("Body");
	RootComponent = TurretBody;
	TurretBody->OnComponentHit.AddDynamic(this, &ATurret::OnComponentHit);

	Health = 100.f;
}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();
}

void ATurret::Destroyed()
{

	Super::Destroyed();

	if (OnTurredKilled.IsBound())
	{
		OnTurredKilled.Broadcast();
	}
}

void ATurret::OnComponentHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	Health -= 20.f;
	if (Health <= 0)
		this->Destroy();
	UE_LOG(LogTemp, Warning, TEXT("HP %f - "), Health);

}
// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

