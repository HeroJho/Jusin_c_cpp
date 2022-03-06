#include <iostream>

void Swap(int*, int*);

int main()
{
    int num1 = 10;
    int num2 = 20;

    std::cout << num1 << ", " << num2 << std::endl;
    Swap(&num1, &num2);
    std::cout << num1 << ", " << num2 << std::endl;
}

void Swap(int* p1, int* p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

