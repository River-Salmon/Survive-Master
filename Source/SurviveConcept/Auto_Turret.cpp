// Fill out your copyright notice in the Description page of Project Settings.

#include "Auto_Turret.h"





// Sets default values
AAuto_Turret::AAuto_Turret()
{
	AggroSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AGGROSPHERE"));
	MuzzlePoint = CreateDefaultSubobject<USceneComponent>(TEXT("MUZZLE"));
	AggroSphere->SetupAttachment(RootComponent, NAME_None);
	MuzzlePoint->SetupAttachment(RootComponent, NAME_None);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh1P = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	Mesh2P = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("MESH2"));
}

void AAuto_Turret::FireProjectile_Implementation()
{
}

// Called when the game starts or when spawned
void AAuto_Turret::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAuto_Turret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

