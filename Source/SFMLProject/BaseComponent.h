#pragma once
#ifndef BaseComponent_h
#define BaseComponent_h

#include <stdio.h>
#include "BaseMessage.h"

class BaseComponent {
public:
	virtual void Awake() {}
	virtual void Start() {}
	virtual void Update() {}
	virtual void LateUpdate() {}
	virtual bool SendMessage(BaseMessage* msg) { return false; }
};

#endif