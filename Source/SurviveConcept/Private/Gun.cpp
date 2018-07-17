// Fill out your copyright notice in the Description page of Project Settings.

#include "Gun.h"


// Sets default values
AGun::AGun()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	Muzzle = CreateDefaultSubobject<USceneComponent>(TEXT("MUZZLE"));
	RootComponent = Mesh;
	Muzzle->SetupAttachment(RootComponent);
}
// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

