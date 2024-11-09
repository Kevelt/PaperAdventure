// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/CPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"

void ACPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (this->K2_GetPawn()) {
		ControlledPawn = Cast<ACharacter>(this->GetPawn());
		MovementComponent = ControlledPawn.Get()->GetMovementComponent();
	}

	check(this->MappingContext);

	if (UEnhancedInputLocalPlayerSubsystem* SubsystemInput = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		UE_LOG(LogTemp, Warning, TEXT("SubsystemInput"))
		SubsystemInput->AddMappingContext(MappingContext, 0);
	}

	UE_LOG(LogTemp, Warning, TEXT("BeginPlay"));
}

void ACPlayerController::Move(const FInputActionValue& Value)
{
	if (ControlledPawn) {
		const FVector ForwardDirection = FVector(1.f, 0.f, 0.f);
		ControlledPawn->AddMovementInput(ForwardDirection, FMath::RoundToInt(Value.GetMagnitude()));
		this->RotateDirection(Value.GetMagnitude());
	}
}

void ACPlayerController::Jump()
{
	if (ControlledPawn) {
		ControlledPawn.Get()->Jump();
	}
}

void ACPlayerController::RotateDirection(const float MovementVector)
{
	if (MovementVector > 0.f)
	{
		this->SetControlRotation(FRotator::ZeroRotator);
	}
	else
	{
		this->SetControlRotation(FRotator(0.f, -180.f, 0.f));
	}
}

void ACPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(this->InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveInpuAction, ETriggerEvent::Triggered, this, &ACPlayerController::Move);
		EnhancedInputComponent->BindAction(JumpInputAction, ETriggerEvent::Started, this, &ACPlayerController::Jump);
	}

	UE_LOG(LogTemp, Warning, TEXT("SetupInputComponent"));
}