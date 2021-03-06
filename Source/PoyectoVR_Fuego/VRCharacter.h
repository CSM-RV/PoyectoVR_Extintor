// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VRCharacter.generated.h"

UCLASS()
class POYECTOVR_FUEGO_API AVRCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVRCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	bool FindTeleportDestination(TArray<FVector> &OutPath, FVector &OutLocation);
	void UpdateDestinationMarker();
	void DrawTeleportPath(const TArray<FVector> &Path);
	void UpdateSpline(const TArray<FVector> &Path);

	void MoveForward(float throttle);
	void MoveRight(float throttle);

	void BeginTeleport();
	void FinishTeleport();

	void StartFade(float FromAlpha, float ToAlpha);

private:
	UPROPERTY()
	class UCameraComponent* Camera;

	UPROPERTY()
	class UMotionControllerComponent* LeftController;

	//UPROPERTY()
	//class UMotionControllerComponent* RightController;

	//UPROPERTY()
	//class UMotionControllerComponent* Tracker;

	UPROPERTY()
	class USceneComponent* VRRoot;

	UPROPERTY(VisibleAnywhere)
	class USplineComponent* TeleportPath;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* DestinationMarker;

	UPROPERTY()
	TArray<class USplineMeshComponent*> TeleportPathMeshPool;

private:
	UPROPERTY(EditAnywhere)
		float TeleportProjectileRadius = 10;

	UPROPERTY(EditAnywhere)
		float TeleportProjectileSpeed = 800;

	UPROPERTY(EditAnywhere)
		float TeleportSimulationTime = 2;

	UPROPERTY(EditAnywhere)
		float MaxTeleportDistance = 1000;

	UPROPERTY(EditAnywhere)
		float TeleportFadeTime = 1;

	UPROPERTY(EditAnywhere)
		FVector TeleportProjectionExtent = FVector(100, 100, 100);

	UPROPERTY(EditDefaultsOnly)
		class UStaticMesh* TeleportArchMesh;

	UPROPERTY(EditDefaultsOnly)
		class UMaterialInterface* TeleportArchMaterial;

};
