#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = i;
    delete[] a;
    return 0;
}