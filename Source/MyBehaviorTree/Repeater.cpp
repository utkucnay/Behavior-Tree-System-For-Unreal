// Fill out your copyright notice in the Description page of Project Settings.


#include "Repeater.h"

Repeater::Repeater(Node* node)
{
	_childNode = node;
}

Repeater::~Repeater()
{
}

void Repeater::Start()
{

}

void Repeater::Update()
{
	_childNode->Execution();
}

bool Repeater::IsEnd()
{
	return false;
}

Node::State Repeater::End()
{
	return Node::State::Running;
}
