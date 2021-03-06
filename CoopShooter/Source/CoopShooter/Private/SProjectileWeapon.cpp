// Fill out your copyright notice in the Description page of Project Settings.

#include "SProjectileWeapon.h"

#include "Components/SkeletalMeshComponent.h"

void ASProjectileWeapon::BeginPlay()
{
	Super::BeginPlay();

	BaseDamage = 40.0f;
	bIsAutomatic = false;
	RateOfFire = 30;
}

void ASProjectileWeapon::Fire()
{
	// Trace the world, from pawn eyes to cross hair location
	AActor* MyOwner = GetOwner();

	if (MyOwner && ProjectileClass)
	{
		FVector EyeLocation;
		FRotator EyeRotation;
		MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

		FVector MuzzleLocation = MeshComp->GetSocketLocation(MuzzleSocketName);

		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		GetWorld()->SpawnActor<AActor>(ProjectileClass, MuzzleLocation, EyeRotation, SpawnParams);
	}
}
