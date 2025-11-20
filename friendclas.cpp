#include <iostream>
using namespace std;

class TwoValues {
    int a;  // private data
    int b;  // private data

public:
    // Constructor to initialize a and b
    TwoValues(int i, int j) { 
        a = i; 
        b = j; 
    }

    // Declaring class Min as a friend
    // All member functions of Min can access a and b
    friend class Min;
};

class Min {
public:
    // Member function of Min that compares private values of TwoValues
    int min(TwoValues x) {
        // Directly accessing x.a and x.b even though they are private
        return x.a < x.b ? x.a : x.b;
    }
};

int main() {
    TwoValues ob(10, 20);
    Min m;

    cout << m.min(ob);  // prints the smaller of 10 and 20
    return 0;
}
