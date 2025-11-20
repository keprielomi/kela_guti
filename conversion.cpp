// Write a program to convert a numerical number to its binary number
#include<iostream>
#include<string>
using namespace std;


//apok kela
class conversion {
private:
    int a;

public:
    friend void test1(conversion x);  // friend function declaration
    void set_ab(int i);               // setter
};

// using scope resolution
void conversion::set_ab(int i) {
    a = i;
}

// friend function definition
void test1(conversion x) {
    int n = x.a;

    if (n == 0) {
        cout << "0";
        return;
    }

    string binary = "";

    while (n > 0) {
        int rem = n % 2;
        binary = char(rem + '0') + binary; // prepend remainder
        n /= 2;
    }

    cout << binary;
}

int main() {
    conversion o;
    o.set_ab(80);

    cout << "Converted binary is: ";
    test1(o);  
    cout << endl;

    return 0;
}
