// Fill out your copyright notice in the Description page of Project Settings.


#include "RepeatUntilFail.h"

RepeatUntilFail::RepeatUntilFail(Node* node)
{
	_childNode = node;
}

RepeatUntilFail::~RepeatUntilFail()
{
}

void RepeatUntilFail::Start(TMap<FString, void*>* data)
{
}

void RepeatUntilFail::Update(TMap<FString, void*>* data)
{
	auto state = _childNode->Execution(data);
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
