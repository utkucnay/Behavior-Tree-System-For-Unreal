// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Node.h"
#include "CoreMinimal.h"

/**
 * 
 */
class MYBEHAVIORTREE_API Decorator : public Node
{
protected:
	Node* _childNode;

};
