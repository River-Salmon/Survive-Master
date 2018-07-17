// Fill out your copyright notice in the Description page of Project Settings.

#include "Gun.h"

// Sets default values
AGun::AGun()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	MuzzlePoint = CreateDefaultSubobject<USceneComponent>(TEXT("MUZZLE"));
	RootComponent = Mesh;
	MuzzlePoint->SetupAttachment(RootComponent);
}
void AGun::FireProjectile_Implementation()
{
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	GetWorld()->SpawnActor<AActor>(ProjectileClass, MuzzlePoint->GetComponentLocation(), UGameplayStatics::GetPlayerController(this, 0)->GetControlRotation(), ActorSpawnParams);
}

void AGun::StartFireInput_Implementation()
{
	FireProjectile();
	if (Automatic)
	{
		GetWorldTimerManager().SetTimer(ShotTimer, this, &AGun::FireProjectile, FireInterval, true, .1f);
	}
}
void AGun::EndFireInput_Implementation()
{
	GetWorldTimerManager().ClearTimer(ShotTimer);
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

