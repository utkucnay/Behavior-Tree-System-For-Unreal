// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Node.h"

/**
 * 
 */
class MYBEHAVIORTREE_API Composite : public Node
{
protected:
	TArray<Node*>		_childNodes;
	int					_currIndex;
	int					_lenght		= 0;

public:
	void				AddNode(Node* node) { _childNodes.Add(node); _lenght++; };
};
