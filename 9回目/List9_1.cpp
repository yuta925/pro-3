#include <iostream>

int main(void)
{
    std::cout << "hello" << std::endl; // 出力の構文
    int n;                             // 宣言は使う前ならどこにあってもよい
    std::cout << "n = ";
    std::cin >> n; // 入力の構文
    int s = 0;
    for (int i = 1; i <= n; i++)
        s += i;
    std::cout << "sum(1.." << n << ") = " << s << std::endl;
    return 0;
}