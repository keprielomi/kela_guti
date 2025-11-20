#include <iostream>
using namespace std;

class Distance {
    int feet;
    int inches;

public:
    // Constructor that initializes feet and inches (default values = 0)
    Distance(int f = 0, int i = 0) {
        feet = f;
        inches = i;
    }

    // Binary '+' operator overloading function
    // This function adds two Distance objects: the current object and object 'd'
    Distance operator + (Distance d) {
        Distance temp; // Temporary object to store the result

        // Add feet of both objects
        temp.feet = feet + d.feet;

        // Add inches of both objects
        temp.inches = inches + d.inches;

        // If inches exceed 12, convert extra inches into feet
        if (temp.inches >= 12) {
            temp.feet += temp.inches / 12; // add the extra feet
            temp.inches = temp.inches % 12; // store remaining inches
        }

        // Return the final Distance object
        return temp;
    }

    // Display function to print the distance
    void display() {
        cout << feet << " feet " << inches << " inches" << endl;
    }
};

int main() {
    Distance d1(5, 8);     // First Distance object
    Distance d2(3, 9);     // Second Distance object

    Distance d3 = d1 + d2; // Calls operator+() to add two objects

    cout << "Total Distance: ";
    d3.display();          // Shows the result

    return 0;
}
