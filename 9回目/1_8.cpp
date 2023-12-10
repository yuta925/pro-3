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

std::ostream &operator<<(std::ostream &os, const Complex &c)
{
    c.print(os);
    return os;
}

int main(void)
{
    Complex a[3];
    a[0] = Complex(1.00, 2.00);
    a[1] = a[0] + Complex(0.00, 1.00);
    Complex *c = &(a[2]);
    *c = a[0];
    for (int i = 0; i < 3; i++)
        std::cout << a[i] << std::endl;
    Complex *b = new Complex[3];
    for (int i = 0; i < 3; i++)
        b[i] = a[i] + Complex(1.00, 1.00);
    for (size_t i = 0; i < 3; i++)
        std::cout << b[i] << std::endl;
    delete[] b;
    return 0;
}