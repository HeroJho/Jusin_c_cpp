#include <vector>
using namespace std; // ����Լ� ���ǵ� ������ �� std uing ���ֱ�

// �������� ����Լ��� �����Ѵ�. (�������� �ʿ��� ������ ���۷��� ����)!!


int main()
{
#pragma region ����� ���̹�

	vector<int>		vecInt;
	vector<float>	vecFloat;

#pragma endregion


#pragma region push_back, pop_back

	// �հ� �ڰ� �ִٴ� ���� �������� ���������� ������(������ �� �� ������ ����)
	// �յڰ� ���� ��, ����Ʈ�� �� ���� �Լ��� �߰��� ������ �ִ�

	//push_front() : deque�� list ��� ����
	//pop_front() : deque�� list ��� ����
	//push_back() : ��� ������ �����̳� ��� ����
	//pop_back() : ��� ������ �����̳� ��� ����

#pragma endregion


#pragma region ���� ���� ������

	// ���ʹ� �迭 ����̱� ������ []������(�����ε� ��)�� ����� �� �ִ�!
	// �������� ����



	// vecInt[3] = 777;		// �ε��� ������ ���� ������ �� ������ ����

	// for (size_t i = 0; i < vecInt.size(); ++i)
	//	 cout << vecInt[i] << endl

#pragma endregion


#pragma region size()

	// size() �����̳� ������ ������ ��ȯ (��� �����̳ʰ� ������)

	// size�� sizt_t�� ��ȯ�Ѵ�!!
	//  ��size_t : unsigned int  

#pragma endregion

#pragma region clear()

	// -�����̳� ���� ��� ���Ҹ� �����Ѵ�.
	// -��� �����̳ʰ� ���´�.

#pragma endregion

#pragma region empty()
 
	// -�����̳� ���� ������ ������ �Ǵ��ϴ� �Լ�
	// -��� �����̳ʰ� ���´�.

#pragma endregion

#pragma region swap()

	// ���� Ÿ���� �����̳ʳ��� ���ҿ� '�޸� ����'�� ��ȯ�Ѵ�

#pragma endregion

#pragma region capacity()

	// - ���͸� ������ ������ �Լ��̴�!

#pragma region ������ �޸� �Ҵ� ��å
	
	//	1) ���ʹ� ���� �迭
	//	2) ������ ���Ҵ��Ѵ�
	//	3) �߰��� ������ �Ҵ��ϸ� ��ȿ����
	//	4) ���Ҵ��� �ּ�ȭ�� ��å�� ����

	// ��å�� ����ϴ� �����Ϸ����� �ٸ���!
	// ��O��Ʃ�� ī�Ľ�Ƽ ��å: n + n/2



	/*for (int i = 0; i < 20; ++i)
	{
		cout << "������ : " << vecInt.size() << "\tī�Ľ�Ƽ : " << vecInt.capacity() << endl;
		vecInt.push_back(10);
	}*/

#pragma endregion


	// clear()�ϸ� size�� 0�� ������, ī�Ľ�Ƽ�� �״�δ�(�����ɷ� ���� ���Ҵ������� �ʴ´�)
	//  ��pop�� ��������.

#pragma region capacity �����

	// ���ſ��� �����Ǵ� �Լ��� ��������, ������ �����
	//		���׷��� �����Ǵ� �Լ��� ����ص� ������, ���絵 �� ����� ���̻��.
	//		�����������ε� �� ����� ����.

	// �� ��� �����
	//		�ӽ� ��ü ������ ���� ��ȯ
	//		vector<int>().swap(vecInt);
	
	
	// ������ �� ���� �ʴ´�!! >> �����Ƽ�...
	//    ��ī�Ľ�Ƽ �� ����ٰ��ؼ� ... ���α׷��� ������ ����~���� . �޸� ������ ��ģ��!!

#pragma endregion

#pragma endregion

#pragma region front(), back()

/*vector<int>	vecInt;

	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);
	vecInt.push_back(40);
	vecInt.push_back(50);

	vecInt.front() = 100;		// �� ���� ������ �޸� ������ ���ٰ����� �Լ�
	vecInt.back() = 5000;		// �� ���� ������ �޸� ������ ���ٰ����� �Լ�

	//cout << vecInt.front() << endl;
	//cout << vecInt.back() << endl;

	for (size_t i = 0; i < vecInt.size(); ++i)
	{
		cout << vecInt[i] << endl;
	}*/

#pragma endregion

	return 0;
}


