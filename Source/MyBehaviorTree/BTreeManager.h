// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Node.h"
#include "TimerLeaf.h"
#include "Inverter.h"
#include "Repeater.h"
#include "Sequence.h"
#include "Selector.h"
#include "Succeeder.h"

/**
 * 
 */

static class MYBEHAVIORTREE_API BTreeManager
{

public:
	TMap<FString, Node*> _trees;
	static BTreeManager* s_instance;

protected:
	BTreeManager();
public:
	BTreeManager(BTreeManager& other) = delete;
    void operator=(const BTreeManager&) = delete;

	void InitTrees();
	Node* GetTreeRootNode(FString name) {
		auto a = _trees.Find(name); 
		return *a; 
	};
	static BTreeManager* GetInstance();
};

BTreeManager* BTreeManager::s_instance = nullptr;