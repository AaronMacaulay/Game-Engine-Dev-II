#pragma once
#ifndef BaseMessage_hpp
#define BaseMessage_hpp

#include <stdio.h>

enum eMessageType
{
	SetPosition,
	GetPosition,
};

class BaseMessage
{
protected: 
	BaseMessage(int destinationObjectID, eMessageType messageTypeID)
		: m_destObjectID(destinationObjectID)
		, m_messageTypeID(messageTypeID)
	{}

public: 
	int m_destObjectID;
	eMessageType m_messageTypeID;
};

#endif 