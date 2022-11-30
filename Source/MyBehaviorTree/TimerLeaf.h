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
public:
					TimerLeaf(float waitTime);
					~TimerLeaf();

protected:
	virtual void	Start()		override;
	virtual void	Update()	override;
	virtual bool	IsEnd()		override;
	virtual State	End()		override;
};
