// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MYBEHAVIORTREE_API Node
{
public:
	enum State {
		Failure,
		Running,
		Success
	}				_state;

public:
	State			Execution(TMap<FString, void*>* data);
	template<class T>
	static	TSharedPtr<T> Init() { return TSharedPtr<T>(new T()); }
	template<class T, typename TField>
	static 	TSharedPtr<T> Init(TField field) { return TSharedPtr<T>(new T(field)); }
protected:
	virtual void	Start(TMap<FString, void*>* data){};
	virtual void	Update(TMap<FString, void*>* data)	{};
	virtual bool	IsEnd()		{	return false;	};
	virtual State	End()		{	return _state;	};
};
