#include <iostream>
#include <assert.h>

class stack
{
private:
    static const int max = 100;
    int data[max];
    int sp;

public:
    void push(int);
    void pop();
    bool empty() const;
    int top() const;
    int size() const;
    stack();
    ~stack();
};

void stack::push(int d)
{
    assert(sp < max);
    data[sp++] = d;
}

void stack::pop()
{
    assert(0 < sp);
    --sp;
}

bool stack::empty() const
{
    return sp == 0;
}

int stack::top() const
{
    return data[sp - 1];
}

int stack::size() const
{
    return sp;
}

stack::stack()
{
    sp = 0;
}

stack::~stack()
{
}

int main(void)
{
    stack s;
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