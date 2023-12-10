#include <iostream>
#include <assert.h>

class stack
{
private:
    int max;
    int *data;
    int sp;

public:
    void push(int d)
    {
        assert(sp < max);
        data[sp++] = d;
    }
    void pop()
    {
        assert(sp > 0);
        sp--;
    }
    bool empty() const { return sp == 0; }
    int top() const { return data[sp - 1]; }
    int size() const { return sp; }
    stack(int sz = 100)
    {
        sp = 0;
        max = sz;
        std::cout << "max = " << max << std::endl;
        data = new int[max];
    }
    ~stack()
    {
        delete[] data;
    };
};

int main(void)
{
    int n;
    std::cin >> n;
    stack s(n);
    s.push(5);
    s.push(8);
    s.push(9);
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    s.pop();
    s.push(3);
    std::cout << s.size() << std::endl;
    while (!s.empty())
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    return 0;
}