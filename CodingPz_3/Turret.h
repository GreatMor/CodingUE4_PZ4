// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Turret.generated.h"

DECLARE_EVENT(ATurret, FOnTurredKilled);

UCLASS()
class CODINGPZ_3_API ATurret : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties

	UPROPERTY(EditAnywhere)
		float Health;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent * TurretBody;

	ATurret();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Destroyed()override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	FOnTurredKilled OnTurredKilled;

	UFUNCTION()
		void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			FVector NormalImpulse, const FHitResult& Hit);


};
