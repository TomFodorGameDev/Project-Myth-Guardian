// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "MthGuardian\DebugMacros.h"
#include "Components/SphereComponent.h"
#include "Characters/GuardianCharacter.h"


// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	 ItemMash = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh|Component"));
	 ItemMash->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	 ItemMash->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	 RootComponent = ItemMash;

	 Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	 Sphere->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnSPhereOverlap);

	Sphere->OnComponentEndOverlap.AddDynamic(this, &AItem::OnSPhereEndOverlap);

	
}

float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCosin()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

void AItem::OnSPhereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	AGuardianCharacter* GuardianCharacter = Cast<AGuardianCharacter>(OtherActor);

	if (GuardianCharacter) 
	{
		GuardianCharacter->SetOverlappingItem(this);
	}
}

void AItem::OnSPhereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AGuardianCharacter* GuardianCharacter = Cast<AGuardianCharacter>(OtherActor);

	if (GuardianCharacter) 
	{
		GuardianCharacter->SetOverlappingItem(nullptr);
	}
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	
}

