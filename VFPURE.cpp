// Pure Virtual Functions Example
#include <iostream>
using namespace std;

// -----------------------------------------------------
// Base abstract class
// -----------------------------------------------------
class number {
protected:
    int val;     // Common data member
public:
    // Setter function for assigning value
    void setval(int i) { 
        val = i; 
    }

    // Pure virtual function (must be overridden)
    virtual void show() = 0;  
};

// -----------------------------------------------------
// Derived class: prints value in hexadecimal format
// -----------------------------------------------------
class hextype : public number {
public:
    void show() override {  
        cout << hex << val << "\n";   // Print in hex
    }
};

// -----------------------------------------------------
// Derived class: prints value in decimal format
// -----------------------------------------------------
class dectype : public number {
public:
    void show() override {  
        cout << val << "\n";          // Print in decimal
    }
};

// -----------------------------------------------------
// Derived class: prints value in octal format
// -----------------------------------------------------
class octtype : public number {
public:
    void show() override {  
        cout << oct << val << "\n";   // Print in octal
    }
};

// -----------------------------------------------------
// Main Function
// -----------------------------------------------------
int main() {
    dectype d;
    hextype h;
    octtype o;

    d.setval(20);
    d.show();   // Output: 20  (decimal)

    h.setval(20);
    h.show();   // Output: 14  (hexadecimal)

    o.setval(20);
    o.show();   // Output: 24  (octal)

    return 0;
}
