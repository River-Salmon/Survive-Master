// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyCharacter.h"

AEnemyCharacter::AEnemyCharacter()
{
	AggroSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AGGROSPHERE"));
	AggroSphere->SetupAttachment(RootComponent, NAME_None);
	MoveUpdateInterval = 3.0f;
	bMovingTowardCore = true;
	AggroSphere->OnComponentBeginOverlap.AddDynamic(this, &AEnemyCharacter::AggroResponse);
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(MoveTimer, this, &AEnemyCharacter::MoveUpdate, MoveUpdateInterval, true, .1f);
}

void AEnemyCharacter::MoveUpdate()
{
	if (bMovingTowardCore)
	{
		MoveTowardCore();
	}
	else 
	{
		MoveTowardPlayer();
	}
}

void AEnemyCharacter::MoveTowardCore_Implementation()
{
}

void AEnemyCharacter::MoveTowardPlayer_Implementation()
{
}

void AEnemyCharacter::AggroResponse_Implementation(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	bMovingTowardCore = false;
	MoveTowardPlayer();
	GetWorldTimerManager().SetTimer(FireTimer, this, &AEnemyCharacter::FireProjectile, MoveUpdateInterval, true, .1f);
}

void AEnemyCharacter::FireProjectile_Implementation()
{
	//Fire the Projectile
}
