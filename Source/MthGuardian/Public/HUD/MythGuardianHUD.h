// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MythGuardianHUD.generated.h"


class UCharacterOverlay;
/**
 * 
 */
UCLASS()
class MTHGUARDIAN_API AMythGuardianHUD : public AHUD
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditDefaultsOnly, Category = MythGuardian)
	TSubclassOf<UCharacterOverlay> CharacterOverlayClass;

	UPROPERTY()
	UCharacterOverlay* CharacterOverlay;
public:
	FORCEINLINE UCharacterOverlay* GetCharacterOverlay() const { return CharacterOverlay;  }
};
