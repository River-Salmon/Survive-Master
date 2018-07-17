// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
#include "Auto_Turret.generated.h"

UCLASS()
class SURVIVECONCEPT_API AAuto_Turret : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAuto_Turret();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USphereComponent* AggroSphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USceneComponent* MuzzlePoint;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class UStaticMeshComponent* Mesh1P;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class UStaticMeshComponent* Mesh2P;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Gameplay)
		void FireProjectile();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float FireInterval;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
