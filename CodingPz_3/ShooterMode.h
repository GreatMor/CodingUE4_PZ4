// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShooterMode.generated.h"

UCLASS(minimalapi)
class ACodingPz_3GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay()override;

	UPROPERTY(EditAnywhere)
		float Scores;


	UFUNCTION()
	void OnTurretKilled();
	ACodingPz_3GameMode();
};



