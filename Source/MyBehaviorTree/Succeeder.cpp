// Fill out your copyright notice in the Description page of Project Settings.


#include "Succeeder.h"

Succeeder::Succeeder(Node* node)
{
	_childNode = node;
}

Succeeder::~Succeeder()
{
}

void Succeeder::Start(TMap<FString, void*>* data)
{
}

void Succeeder::Update(TMap<FString, void*>* data)
{
	auto state = _childNode->Execution(data);
	if (state != Node::State::Running)
		_state = Node::State::Success;
}

bool Succeeder::IsEnd()
{
	if (_state != Node::State::Running)
		return true;
	return false;
}

Node::State Succeeder::End()
{
	return _state;
}
