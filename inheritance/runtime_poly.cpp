#include <iostream>

class Customer
{
    int custid;
    std::string custname;
    std::string mobno;

public:
    Customer(int id, std::string name, std::string mob) : custid(id), custname(name), mobno(mob) {}
    virtual void makeCall(int nmins)
    {
        std::cout << "Base -- makeCall\n";
    }
    virtual void credit(int amount)
    {
        std::cout << "Base -- credit\n";
    }
    virtual double getBalance() const { return 0; };
    virtual void display() const
    {
        std::cout << "Base -- display\n";
        std::cout << custid << "," << custname << "," << mobno << "\n";
    }
};

class PrepaidCustomer : public Customer
{
    double balance;
    int validity;

public:
    PrepaidCustomer(int id, std::string name, std::string mob, double bal, int x) : Customer(id, name, mob), balance(bal), validity(x) {}
    void makeCall(int nmins)
    {
        std::cout << "PrepaidCustomer -- makeCall\n";
        balance -= nmins;
    }
    void credit(int amount)
    {
        std::cout << "PrepaidCustomer -- credit\n";
        balance += amount;
    }
    double getBalance() const
    {
        return balance;
    }
    void display() const
    {
        std::cout << "PrepaidCustomer -- display\n";
        Customer::display();
        std::cout << "Balance: " << balance << ", " << "validity: " << validity << "\n";
    }
};

class PostpaidCustomer : public Customer
{
    double creditpoints;
    int duedate;

public:
    PostpaidCustomer(int id, std::string name, std::string mob, double cre, int x) : Customer(id, name, mob), creditpoints(cre), duedate(x) {}
    void makeCall(int nmins)
    {
        std::cout << "PostpaidCustomer -- makeCall\n";
        creditpoints += nmins;
    }
    void credit(int amount)
    {
        std::cout << "PostpaidCustomer -- credit\n";
        creditpoints -= amount;
    }
    double getBalance() const
    {
        return creditpoints;
    }
    void display() const
    {
        std::cout << "PostpaidCustomer  -- display\n";
        Customer::display();
        std::cout << "Credit points: " << creditpoints << ", " << "duedate: " << duedate << "\n";
    }
};

int main()
{

    PrepaidCustomer preobj(1001, "Richard", "9812341234", 600, 45);
    PostpaidCustomer postobj(1002, "Jack", "9678907890", 100, 45);
    Customer *pc = nullptr;

    int choice = 0;
    std::cin >> choice;

    if (choice == 1)
    {
        pc = &preobj; // upcasting - Customer type pointer holding address of PrepaidCustomer object
    }
    else
    {
        pc = &postobj; // upcasting - Customer type pointer holding address of PostpaidCustomer object
    }

    // operations based on the upcasted pointer/reference
    pc->makeCall(100);
    pc->credit(50);
    pc->display();

    return 0;
}