#pragma once
#include "CScene.h"

#include "CMonster.h"
#include "Define.h"
#include "CGameManager.h"
#include "CSceneManager.h"

class CHunt :
    public CScene
{
private:

public:
    virtual void Update();

public:
    CHunt();
    ~CHunt();
};

