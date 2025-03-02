#include <iostream>
using namespace std;

class ShallowCopy {
public:
    int* data;

    // Constructor
    ShallowCopy(int val) {
        data = new int(val); // Dynamic memory allocation
    }

    // Copy Constructor (Default - Shallow Copy)
    ShallowCopy(const ShallowCopy& obj) {
        data = obj.data; // Copies the pointer, NOT the actual value
    }

    void display() {
        cout << "Value: " << *data << endl;
    }
};

int main() {
    ShallowCopy obj1(10);
    ShallowCopy obj2 = obj1; // Shallow copy occurs

    obj1.display();  // Output: Value: 10
    obj2.display();  // Output: Value: 10

    // Modifying obj2 also modifies obj1
    *obj2.data = 20;

    obj1.display();  // Output: Value: 20
    obj2.display();  // Output: Value: 20 (same memory)

    return 0;
}
