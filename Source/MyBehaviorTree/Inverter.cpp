// Fill out your copyright notice in the Description page of Project Settings.


#include "Inverter.h"

Inverter::Inverter(TSharedPtr<Node> node)
{
	_childNode = node;
}

Inverter::~Inverter()
{
}

void Inverter::Start(TMap<FString, void*>* data)
{

}

void Inverter::Update(TMap<FString, void*>* data)
{
	auto state = _childNode->Execution(data);
	if (state == Node::State::Success) {
		_state = Node::State::Failure;
	}
	if (state == Node::State::Failure) {
		_state = Node::State::Success;
	}
}

bool Inverter::IsEnd()
{
	return _state != Node::State::Running;
}

Node::State Inverter::End()
{
	return _state;
}
