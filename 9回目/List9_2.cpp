#include <iostream>

int main(void)
{
    int *a = 0;  // ポインタの宣言
    a = new int; // int 1 個分の領域を割り当て, そこへ のポインタを返す
    *a = 100;
    std::cout << *a << std::endl;
    delete a; // 領域の解放
    return 0;
}