#include <iostream>   // std::cout, std::endl
#include <cstdlib>    // exit()
using namespace std;

const int SIZE = 10;  // compile-time constant array size used by the template

// Declare a class template named 'atype' parameterized by AType
template <class AType>
class atype {
    AType a[SIZE];   // fixed-size array of AType elements
public:
    atype() {        // default constructor
        register int i;               // 'register' is a hint to compiler (obsolete)
        for(i = 0; i < SIZE; i++)
            a[i] = i;                 // initialize each element to the integer i (converted to AType)
    }
    AType &operator[](int i);         // overloaded subscript operator (returns reference)
}; // end of class template

// Provide range checking implementation for operator[]
template <class AType>
AType &atype<AType>::operator[](int i)
{
    if (i < 0 || i > SIZE - 1) {      // check for out-of-range index
        cout << "\nIndex value of ";
        cout << i << " is out-of-bounds.\n";
        exit(1);                      // terminate program immediately on error
    }
    return a[i];                      // return reference to element so it can be read or assigned
}

int main()
{
    atype<int> intob;        // instantiate template for int (integer array)
    atype<double> doubleob;  // instantiate template for double (double array)
    int i;

    cout << "Integer array: ";
    for(i = 0; i < SIZE; i++) intob[i] = i;         // assign values 0..9 to int array
    for(i = 0; i < SIZE; i++) cout << intob[i] << " "; // print int array
    cout << '\n';

    cout << "Double array: ";
    for(i = 0; i < SIZE; i++) doubleob[i] = (double) i / 3; // assign 0, 0.333..., ...
    for(i = 0; i < SIZE; i++) cout << doubleob[i] << " ";   // print double array
    cout << '\n';

    intob[12] = 100; // deliberate out-of-bounds access — triggers the range check and exits
    return 0;
}
