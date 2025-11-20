#include <iostream>
#include<string>
using namespace std;
class student{
    public:
    string name;
    int rollno;
    student();//constructor declaration
};
student::student(){
    name="John";
    rollno=140;
}
int main(){
    student st;
    cout<<"Sudent Name:"<<st.name<<"\t"<<"Rollno:"<<st.rollno<<endl;
    return 0;
}
