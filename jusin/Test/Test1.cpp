#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Player
{
	char D[26];	// 48/46
	int hp;		// 24/20
	float A;	// 16/16
	float B;	// 16/12
	double C;	// 8/8
};



void main()
{
	cout << sizeof(Player);
	
}