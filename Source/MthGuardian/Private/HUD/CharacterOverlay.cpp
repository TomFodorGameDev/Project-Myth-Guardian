// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/CharacterOverlay.h"
#include "Components/ProgressBar.h"

void UCharacterOverlay::SetHealthBarPercent(float Percent)
{
	if (HealthProgressBar)
	{
		HealthProgressBar->SetPercent(Percent);
	}
}

void UCharacterOverlay::SetManaBarPercent(float Percent)
{
	if (ManaProgressBar)
	{
		ManaProgressBar->SetPercent(Percent);
	}
}
