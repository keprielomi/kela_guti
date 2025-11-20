#include <iostream>
using namespace std;

class B;  // Forward declaration (tells compiler that B exists)

class A {
private:
    int numA;  // private member
public:
    A() : numA(5) {}  // constructor initializes numA = 5

    // Friend function declaration - now showSum can access numA
    friend void showSum(A, B);   
};

class B {
private:
    int numB;  // private member
public:
    B() : numB(10) {}  // constructor initializes numB = 10

    // Friend function declaration - showSum can access numB too
    friend void showSum(A, B);
};

// Friend function definition
// Not a member of any class, but still allowed to access numA and numB
void showSum(A objA, B objB) {
    cout << "Sum = " << objA.numA + objB.numB << endl;
}

int main() {
    A a;
    B b;

    showSum(a, b);  // Friend function used
    return 0;
}
