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

Complex operator+(const Complex &a, const Complex &b)
{
    double r = a.re() + b.re();
    double i = a.im() + b.im();
    return Complex(r, i);
}

Complex operator-(const Complex &a, const Complex &b)
{
    double r = a.re() - b.re();
    double i = a.im() - b.im();
    return Complex(r, i);
}

Complex operator*(const Complex &a, const Complex &b)
{
    double r = a.re() * b.re() - a.im() * b.im();
    double i = a.re() * b.im() + a.im() * b.re();
    return Complex(r, i);
}

int main(void)
{
    Complex a(1.00, 2.00);
    Complex b(3.00, 4.00);
    Complex c(2.35, 5.32);
    Complex s = c - b;
    s.print(std::cout);
    std::cout << std::endl;
    Complex t = a * b;
    t.print(std::cout);
    std::cout << std::endl;
    return 0;
}