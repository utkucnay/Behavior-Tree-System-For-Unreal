// Fill out your copyright notice in the Description page of Project Settings.


#include "Repeater.h"

Repeater::Repeater(TSharedPtr<Node> node)
{
	_childNode = node;
}

Repeater::~Repeater()
{
}

void Repeater::Start(TMap<FString, void*>* data)
{

}

void Repeater::Update(TMap<FString, void*>* data)
{
	_childNode->Execution(data);
}

bool Repeater::IsEnd()
{
	return false;
}

Node::State Repeater::End()
{
	return Node::State::Running;
}
