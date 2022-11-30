// Fill out your copyright notice in the Description page of Project Settings.


#include "RepeatUntilFail.h"

RepeatUntilFail::RepeatUntilFail(Node* node)
{
	_childNode = node;
}

RepeatUntilFail::~RepeatUntilFail()
{
}

void RepeatUntilFail::Start()
{
}

void RepeatUntilFail::Update()
{
	auto state = _childNode->Execution();
	if (state == Node::State::Failure)
		_state = Failure;
}

bool RepeatUntilFail::IsEnd()
{
	if (_state == Node::State::Failure)
		return true;
	return false;
}

Node::State RepeatUntilFail::End()
{
	return _state;
}
