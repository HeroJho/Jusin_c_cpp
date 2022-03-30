#include "pch.h"
#include "CPlayer.h"

CPlayer::CPlayer(string _cName, int _iAt, int _iDt, int _iMaxHp, int _iGold)
	: CObj(_cName, _iAt, _iDt, _iMaxHp), m_iGold(_iGold)
{
}
CPlayer::~CPlayer()
{

}