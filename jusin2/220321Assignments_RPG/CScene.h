#pragma once

#include <iostream>
using namespace std;

class CScene
{
private:

public:
	virtual void Update() = 0;

public:
	CScene();
	virtual ~CScene();
};

