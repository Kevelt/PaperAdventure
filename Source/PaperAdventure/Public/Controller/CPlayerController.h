// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "CPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class APawn;
class UPawnMovementComponent;
class UEnhancedInputLocalPlayerSubsystem;
/**
 * 
 */
UCLASS()
class PAPERADVENTURE_API ACPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	virtual void SetupInputComponent() override;

	void Move(const FInputActionValue& Value);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Custom Values|Input")
	TObjectPtr<UInputMappingContext> MappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Custom Values|Input")
	TObjectPtr<UInputAction> MoveInpuAction;

	UPROPERTY(EditDefaultsOnly, Category = "Custom Values|Input")
	TObjectPtr<UInputAction> JumpInputAction;

	UPROPERTY(VisibleAnywhere, Category = "Custom Values|References")
	TObjectPtr<ACharacter> ControlledPawn;

	UPROPERTY(VisibleAnywhere, Category = "Custom Values|References")
	TObjectPtr<UPawnMovementComponent> MovementComponent;

	void RotateDirection(const float Value);
	void Jump();
};
