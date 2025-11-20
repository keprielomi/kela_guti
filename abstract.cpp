#include <iostream>
using namespace std;

// *****************************************************************
// Abstract Base Class
// *****************************************************************
class Shape {
public:
    // Pure virtual function:
    // - Declared with '= 0'
    // - Forces all derived classes to provide their own implementation
    // - Makes 'Shape' an abstract class (cannot create objects of it)
    virtual void draw() = 0;
};

// *****************************************************************
// Derived Class: Circle
// *****************************************************************
class Circle : public Shape {
public:
    // Overrides the pure virtual function from Shape
    // Provides Circle-specific behavior
    void draw() override {
        cout << "Drawing a Circle\n";
    }
};

// *****************************************************************
// Derived Class: Rectangle
// *****************************************************************
class Rectangle : public Shape {
public:
    // Overrides draw() for Rectangle
    void draw() override {
        cout << "Drawing a Rectangle\n";
    }
};

// *****************************************************************
// Main Function
// *****************************************************************
int main() {

    // You cannot create Shape objects because Shape is abstract.
    // But you CAN create objects of derived classes.
    Circle c;
    Rectangle r;

    // Base class pointer:
    // This enables run-time polymorphism.
    Shape* ptr;

    // Point ptr to Circle object
    ptr = &c;
    ptr->draw();   // Executes Circle::draw()

    // Point ptr to Rectangle object
    ptr = &r;
    ptr->draw();   // Executes Rectangle::draw()

    return 0;
}
