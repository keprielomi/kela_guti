#include <iostream>
#include <cstdlib>
#include <new>
using namespace std;

class loc {
    int longitude, latitude;
public:
    loc() {}                          // default
    loc(int lg, int lt) {             // parameterized
        longitude = lg;
        latitude = lt;
    }
    void show() {                     // print coords
        cout << longitude << " ";
        cout << latitude << "\n";
    }

    void *operator new(size_t size);  // class-specific new
    void operator delete(void *p);    // class-specific delete
};

// overloaded new: allocate raw memory, throw on failure
void *loc::operator new(size_t size)
{
    void *p;
    cout << "In overloaded new.\n";
    p = malloc(size);                 // use malloc for allocation
    if(!p) {
        bad_alloc ba;
        throw ba;                     // mimic standard new behavior
    }
    return p;
}

// overloaded delete: free memory allocated by malloc
void loc::operator delete(void *p)
{
    cout << "In overloaded delete.\n";
    free(p);
}

int main()
{
    loc *p1, *p2;

    try {
        p1 = new loc (10, 20);        // calls loc::operator new then constructor
    } catch (bad_alloc xa) {
        cout << "Allocation error for p1.\n";
        return 1;
    }

    try {
        p2 = new loc (-10, -20);      // same for p2
    } catch (bad_alloc xa) {
        cout << "Allocation error for p2.\n";
        return 1;
    }

    p1->show();                       // output: 10 20
    p2->show();                       // output: -10 -20

    delete p1;                        // calls destructor (none) then loc::operator delete
    delete p2;

    return 0;
}
