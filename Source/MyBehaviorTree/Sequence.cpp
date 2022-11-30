// Fill out your copyright notice in the Description page of Project Settings.


#include "Sequence.h"

Sequence::Sequence()
{
}

Sequence::~Sequence()
{
}

void Sequence::Start()
{
	_currIndex = 0;
}

void Sequence::Update()
{
	auto state = _childNodes[_currIndex]->Execution();
	if (state == Node::State::Success) {
		_currIndex += 1;
	}
	if (state == Node::State::Failure) {
		_state = Node::State::Failure;
	}
}

bool Sequence::IsEnd()
{
	if (_state == Node::State::Failure)
		return true;
	if (_currIndex == _lenght)
	{
		_state = Node::State::Success;
		return true;
	}
	return false;
}

Node::State Sequence::End()
{
	return _state;
}
