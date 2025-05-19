#include <iostream>

class Base {
    int x;
  public:
    Base(int p) : x(p) {}
    void printx() { std::cout << x << "\n"; }
};

class Derived : public Base {
    int y;
  public:
    Derived(int p, int q) : Base(p),y(q) { }
    void printy() { std::cout << y << "\n"; }
    void printxy() {
      Base::printx();
      printy();
    }
};

int main() {
  
    Base b1(10);
    Derived d1(11, 22);
  
    Base *bp1 = &b1;        // allowed as pointer and object are of Base type
    Derived *dp1 = &d1;     // allowed as pointer and object are of Derived type
    Base *bp2 = &d1;        // upcasting, allowed, implicit conversion
    // Derived *dp2 = &b1;  // downcasting, not allowed, compiler error by default
   
    Base &br1 = b1;        // allowed as reference and object are of Base type
    Derived &dr1 = d1;     // allowed as reference and object are of Derived type 
    Base &br2 = d1;        // upcasting, allowed, implicit conversion
    // Derived &dr2 = b1;  // downcasting, not allowed, compiler error by default

    Base *bhp1 = new Base(10);           // allowed as pointer and heap object are of Base type
    Derived *dhp1 = new Derived(11, 12); // allowed as pointer and heap object are of Derived type
    Base *bhp2 = new Derived(11, 12);    // upcasting, allowed, implicit conversion
    // Derived *dhp2 = new Base(10);     // downcasting, not allowed, compiler error by default
  
    delete bhp1;
    delete dhp1;
    delete bhp2;
    // delete dhp2;
  
    return 0;
}