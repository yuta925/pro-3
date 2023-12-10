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
    friend bool equal(const stack &, const stack &);
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

bool equal(const stack &s1, const stack &s2)
{
    bool eq = true;     // 等しければeq=true、そうでなければeq=false
    if (s1.sp != s2.sp) // データ数が違えば等しくない
        eq = false;
    else
    {
        for (int i = 0; i < s1.sp; i++)
            if (s1.data[i] != s2.data[i]) // データが一つでも一致しなければ等しくない
                eq = false;
    }
    return eq;
}

int main(void)
{
    stack s1, s2;
    s1.push(5);
    s1.push(8);
    s1.push(9);
    s2.push(5);
    s2.push(8);
    s2.push(9);
    s2.push(10);
    std::cout << equal(s1, s2) << std::endl;
    s2.pop();
    std::cout << equal(s1, s2) << std::endl;
    return 0;
}