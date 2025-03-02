#include <iostream>
using namespace std;

class DeepCopy {
public:
    int* data;

    // Constructor
    DeepCopy(int val) {
        data = new int(val); // Dynamic memory allocation
    }

    // Deep Copy Constructor
    DeepCopy(const DeepCopy& obj) {
        data = new int(*obj.data); // Allocating new memory & copying value
    }

    ~DeepCopy() {
        delete data; // Free memory to prevent memory leaks
    }

    void display() {
        cout << "Value: " << *data << endl;
    }
};

int main() {
    DeepCopy obj1(10);
    DeepCopy obj2 = obj1; // Deep copy occurs

    obj1.display();  // Output: Value: 10
    obj2.display();  // Output: Value: 10

    // Modifying obj2 does NOT affect obj1
    *obj2.data = 20;

    obj1.display();  // Output: Value: 10 (unchanged)
    obj2.display();  // Output: Value: 20 (modified)

    return 0;
}
