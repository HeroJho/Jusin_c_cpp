#include <iostream>
#include <string>		// ���ڿ� ���� ���
using namespace std;
// ���ڿ��� �� �ٷ�� ���ؼ� ������� Ŭ���� ����

void main()
{
	string strName = "ȫ�浿";
	cout << strName << endl;

	string strNameTwo = "������";

	strName += strNameTwo;			// ���� �����ڸ� ���ؼ� ���ڿ� ������ ��������
	cout << strName << endl;

	cout << strName.length() << endl;	// ���ڿ� ���̸� ���ϴ� ��� �Լ� ����

	if (strName == strNameTwo)			// ���ڿ� �� ������ ����
	{
		cout << "��ġ!" << endl;
	}
	else
		cout << "����ġ!" << endl;


	char szDest[32] = "jusin";
	string s;
	s = szDest;
	cout << s << endl;
	// szDest = s.c_str();		// const char* ��ȯ
	string s = "Hello";
	const char* pBuff = s.c_str();

	cout << sizeof(string) << endl; // ���ڿ� ���̿� ������� 28����Ʈ
	// ������� ���鿡���� string �뷮�� ����
	// cŸ���� ����¿����� ������ �ȴ�. ������ ���߿� ���� �� ����Ѵ�.
}