/* Write a program to calculate the area of a rectangle
   using the concept of operator overloading
*/

#include <iostream>
using namespace std;

class Rectangle {
private:
    int length, breadth;

public:
    // Constructor
    Rectangle(int l = 0, int b = 0) {
        length = l;
        breadth = b;
    }

    // Operator overloading for '*'
    int operator*(Rectangle r) {
        return length * breadth; // area of THIS rectangle
    }
};

int main() {
    int l, b;
    cout << "Enter length and breadth: ";
    cin >> l >> b;

    Rectangle r(l, b);

    cout << "Area = " << (r * r);  // using overloaded operator
    return 0;
}
