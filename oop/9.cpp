// polymorphism-2
// virtual method

#include <iostream>

using namespace std;

class Employee {
protected:
    string Name;

public:
    Employee(string name) {
        Name = name;
    }
    virtual void Work() { // make this method virtual, so that it can check in runtime
        cout << Name << " is working" << endl;
    }
};

class Developer : public Employee {
private:
    string FavoriteProgrammingLanguage;

public:
    Developer(string name, string favoriteProgrammingLanguage) : Employee(name) {
        FavoriteProgrammingLanguage = favoriteProgrammingLanguage;
    }
    void Work() {
        cout << Name << " is developing using " << FavoriteProgrammingLanguage << endl;
    }
};

class Tester : public Employee {
public:
    Tester(string name) : Employee(name) {}
    void Work() {
        cout << Name << " is testing the software" << endl;
    }
};

int main() {
    Developer d = Developer("Debmalya Sur", "C++");
    Tester t = Tester("Jack");

    // We are creating a parent class ptr which is pointing the child class object
    Employee *e1 = &d;
    Employee *e2 = &t;
    e1->Work();
    e2->Work();

    return 0;
}