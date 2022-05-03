// Encapsulation

#include <iostream>

using namespace std;

class Employee {
private:
    string Name;
    int Age;

public:
    Employee(string name, int age) {
        Name = name;
        Age = age;
    }
    void setName(string name) {
        Name = name;
    }
    string getName() {
        return Name;
    }
    void setAge(int age) {
        if (age >= 18)
            // through the getter and setter, you can validate the inputs
            Age = age;
    }
    int getAge() {
        return Age;
    }
    void Introduce() {
        cout << "Name: " << Name << ", Age: " << Age << endl;
    }
};

int main() {
    Employee employee1 = Employee("Debmalya Sur", 21);
    employee1.Introduce();
    employee1.setAge(14);
    employee1.Introduce(); // Same output as the previous one
    employee1.setAge(18);
    employee1.Introduce();

    return 0;
}