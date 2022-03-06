#include <iostream>

using namespace std;

int main()
{
	// 실력이 좋은 학생들은 배웠던 내용을 복습에 그치지 않고 다른 버전이나 응용을 해본다
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i >= j)
				cout << " ";
			else
				cout << "*";
		}
		cout << endl;
	}
	// i와 j를 행렬의 좌표로 보고, 출력하려는 좌표만 남겨서 규칙을 찾아 if문으로 출력, 아니면 공백 출력
	// 이렇게 별을 찍는게 반복문에서 규칙을 찾는 건다!!!

}