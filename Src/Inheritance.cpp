#include <iostream>
using namespace std;

class Base
{
    int iPrivate=1;
public:
    int iPublic=2;
protected:
    int iProtected=3;
};

class Derived:public Base
{
public:
    void display() 
    {
        cout << "From Base:" << iProtected << endl;
    }
};

int main()
{
    Derived d;
    d.display();

}
