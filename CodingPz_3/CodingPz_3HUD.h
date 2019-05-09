// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CodingPz_3HUD.generated.h"

UCLASS()
class ACodingPz_3HUD : public AHUD
{
	GENERATED_BODY()

public:
	ACodingPz_3HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

