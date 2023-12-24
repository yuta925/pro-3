#include <iostream>
#include <string>

class trace
{
private:
    std::string name;

public:
    trace(const std::string &nm)
    { // 文字列引数を持つコンストラクタ
        name = nm;
        std::cerr << name << " begin" << std::endl; // 〇〇〇　begin と表示
    }
    ~trace()
    {                                             // デストラクタ
        std::cerr << name << " end" << std::endl; // 〇〇〇　end と表示
    }
};

int add(int a, int b)
{
    trace t("add");
    return a + b;
}

int main(void)
{
    trace t1("main");
    for (int i = 0; i < 3; i++)
    {
        trace t2("for-loop");
        int c = add(i, i + 1);
    }
    return 0;
}