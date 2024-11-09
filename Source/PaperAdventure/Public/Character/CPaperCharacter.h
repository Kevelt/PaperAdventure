// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "PaperZDAnimationComponent.h"
#include "CPaperCharacter.generated.h"

class UNiagaraSystem;
class UPaperZDAnimSequence;
class FInputActionValue;
/**
 * 
 */
UCLASS()
class PAPERADVENTURE_API ACPaperCharacter : public APaperCharacter
{
	GENERATED_BODY()
	
public:
	void Move(const FInputActionValue& value);
};
