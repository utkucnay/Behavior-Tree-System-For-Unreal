// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Decorator.h"
#include "CoreMinimal.h"

/**
 * 
 */
class MYBEHAVIORTREE_API RepeatUntilFail : public Decorator
{
public:
	RepeatUntilFail(TSharedPtr<Node> node);
	~RepeatUntilFail();

protected:
	virtual void	Start(TMap<FString, void*>* data)		override;
	virtual void	Update(TMap<FString, void*>* data)	override;
	virtual bool	IsEnd()		override;
	virtual State	End()		override;
};
