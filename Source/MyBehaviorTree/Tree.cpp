// Fill out your copyright notice in the Description page of Project Settings.

#include "TimerLeaf.h"
#include "Inverter.h"
#include "Repeater.h"
#include "Sequence.h"
#include "Selector.h"
#include "Succeeder.h"
#include "Tree.h"

// Sets default values for this component's properties
UTree::UTree()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	auto seq = new Sequence();
	auto slc = new Selector();
	seq->AddNode(new TimerLeaf(1));

	slc->AddNode(new Succeeder(new Inverter(new TimerLeaf(.5f))));
	slc->AddNode(new TimerLeaf(1.25f));

	seq->AddNode(slc);
	seq->AddNode(new TimerLeaf(2));
	_root = new Repeater(seq);
}


// Called when the game starts
void UTree::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void UTree::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	auto state = _root->Execution();
	if (state != Node::State::Running)
		ThisTickFunction->UnRegisterTickFunction();
}

