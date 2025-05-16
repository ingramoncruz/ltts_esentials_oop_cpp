#include <iostream>
class Complex {
    int m_real;
    int m_imag;

public:
    Complex() {}

    Complex(int real, int imag) : m_real(real), m_imag(imag) {}

//     // Overloading the + operator
//     Complex operator+(const Complex& other) {
//         return Complex(m_real + other.m_real, m_imag + other.m_imag);
//     }

//     // Overloading the << operator for output
//     friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
//         os << c.m_real << " + " << c.m_imag << "i";
//         return os;
//     }
// };

// int main() {
//     Complex c1(3, 4);
//     Complex c2(1, 2);
//     Complex c3 = c1 + c2; // Using the overloaded + operator

//     std::cout << "Result of addition: " << c3 << std::endl; // Using the overloaded << operator
//     return 0;
// }

    void display() {
        // print m_real, m_imag in a+ib format
    }

    Complex add (const Complex& r2) { // c1.add(c2)
        int treal = m_real + r2.m_real; // this->m_real + r2.m_real
        int timag = m_imag + r2.m_imag;
        // Complex temp(treak, timag);
        // return temp;
        return Complex(treal, timag);
    }

    Complex multiply (const Complex& r2) { 
        // TODO
    }

    Complex subtract (const Complex& r2) { 
        // TODO
    }

    bool equals(const Complex& r2) { // c1.equals(c2)
        return (m_real == r2.m_real && m_imag == r2.m_imag);
    }

    //Overloading the << operator for output
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.m_real << " + " << c.m_imag << "i";
        return os;
    }
};

int main() {
    Complex c1(2, 3);
    Complex c2(4, 5);
    Complex c3, c4, c5;

    c3 = c1.add(c2); // add(c1, c2)
    std::cout << "Addition: " << c3 << std::endl;
    // c4 = c1.multiply(c2);

    if (c1.equals(c2))  // if(equals(c1, c2))
        std::cout << "c1 and c2 are equal" << std::endl;
    else
        std::cout << "c1 and c2 are not equal" << std::endl;
    
    return 0;
}