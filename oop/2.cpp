#include <iostream>

using namespace std;

class Employee {
public:
    string Name;
    int Age;

    Employee(string name, int age) {
        Name = name;
        Age = age;
    }

    void Introduce() {
        cout << "Name: " << Name << ", Age: " << Age << endl;
    }
};

int main() {
    Employee employee1 = Employee("Debmalya Sur", 21);
    employee1.Introduce();

    return 0;
}