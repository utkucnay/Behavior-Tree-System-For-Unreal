// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Composite.h"
#include "CoreMinimal.h"

/**
 * 
 */
class MYBEHAVIORTREE_API Selector : public Composite
{
public:
					Selector();
					~Selector();

protected:
	virtual void	Start();
	virtual void	Update();
	virtual bool	IsEnd();
	virtual State	End();
};
