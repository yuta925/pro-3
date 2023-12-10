#include <iostream>

int main(void)
{
    std::cout << "hello" << std::endl;
    int n;
    std::cout << "n = ";
    std::cin >> n;
    int s = 1;
    for (int i = 1; i <= n; i++)
        s *= i;
    std::cout << n << "! = " << s << std::endl;
    return 0;
}