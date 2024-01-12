// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/MythGuardianHUD.h"
#include "HUD/CharacterOverlay.h"

void AMythGuardianHUD::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();

	if (World)
	{
		APlayerController* Controller = World->GetFirstPlayerController();

		if (Controller && CharacterOverlayClass)
		{
			CharacterOverlay =  CreateWidget<UCharacterOverlay>(Controller, CharacterOverlayClass);
			CharacterOverlay->AddToViewport();
		}
	}
	
}
