// Demonstration of Function Templates (Single-Type and Two-Type Generics)

#include <iostream>
using namespace std;

/* ---------------------------------------------------------
   FUNCTION TEMPLATE 1: Single generic type
   Enables swapping of any two values of the same data type.
   --------------------------------------------------------- */
template <class X>
void swapargs(X &a, X &b)
{
    X temp;    // Temporary variable of type X
    temp = a;  
    a = b;     
    b = temp;  
}

/* ---------------------------------------------------------
   FUNCTION TEMPLATE 2: Two generic types
   Accepts two parameters of potentially different types
   and displays them.
   --------------------------------------------------------- */
template <class type1, class type2>
void myfunc(type1 x, type2 y)
{
    cout << x << " " << y << '\n';
}

int main()
{
    // Test data for swapargs()
    int i = 10, j = 20;
    double x = 10.1, y = 23.3;
    char a = 'x', b = 'z';

    // Before swapping
    cout << "Original i, j: " << i << ' ' << j << '\n';
    cout << "Original x, y: " << x << ' ' << y << '\n';
    cout << "Original a, b: " << a << ' ' << b << '\n';

    // Calling single-type template
    swapargs(i, j);       // Generates: swapargs<int>()
    swapargs(x, y);       // Generates: swapargs<double>()
    swapargs(a, b);       // Generates: swapargs<char>()

    // After swapping
    cout << "Swapped i, j: " << i << ' ' << j << '\n';
    cout << "Swapped x, y: " << x << ' ' << y << '\n';
    cout << "Swapped a, b: " << a << ' ' << b << '\n';

    // Calling two-type template
    myfunc(10, "I like C++");   // type1=int, type2=const char*
    myfunc(98.6, 19L);          // type1=double, type2=long

    return 0;
}
