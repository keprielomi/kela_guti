#include <iostream>
#include <stdexcept>   // std::out_of_range
using namespace std;

const int SIZE = 10;  // compile-time constant array size used by the template

template <class AType>
class atype {
    AType a[SIZE];   // fixed-size array of AType elements
public:
    atype() {        // default constructor
        for (int i = 0; i < SIZE; ++i)
            a[i] = static_cast<AType>(i); // initialize each element
    }

    // non-const subscript operator (returns reference)
    AType &operator[](int i) {
        if (i < 0 || i >= SIZE) {
            throw out_of_range("Index out of bounds");
        }
        return a[i];
    }

    // const subscript operator
    const AType &operator[](int i) const {
        if (i < 0 || i >= SIZE) {
            throw out_of_range("Index out of bounds");
        }
        return a[i];
    }
};

int main() {
    try {
        atype<int> intob;        // instantiate template for int
        atype<double> doubleob;  // instantiate template for double

        cout << "Integer array: ";
        for (int i = 0; i < SIZE; ++i) intob[i] = i;
        for (int i = 0; i < SIZE; ++i) cout << intob[i] << " ";
        cout << '\n';

        cout << "Double array: ";
        for (int i = 0; i < SIZE; ++i) doubleob[i] = static_cast<double>(i) / 3.0;
        for (int i = 0; i < SIZE; ++i) cout << doubleob[i] << " ";
        cout << '\n';

        // Deliberate out-of-bounds test (uncomment to see exception)
        // intob[12] = 100;

    } catch (const std::out_of_range &e) {
        cerr << "Runtime error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
