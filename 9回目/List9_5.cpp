#include <iostream>

void inc(int *x)
{
    (*x)++;
    std::cout << "*x = " << *x << std::endl;
}

int main(void)
{
    int a = 5;
    inc(&a);
    std::cout << "a = " << a << std::endl;
    return 0;
}