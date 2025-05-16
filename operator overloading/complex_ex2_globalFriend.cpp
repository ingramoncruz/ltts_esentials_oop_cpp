#include <iostream>
class Complex {
    int m_real;
    int m_imag;

public:
    Complex() {}

    Complex(int real, int imag) : m_real(real), m_imag(imag) {}

    void display() {
        // print m_real, m_imag in a+ib format
    }

    friend Complex add(const Complex& r1, const Complex& r2);
    friend Complex multiply(const Complex& r1, const Complex& r2);
    friend Complex subtract(const Complex& r1, const Complex& r2);
    friend bool equals(const Complex& r1, const Complex& r2);

    //Overloading the << operator for output
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.m_real << " + " << c.m_imag << "i";
        return os;
    }
};

Complex add(const Complex& r1, const Complex& r2) {
    return Complex(r1.m_real + r2.m_real, r1.m_imag + r2.m_imag);
}

Complex multiply(const Complex& r1, const Complex& r2) {
    return Complex(r1.m_real * r2.m_real - r1.m_imag * r2.m_imag,
                   r1.m_real * r2.m_imag + r1.m_imag * r2.m_real);
}

Complex subtract(const Complex& r1, const Complex& r2) {
    return Complex(r1.m_real - r2.m_real, r1.m_imag - r2.m_imag);
}

bool equals(const Complex& r1, const Complex& r2) {
    return (r1.m_real == r2.m_real && r1.m_imag == r2.m_imag);
}

int main() {
    Complex c1(2, 3);
    Complex c2(4, 5);
    Complex c3, c4, c5;

    c3 = add(c1, c2);
    c4 = multiply(c1, c2);
    c5 = subtract(c1, c2);
    std::cout << "Addition: " << c3 << std::endl;
    std::cout << "Multiplication: " << c4 << std::endl;
    std::cout << "Subtraction: " << c5 << std::endl;
    std::cout << "Equality: " << (equals(c1, c2) ? "Equal" : "Not Equal") << std::endl;

    return 0;
}