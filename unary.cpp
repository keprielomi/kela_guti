#include <iostream>
using namespace std;

class Number {
    int x, y;  // Two integer data members

public:
    // Constructor: initializes x and y with provided values
    Number(int a, int b) {
        x = a;
        y = b;
    }

    // Unary minus operator overloading
    // This will flip the sign of both x and y when "-object" is used
    void operator - () {
        x = -x;  // Negate x
        y = -y;  // Negate y
    }

    // Function to print current values of x and y
    void display() {
        cout << "x = " << x << ", y = " << y << endl;
    }

    int main() {
        Number n1(5, -10); // Create object with x=5, y=-10

        cout << "Before overloading: ";
        n1.display();      // Display initial values

        -n1;               // Calls operator-() → negates both x and y

        cout << "After overloading: ";
        n1.display();      // Display values after applying unary minus

        return 0;
    }
};
