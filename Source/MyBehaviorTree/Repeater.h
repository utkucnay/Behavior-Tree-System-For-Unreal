// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Decorator.h"
#include "CoreMinimal.h"

/**
 * 
 */
class MYBEHAVIORTREE_API Repeater : public Decorator
{
public:
	Repeater(TSharedPtr<Node> node);
	~Repeater();

protected:
	virtual void	Start()		override;
	virtual void	Update()	override;
	virtual bool	IsEnd()		override;
	virtual State	End()		override;
};
