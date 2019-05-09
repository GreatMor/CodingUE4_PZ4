// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ShooterMode.h"
#include "CodingPz_3HUD.h"
#include "CodingPz_3Character.h"
#include "kismet/GameplayStatics.h"
#include "Turret.h"
#include "UObject/ConstructorHelpers.h"

void ACodingPz_3GameMode::OnTurretKilled()
{
	Scores += 20;
	UE_LOG(LogTemp, Warning, TEXT("Scores %f - "), Scores);
}

ACodingPz_3GameMode::ACodingPz_3GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ACodingPz_3HUD::StaticClass();

	
}

void ACodingPz_3GameMode::BeginPlay()
{
	Super::BeginPlay();
	Scores = 0;
	TArray<AActor *> turretActors;
	UGameplayStatics::GetAllActorsOfClass(this, ATurret::StaticClass(), turretActors);
	for (AActor* turretActors : turretActors)
	{
		ATurret * turret = Cast<ATurret>(turretActors);
		if (turret)
		{
			turret->OnTurredKilled.AddUFunction(this, "OnTurretKilled");
		}
	}
}

