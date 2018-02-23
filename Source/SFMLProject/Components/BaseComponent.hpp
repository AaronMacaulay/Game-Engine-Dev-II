#pragma once
#define BaseComponent_hpp

#include <stdint.h>
//#include "BaseMessage.hpp"// //needs to be included once made

class BaseComponent
{
public:
	virtual void Awake() {}
	virtual void Start() {}
	virtual void Update() {}
	virtual void LateUpdate() {}
	//virtual bool SendMessage(BaseMessage* msg) { return false; }// // needs to be included
};

