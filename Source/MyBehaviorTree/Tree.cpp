// Fill out your copyright notice in the Description page of Project Settings.


#include "Tree.h"

// Sets default values for this component's properties
UTree::UTree()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	_treeData.AddData("Timer1", &_timer1);
	_treeData.AddData("Timer2", &_timer2);

	

}


// Called when the game starts
void UTree::BeginPlay()
{
	Super::BeginPlay();

	_root = BTreeManager::GetInstance()->GetTreeRootNode("BasicTree");
}


// Called every frame
void UTree::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	auto state = _root->Execution(_treeData.GetData());
	if (state != Node::State::Running) {
		ThisTickFunction->UnRegisterTickFunction();
	}
}

