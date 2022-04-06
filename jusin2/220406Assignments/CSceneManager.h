#pragma once

class CScene;

class CSceneManager
{
private:
	static FIELD m_eCurField;
	static FIELD m_ePreField;

private:
	CScene* m_vecScene[(int)FIELD::END];

public:
	void Update();
	void Login();

public:
	static void Set_CurField(FIELD _eCurField);
	static FIELD Get_CurField();
	static FIELD Get_PreField();

public:
	CSceneManager();
	~CSceneManager();
};

