// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FireCharacter.generated.h"

UCLASS()
class POYECTOVR_FUEGO_API AFireCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFireCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY()
		class UCameraComponent* Camera;

	UPROPERTY()
		class UMotionControllerComponent* LeftController;

	UPROPERTY()
		class UMotionControllerComponent* RightController;

	UPROPERTY()
		class UMotionControllerComponent* Tracker;

	UPROPERTY()
		class USceneComponent* VRRoot;

};
