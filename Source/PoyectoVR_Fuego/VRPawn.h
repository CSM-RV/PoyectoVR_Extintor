// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "HandControllerBase.h"
#include "VRPawn.generated.h"

UCLASS()
class POYECTOVR_FUEGO_API AVRPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AVRPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(UInputComponent * PlayerInputComponent) override;

private:

	void LeftTriggerPressed() { if (LeftPaintBrushHandController) LeftPaintBrushHandController->TriggerPressed(); }
	void LeftTriggerReleased() { if (LeftPaintBrushHandController) LeftPaintBrushHandController->TriggerReleased(); }

	// Config
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AHandControllerBase> PaintBrushHandControllerClass;
	
	// Components
	UPROPERTY(VisibleAnywhere)
	USceneComponent* VRRoot;
	
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;
	
	// Reference
	UPROPERTY()
	AHandControllerBase* LeftPaintBrushHandController;
	
};
