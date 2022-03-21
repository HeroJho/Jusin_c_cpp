#pragma once

#include "CScene.h"
#include "Define.h"
#include "CGameManager.h"
#include "CSceneManager.h"

class CLobby :
    public CScene
{
private:

public:
    virtual void Update();

public:
    CLobby();
    ~CLobby();
};

