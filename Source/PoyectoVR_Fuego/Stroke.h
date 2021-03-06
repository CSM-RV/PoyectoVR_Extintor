// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Stroke.generated.h"

UCLASS()
class POYECTOVR_FUEGO_API AStroke : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStroke();
	void Update(FVector CursorLocation);

private:
	FTransform GetNextSegmentTransform(FVector CurrentLocation) const;
	FTransform GetNextJointTransform(FVector CurrentLocation) const;
	FVector GetNextSegmentScale(FVector CurrentLocation) const;
	FQuat GetNextSegmentRotation(FVector CurrentLocation) const;
	FVector GetNextSegmentLocation(FVector CurrentLocation) const;

	// Components
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* StrokeMeshes;

	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* JointMeshes;
	
	// State
	FVector PreviousCursorLocation;
};
