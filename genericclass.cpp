#include <iostream>
using namespace std;

// Generic Class
template <class T>
class Box {
private:
    T value;
public:
    Box(T v) { value = v; }
    void show() { cout << "Value: " << value << endl; }
};

// Generic Function with Two Types
template <class type1, class type2>
void myfunc(type1 x, type2 y) {
    cout << x << " " << y << "\n";
}

int main() {
    // Using Generic Class
    Box<int> intBox(10);         
    Box<double> doubleBox(3.14); 
    Box<string> stringBox("Hello");

    intBox.show();
    doubleBox.show();
    stringBox.show();

    // Using Generic Function
    myfunc(10, "I like C++");
    myfunc(98.6, 19L);

    return 0;
}
