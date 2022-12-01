// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Node.h"
#include "CoreMinimal.h"

/**
 * 
 */
class MYBEHAVIORTREE_API Leaf : public Node
{
protected:
	virtual void	Start(TMap<FString, void*>* data)		override {};
	virtual void	Update(TMap<FString, void*>* data)	override {};
	virtual bool	IsEnd()		override { return Node::IsEnd(); };
	virtual State	End()		override { return Node::End(); };
};
