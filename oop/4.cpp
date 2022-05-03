// Abstraction
// Hiding complex things behind the function
// It makes debuging or the future development easy!

#include <iostream>

using namespace std;

class AbstractEmployee {
    // this is a contract. In other words, it's an abstract class
    virtual void AskForPromotion() = 0; // this is one rule for the abstract class,
    // which is also a pure virtual function
};

class Employee : AbstractEmployee { // syntax that, Employee class is signing for AbstractEmployee contract
// Now the methods of AbstractEmployee class, have to be overwritten in this class
private:
    string Name;
    int Age;

public:
    Employee(string name, int age) {
        Name = name;
        Age = age;
    }

    void AskForPromotion() {
        if (Age > 30)
            cout << Name << " got a promotion!" << endl;
        else
            cout << Name << ", sorry no promotion for you" << endl;
    }
};

int main() {
    Employee employee1 = Employee("Debmalya Sur", 21);
    employee1.AskForPromotion();

    return 0;
}