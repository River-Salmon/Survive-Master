// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h "
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SURVIVECONCEPT_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Gameplay)
	void FireProjectile();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Mesh)
	class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	class UClass* ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float FireInterval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	int32 Energy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float ShotSpread;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool Automatic;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Gameplay)
	class USceneComponent* MuzzlePoint;

	FTimerHandle ShotTimer;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Gameplay)
	void StartFireInput();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Gameplay)
	void EndFireInput();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};