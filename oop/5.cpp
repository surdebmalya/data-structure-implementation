// Inheritence

#include <iostream>

using namespace std;

class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee {
private:
    string Name;
    int Age;

public:
    Employee(string name, int age) {
        Name = name;
        Age = age;
    }

    string getName() {
        return Name;
    }

    void AskForPromotion() {
        if (Age > 30)
            cout << Name << " got a promotion!" << endl;
        else
            cout << Name << ", sorry no promotion for you" << endl;
    }
};

class Developer: Employee { // here inheritence happend
// now, all the public methods of Employee are also accessable from this class
public:
    string FavoriteProgrammingLanguage;
    Developer(string name, int age, string language): Employee(name, age) {
        FavoriteProgrammingLanguage = language;
    }

    void FixBug() {
        cout << getName() << " fixed bug using " << FavoriteProgrammingLanguage << endl;
    }
};

int main() {
    Developer d = Developer("Debmalya", 21, "C++");
    d.FixBug();

    return 0;
}