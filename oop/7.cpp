// Inheritence-2

/*
Normally the inherited variables and methods are private, 
so to access them in the developer class also, you have
to use the "public" keyword while inheritence.
*/

#include <iostream>

using namespace std;

class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee {
private:
    int Age;

protected:
    string Name;
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

class Developer: public Employee {
// here we make the inheritence privates as private,
// public as public and same for protected also
public:
    string FavoriteProgrammingLanguage;
    Developer(string name, int age, string language): Employee(name, age) {
        FavoriteProgrammingLanguage = language;
    }

    void FixBug() {
        cout << Name << " fixed bug using " << FavoriteProgrammingLanguage << endl;
    }
};

int main() {
    Developer d = Developer("Debmalya", 21, "C++");
    d.FixBug();

    d.AskForPromotion();

    return 0;
}