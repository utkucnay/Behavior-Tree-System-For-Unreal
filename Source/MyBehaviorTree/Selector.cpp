// Fill out your copyright notice in the Description page of Project Settings.


#include "Selector.h"

Selector::Selector()
{
}

Selector::~Selector()
{
}

void Selector::Start()
{
	_currIndex = 0;
}

void Selector::Update()
{
	auto state = _childNodes[_currIndex]->Execution();
	if (state == Node::State::Success) {
		_currIndex += 2;
	}
	if (state == Node::State::Failure) {
		_currIndex += 1;
	}
}

bool Selector::IsEnd()
{
	if (_currIndex >= _lenght)
	{
		_state = Node::State::Success;
		return true;
	}
	return false;
}

Node::State Selector::End()
{
	return _state;
}
