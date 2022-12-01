// Fill out your copyright notice in the Description page of Project Settings.


#include "BTreeManager.h"

BTreeManager::BTreeManager()
{
	InitTrees();
}

void BTreeManager::InitTrees()
{
	auto seq = Sequence::Init<Sequence>();
	auto slc = Selector::Init<Selector>();
	seq->AddNode(TimerLeaf::Init<TimerLeaf, FString>("Timer1"));

	seq->AddNode(TimerLeaf::Init<TimerLeaf, FString>("Timer2"));
	auto _root = Repeater::Init<Repeater, Node*>(seq);
	_trees.Add("BasicTree", _root);
}

BTreeManager* BTreeManager::GetInstance()
{
	if (s_instance == nullptr) {
		s_instance = new BTreeManager();
	}
	return s_instance;
}
