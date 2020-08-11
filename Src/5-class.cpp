# include <iostream>
using namespace std;

class Student
{
    
public:
    Student();
    Student(const string name);
    void set()
    {
        static int num =0;  // Visibility = function, lifetime =program
        n= ++num;
        cout<<num<<endl;
    }
    void print(string str){
        cout << str << "Num =: " << n << endl;
    }
};
Student::Student(const string name)
{
}
Student::Student()
{
}

void fun()
{
    Student s1;
    s1.set();
    s1.set();
    s1.print("2");
    
    Student s2;
    s2.set();
    s2.print("3");
    
    s1.print("4");
}

int main(int argc, char* argv[])
{
    Student s;
    s.set();
    s.print("1");
    
    fun();

    s.set();
    s.print("5");
 }