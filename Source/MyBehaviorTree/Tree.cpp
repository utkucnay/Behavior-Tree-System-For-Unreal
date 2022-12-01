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

	auto seq = Sequence::Init<Sequence>();
	auto slc = Selector::Init<Selector>();
	seq->AddNode(TimerLeaf::Init<TimerLeaf,float>(5));

	seq->AddNode(TimerLeaf::Init<TimerLeaf,float>(2));
	_root = Repeater::Init<Repeater,TSharedPtr<Node>>(seq);
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

