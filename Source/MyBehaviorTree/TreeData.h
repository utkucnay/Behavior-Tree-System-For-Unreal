// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MYBEHAVIORTREE_API TreeData
{
private:
	TMap<FString, void*> _datas;
public:
	TreeData();
	~TreeData();
public:
	 void AddData(FString name, void* think) {

		_datas.Add(name, think);
	 }
	 TMap<FString, void*>* GetData() {
		return &_datas;
	 }
};
