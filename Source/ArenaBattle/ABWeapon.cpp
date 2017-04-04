// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaBattle.h"
#include "ABWeapon.h"


// Sets default values
AABWeapon::AABWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	RootComponent = Weapon;

	ConstructorHelpers::FObjectFinder<USkeletalMesh>SK_Weapon(TEXT("SkeletalMesh'/Game/InfinityBladeWeapons/Weapons/Blade/Swords/Blade_SwordA/SK_Blade_SwordA.SK_Blade_SwordA'"));

	Weapon->SetSkeletalMesh(SK_Weapon.Object);
}

// Called when the game starts or when spawned
void AABWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	Weapon = NewObject<USkeletalMeshComponent>(this);

}

// Called every frame
void AABWeapon::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

