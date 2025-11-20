#include <iostream>
#include <string>
using namespace std;

class student {
public:
    string name;
    int rollno;

    student();                                         // default constructor
    student(string n, int r);                          // parameterized constructor
    student(const student &obj);                       // copy constructor
    student(student &&obj) noexcept;                   // move constructor
};

// ------------------- Default Constructor -------------------
student::student() {           // default
    name = "John";
    rollno = 140;
}

// ---------------- Parameterized Constructor -----------------
student::student(string n, int r) {   // parameterized
    name = n;
    rollno = r;
}

// --------------------- Copy Constructor ---------------------
student::student(const student &obj) {   // copy
    name = obj.name;
    rollno = obj.rollno;
}

// --------------------- Move Constructor ---------------------
student::student(student &&obj) noexcept {   // move
    name = std::move(obj.name);
    rollno = obj.rollno;
    obj.rollno = 0;     // optional: reset moved-from object
}

int main() {
    student st1;                                    // calls default constructor
    student st2("Alice", 101);                      // calls parameterized constructor
    student st3(st2);                               // calls copy constructor
    student st4(std::move(st3));                    // calls move constructor

    cout << "Default: " << st1.name << " " << st1.rollno << endl;
    cout << "Param:   " << st2.name << " " << st2.rollno << endl;
    cout << "Copy:    " << st3.name << " " << st3.rollno << endl;
    cout << "Move:    " << st4.name << " " << st4.rollno << endl;

    return 0;
}
