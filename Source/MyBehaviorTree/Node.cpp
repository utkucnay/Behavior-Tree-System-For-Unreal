// Fill out your copyright notice in the Description page of Project Settings.


#include "Node.h"

Node::State Node::Execution()
{
	if (_state != State::Running) {
		Start();
		_state = State::Running;
	}
	if (IsEnd()) {
		_state = End();
		return _state;
	}
	Update();
	return _state;
}
