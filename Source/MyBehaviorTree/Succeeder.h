// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Decorator.h"
#include "CoreMinimal.h"

/**
 * 
 */
class MYBEHAVIORTREE_API Succeeder : public Decorator
{
public:
	Succeeder(TSharedPtr<Node> node);
	~Succeeder();

protected:
	virtual void	Start(TMap<FString, void*>* data)		override;
	virtual void	Update(TMap<FString, void*>* data)	override;
	virtual bool	IsEnd()		override;
	virtual State	End()		override;
};
