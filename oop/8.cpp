// polymorphism-1 
// poly + morph => many forms

#include <iostream>

using namespace std;

class Employee {
protected:
    string Name;

public:
    Employee(string name) {
        Name = name;
    }
    void Work() {
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

    d.Work();
    t.Work();

    return 0;
}