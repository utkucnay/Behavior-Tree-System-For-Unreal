// Fill out your copyright notice in the Description page of Project Settings.


#include "Node.h"

Node::State Node::Execution(TMap<FString, void*>* data)
{
	if (_state != State::Running) {
		Start(data);
		_state = State::Running;
	}
	if (IsEnd()) {
		_state = End();
		return _state;
	}
	Update(data);
	return _state;
}
