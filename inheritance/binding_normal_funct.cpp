#include <iostream>

class Customer {
    int custid;
    std::string custname;
    std::string mobno;
  public:
    Customer(int id, std::string name, std::string mob) : custid(id), custname(name), mobno(mob) {}
    void makeCall(int nmins) { 
        std::cout << "Base -- makeCall\n";
    }
    void credit(int amount) {
        std::cout << "Base -- credit\n";
    }
    double getBalance() const { return 0; } ;
    void display() const {
        std::cout << "Base -- display\n";
        std::cout << custid << "," << custname << "," << mobno << "\n";
    }
};

class PrepaidCustomer : public Customer {
    double balance;
    int validity;
  public:
    PrepaidCustomer(int id, std::string name, std::string mob, double bal, int x): Customer(id, name, mob), balance(bal),validity(x) {}
    void makeCall(int nmins) {
        std::cout << "Derived -- makeCall\n";
        balance -= nmins;
    }
    void credit(int amount) {  
        std::cout << "Derived -- credit\n";
        balance += amount;
    }
    double getBalance() const{
        return balance;
    }
   void display() const {
       std::cout << "Derived -- display\n";
       Customer::display();
       std::cout << balance << "," << validity << "\n";
    }
};

int main() {
  int bal = 0;
  
  PrepaidCustomer pobj(1001, "Richard", "9845012345", 600, 45);
  // pobj.display();
  Customer *pc = &pobj; // upcasting - Base class pointer holding address of derived class object
  // Customer &rc = pobj;
  // Customer *ptr = new PrepaidCustomer(1001, "Richard", "9845012345", 600, 45);
  
  pc->makeCall(5);  // upcasted pointer calling overridden function
  // rc.makeCall(5);
  // ptr->makeCall(5);   
  
  pc->credit(100);  // upcasted pointer calling overridden function
  // rc.credit(100);
  // ptr->credit(100);  
  
  bal = pc->getBalance();    // upcasted pointer calling overridden function 
  // bal = rc.getBalance();    
  // bal = ptr->getBalance();    
  
  std::cout << "Final balance is : " << bal << "\n";

  pc->display(); // upcasted pointer calling overridden function
  // rc.display();  
  // ptr->display();
  
  // delete ptr;
  return 0;
}