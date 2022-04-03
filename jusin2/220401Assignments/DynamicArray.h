#pragma once

class DynamicArray
{
private:
	int*	m_arrInt;
	int		m_iCount;
	int		m_iCapacity;

public:
	void Push(int _iValue);
	int Pop();
	int GetSize() { return m_iCount; }

public:
	int& operator[](int _iIndex) {
		if (_iIndex < 0 || _iIndex >= m_iCount) {
			cout << "À¯È¿ ÀÎµ¦½º°¡ ¾Æ´Õ´Ï´Ù." << endl;
			exit(1);
		}

		return m_arrInt[_iIndex];
	}
	int operator[](int _iIndex) const {
		if (_iIndex < 0 || _iIndex >= m_iCount) {
			cout << "À¯È¿ ÀÎµ¦½º°¡ ¾Æ´Õ´Ï´Ù." << endl;
			exit(1);
		}

		return m_arrInt[_iIndex];
	}

public:
	DynamicArray();
	~DynamicArray();
};

