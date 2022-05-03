// Protected access modifier
/* 
Under this access modifier, the variables and methods can be 
accessed directly in the inherited classes also
*/

#include <iostream>

using namespace std;

class Employee {
private:
    int Age;

protected:
    string Name;

public:
    Employee(string name, int age) {
        Name = name;
        Age = age;
    }
};

class Developer: Employee {
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

    return 0;
}