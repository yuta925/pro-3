#include <iostream>

class Complex
{
private:
    double real;
    double imag;

public:
    Complex()
    {
        real = 0.0;
        imag = 0.0;
    }
    Complex(double r, double i)
    {
        real = r;
        imag = i;
    }
    Complex(double r)
    {
        real = r;
        imag = 0.0;
    }
    Complex &operator+=(const Complex &c);
    ~Complex() {}
    double re() const { return real; }
    double im() const { return imag; }
    void set_re(double r) { real = r; }
    void set_im(double i) { imag = i; }
    void print(std::ostream &os) const
    {
        os << real << "+" << imag << "i";
    }
};

Complex &Complex::operator+=(const Complex &c)
{
    real += c.real;
    imag += c.imag;
    return *this;
}

int main(void)
{
    Complex a(1.0, 2.0);
    Complex b(3.0, 4.0);
    Complex c;
    std::cout << "a=";
    a.print(std::cout);
    std::cout << std::endl;
    std::cout << "b=";
    b.print(std::cout);
    std::cout << std::endl;
    std::cout << "a+=bを実行してcに代入" << std::endl;
    c = (a += b);
    std::cout << "c=";
    c.print(std::cout);
    std::cout << std::endl;
    return 0;
}