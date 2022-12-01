// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Leaf.h"
#include "CoreMinimal.h"

/**
 * 
 */
class MYBEHAVIORTREE_API TimerLeaf : public Leaf
{
	float			_waitTime;
	float			_currTime;
	FString			_name;
public:
					TimerLeaf(FString name);
					~TimerLeaf();

protected:
	virtual void	Start(TMap<FString, void*>* data)		override;
	virtual void	Update(TMap<FString, void*>* data)	override;
	virtual bool	IsEnd()		override;
	virtual State	End()		override;
};
