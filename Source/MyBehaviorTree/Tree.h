// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Node.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Tree.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYBEHAVIORTREE_API UTree : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTree();
	TSharedPtr<Node> _root;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
