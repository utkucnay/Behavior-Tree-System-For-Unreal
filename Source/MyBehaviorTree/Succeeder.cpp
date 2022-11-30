// Fill out your copyright notice in the Description page of Project Settings.


#include "Succeeder.h"

Succeeder::Succeeder(Node* node)
{
	_childNode = node;
}

Succeeder::~Succeeder()
{
}

void Succeeder::Start()
{
}

void Succeeder::Update()
{
	auto state = _childNode->Execution();
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
