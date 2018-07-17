// Fill out your copyright notice in the Description page of Project Settings.

#include "Auto_Turret.h"





// Sets default values
AAuto_Turret::AAuto_Turret()
{
	AggroSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AGGROSPHERE"));
	MuzzlePoint = CreateDefaultSubobject<USceneComponent>(TEXT("MUZZLE"));
	Mesh1P = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	Mesh2P = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("MESH2"));
	RootComponent = AggroSphere; 
	AggroSphere->SetupAttachment(RootComponent, NAME_None);
	Mesh1P->SetupAttachment(RootComponent, NAME_None);
	Mesh2P->SetupAttachment(RootComponent, NAME_None);
	MuzzlePoint->SetupAttachment(Mesh2P, NAME_None);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

	AggroSphere->OnComponentBeginOverlap.AddDynamic(this, &AAuto_Turret::AggroResponse);

	//set default values
	FireInterval = 0.2f;
	ShotSpread = 3.0f;
}

void AAuto_Turret::AggroResponse_Implementation(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	TargetActor = OtherActor;
	GetWorldTimerManager().SetTimer(FireTimer, this, &AAuto_Turret::FireProjectile, FireInterval, true, .1f);
}

void AAuto_Turret::FireProjectile_Implementation()
{
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	FRotator SpawnRotation;
	FRotator RotTowardTarget;
	FVector DeltaVector;
	//sanity checked location delta to prevent crashing
	if (TargetActor)
	{
		DeltaVector = FVector(TargetActor->GetActorLocation() - GetActorLocation());
	}
	else
	{
		DeltaVector = FVector(0, 0, 0);
	}
	RotTowardTarget = FRotationMatrix::MakeFromX(DeltaVector).Rotator();
	SpawnRotation = FRotator(FMath::FRandRange(ShotSpread*-1, ShotSpread) + RotTowardTarget.Pitch, FMath::FRandRange(ShotSpread*-1, ShotSpread) + RotTowardTarget.Yaw, FMath::FRandRange(ShotSpread*-1, ShotSpread) + RotTowardTarget.Roll);
	//Fire the Projectile
	GetWorld()->SpawnActor<AActor>(ProjectileClass, MuzzlePoint->GetComponentLocation(), SpawnRotation, ActorSpawnParams);
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

