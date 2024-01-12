// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GuardianAnimInstance.h"
#include "Characters/GuardianCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UGuardianAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	GuardianCharacter = Cast<AGuardianCharacter>(TryGetPawnOwner());
	if (GuardianCharacter) 
	{
		GuardianCharacterMovement = GuardianCharacter->GetCharacterMovement();
	}
}
	

void UGuardianAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (GuardianCharacterMovement) 
	{
		GroundSpeed =  UKismetMathLibrary::VSizeXY(GuardianCharacterMovement->Velocity);
		IsFalling = GuardianCharacterMovement->IsFalling();
		CharacterState = GuardianCharacter->GetCharacterState();
	}
}
