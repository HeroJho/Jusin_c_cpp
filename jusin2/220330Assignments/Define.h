

#define SAFE_DELETE(p) if(p){ delete p; }

struct StatInfo
{
	string m_cName;
	int m_iLevel;
	int m_iExp;
	int m_iMaxHp;
	int m_iHp;
	int m_iAt;
	int m_iDt;

	StatInfo(string _cName, int _iAt, int _iDt, int _iMaxHp)
		: m_cName(_cName), m_iAt(_iAt), m_iDt(_iDt), m_iMaxHp(_iMaxHp)
		, m_iLevel(1), m_iExp(0), m_iHp(m_iMaxHp)
	{
	}
	~StatInfo() {}

};

enum SCENE{NONE, TOWN, DUNGUN, SHOP, COUNT = SHOP};