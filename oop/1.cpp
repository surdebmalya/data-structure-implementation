#include <iostream>

using namespace std;

class Employee {
public:
    string Name;
    int Age;

    void Introduce() {
        cout << "Name: " << Name << ", Age: " << Age << endl;
    }
};

int main() {
    Employee employee1;
    employee1.Introduce();
    // It will print the default values of the constructors, like: Name: , Age: 4194432

    return 0;
}