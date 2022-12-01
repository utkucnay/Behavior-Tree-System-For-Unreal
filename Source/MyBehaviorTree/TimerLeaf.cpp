// Fill out your copyright notice in the Description page of Project Settings.

#include<string>
#include "TimerLeaf.h"

TimerLeaf::TimerLeaf(FString name)
{
	_name = name;
}

TimerLeaf::~TimerLeaf()
{
}

void TimerLeaf::Start(TMap<FString, void*>* data)
{
	auto a = data->Find(_name);
	auto b = *a;
	_waitTime = *((float *)b);
	_currTime = 0;
	UE_LOG(LogTemp, Warning, TEXT("Start TimerLeaf"));
}

void TimerLeaf::Update(TMap<FString, void*>* data)
{
	_currTime += FApp::GetDeltaTime();
	
	UE_LOG(LogTemp, Warning, TEXT("The float value is: %f"), _currTime);
}

bool TimerLeaf::IsEnd()
{
	return _waitTime <= _currTime;
}

Node::State TimerLeaf::End()
{
	UE_LOG(LogTemp, Warning, TEXT("End TimerLeaf"));
	return Node::State::Success;
}



