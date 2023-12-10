#include <iostream>

void swap(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

int main(void)
{
    int a = 5, b = 3;
    std::cout << "入れ替え前" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "入れ替え後" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    return 0;
}