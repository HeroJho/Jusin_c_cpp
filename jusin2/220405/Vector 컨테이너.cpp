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

	// push_front() : deque�� list ��� ����
	// pop_front()	: deque�� list ��� ����
	// push_back()	: ��� ������ �����̳� ��� ����
	// pop_back()	: ��� ������ �����̳� ��� ����

#pragma endregion


#pragma region ���� ���� ������

	// ���ʹ� �迭 ����̱� ������ []������(�����ε� ��)�� ����� �� �ִ�!
	// �������� ����

	// vecInt[3] = 777;		// �ε��� ������ ���� ������ �� ������ ����

	// for (size_t i = 0; i < vecInt.size(); ++i)
	//	 cout << vecInt[i] << endl

#pragma endregion


#pragma region ���� ���̴� ��� �Լ�

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



#pragma region capacity() *�߿�

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

#pragma region insert()

	// ������ ��ġ�� ���Ҹ� �����ϴ� �Լ�
	// vecInt.insert(iter, 60000);

#pragma endregion



#pragma region erase() *���� Ư��! �߿�!

	// ������ ��ġ�� ���Ҹ� �����ϴ� �Լ�
	// iter = vecInt.erase(iter);


	// ���� �� �׳� iter�� �����Ϸ��� ������
	vecInt.erase(iter);	
	cout << (*iter) << endl;

	// ��?
	// iter: ���Ҹ� ����Ű������ ��ü (�޸𸮸� ����Ű�� �뵵�� �ƴϴ�!)
	// ���Ұ� �����ƴ� >> ����Ű�� ���Ұ� ���µ�?
	// ��ȯ���� ���Ҹ� ���� ����Ų ����
	// ������ ����: ������ �� �ڿ� ���� ���Ҹ� ����Ű�� ���͸� ��ȯ!! ��ȯ������ �޾���� �Ѵ�!

	// ����Ʈ�� �����غ���!
	
#pragma endregion



#pragma endregion


#pragma region �޸� Ȯ���� ���� vector�� �Լ���


#pragma region ������ ���

	vector<int>		vecInt(10);
	// ���� ������ ���� ���� 0���� �ʱ�ȭ�� ���·� ������� ī�Ľ�Ƽ�� �̸� 10�� ������ִ� ����
	//     ��size == ī�Ľ�Ƽ
	// �̷��� push_back�ϸ� �ٷ� ���Ҵ��� �Ͼ

#pragma endregion

#pragma region resize()

	vecInt.resize(2);		
	// ������ ������ �ٽ� �����ϴ� �Լ�.
	//    ����, �̹� Ȯ���� �޸� ����(ī�Ľ�Ƽ)�� �پ���� �ʴ´�.

	vecInt.resize(50);
	// ������ ��Ű�� �׸�ŭ ���Ҵ�(ī�Ľ�Ƽ ����)�Ѵ�.

#pragma endregion

#pragma region reserve()

	vecInt.reserve(10);	
	// ���� ���� ���� ���� ������ �޸� ������ �̸� Ȯ���ϴ� �Լ�
	// size�� 0�̰� ĳ�۽�Ƽ�� �ø���

#pragma endregion


#pragma region ����

	// �ᱹ �����ڸ� ���� ���� Ȯ���� �ϰ� resize�Լ��� ���� �� ����
	// reserve�� ���°� ���ϴ�.
	// ������ �̸����� �޸� ������ �˾Ƽ� ���ִ� �޸� Ȯ�� ���� �Լ����� �� ����� �� �ϰԵȴ�.

#pragma endregion


#pragma endregion





	return 0;
}


