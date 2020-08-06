#include <iostream>
#include <limits>
#include <vector>
using namespace std;
/*
    Big-Endian：高位字节在前，低位字节在后。若系统中栈向低地址方向分配，则高字节在低地址，低字节在高地址
    Little-Edian：低位字节在前，高位字节在后。若系统中栈向低地址方向分配，则高字节在高地址，低字节在低地址.
    Windows,Linux, ARM均采用Little Edian, Mac采用Big-Edian.
    X86系统中,Stack分配往低地址方向增长，Heap分配向高地址方向增长，
*/
void CheckEdian() {
    int x = 0x02;
    char* ptr = (char*) &x;
    if (*ptr == 0x02)
        cout<< "Little-endian\n"<<endl;
    else
        cout << "Big-endian\n" << endl;
}
// Swap Edian
 void SwapEndian(void* pSrc, void* pDst, int len) 
{
    char* ptrSrc = (char*) pSrc;
    char* ptrDst = (char*) pDst;

    for(int i = len - 1; i>=0;i--)
    {
        *(ptrDst + i) = *ptrSrc;
        ptrSrc++;
    }
}
void DisplayInBinary(void* pData, int len) 
{
    //change the pointer type to char*
    char* ptr = (char*) pData;

    // X86系统采用Little-Edian,Stack分配往低地址方向增长，Heap分配向高地址方向增长，
    // 高字节在高地址，低字节在低地址，因此先让指针指向高字节，才能确保按顺序打印
    unsigned char Flag = 0x80;
    ptr += (len - 1);
    for (int i = 0; i < len; i++) 
    {
        Flag = 0x80;
        for (int j = 0; j < 8; j++)
        {
            if (*ptr& Flag)
                cout << 1;
            else
                cout << 0;
            Flag >>= 1;
        }
        ptr--;
    }
    cout << "\n";
}

int main()
{
    CheckEdian();
    // bool
    cout << "sizeof(bool)=1:" << sizeof(bool) << endl << endl;

    // char
    cout << "sizeof(char)=1:" << sizeof(char) << endl;
    cout << "sizeof(unsigned char)=1:" << sizeof(unsigned char) << endl;
    cout << "sizeof(char16_t)=2:" << sizeof(char16_t) << endl;
    cout << "sizeof(char32_t)=4:" << sizeof(char32_t) << endl;
    cout << "sizeof(wchar_t)=2:" << sizeof(wchar_t) << endl << endl;

    // integers: short, int(=long int), long long
    cout << "sizeof(short=short int)=2:" << sizeof(short) << endl;
    cout << "sizeof(unsigned short int)=2" << sizeof(unsigned short) << endl << endl;

    cout << "sizeof(int)=4:" << sizeof(int) << endl;
    cout << "sizeof(unsigned int)=4:" << sizeof(unsigned) << endl << endl;

    cout << "sizeof(long int)=4:" << sizeof(long) << endl;
    cout << "sizeof(unsigned long int)=4:" << sizeof(unsigned long) << endl << endl;

    cout << "sizeof(long long int)=8:" << sizeof(long long) << endl;
    cout << "sizeof(unsigned long long int)=8:" << sizeof(unsigned long long) << endl << endl;

    // float and doble
    cout << "sizeof(float)=4:" << sizeof(float) << endl;
    cout << "sizeof(double)=8:" << sizeof(double) << endl;

    cout << "sizeof(long double)=8:" << sizeof(long double) << endl << endl;
    
    // pointers
    cout << "sizeof Pointer,X86=4,X64=8:" << sizeof(int*) << endl;
    cout << "sizeof decltype(nullptr), X86=4,X64=8:" << sizeof(decltype(nullptr)) << endl << endl;  // for null pointer

    // Example of return limits
    cout << "int Min = " << numeric_limits<int>::min() << endl;
    cout << "int Max = " << numeric_limits<int>::max() << endl;
    cout << "Is int signed? = " << numeric_limits<int>::is_signed << endl;
    cout << "Non-signed bits of int = " << numeric_limits<int>::digits << endl << endl;

    /*
        b. 隐式转换规则：
            规则 1：char、short 和 unsigned short 值在计算式中自动Upgrade为 int 值。
            规则 2：当运算符使用不同数据类型的两个值时，较低容量的值将被升级为较高容量值的类型。
            规则 3：当表达式的最终值分配给变量时，将被转换为该变量的数据类型。
        隐式转换过程发生在表达式在工作区的计算过程中，原变量的值不会发生变化。
        c. 降级规则：
            i. 空间大的类型转换为小容量类型时，会导致数据丢失(如float或double转换为int时，会丢弃小数部分)，导致不准确的结果。
            ii. 负数转化为无符号类型，通常会采用二进制补码表示。 (编译器不警告有符号和无符号整数类型之间的隐式转换)
            iii.无论是转换到bool类型或者是有bool类型进行转换： false等价于0(数值类型)或者空指针(指针类型)； true则等价于其它任何数值或者由true转化为1。
    */
    float fData = 1.54;
    int iData = fData;
    cout << "1.54 coverted to int="<<iData << endl;

    int a = -2;
    bool b = a;
    cout << a <<" to bool =" << b << endl;

    b=static_cast<bool> (a);
    cout << a << " static_cst to bool =" << b << endl;
    
    int iNegtive = -2;
    unsigned iPositive = iNegtive;
    cout << iNegtive << " coverted to usinged int=" << iPositive << endl;
    DisplayInBinary(&iPositive, sizeof(iPositive));

    iPositive = static_cast<unsigned>(iNegtive);
    cout << iNegtive << " static_cast to usinged int=" << iPositive << endl;
    DisplayInBinary(&iPositive, sizeof(iPositive));

    int tmp = 0;
    cout << "swap Endian:" << endl;
    SwapEndian(&iPositive, &tmp, sizeof(iPositive));
    DisplayInBinary(&tmp, sizeof(tmp));

    // user defined
    enum color {red,green=5,blue} c = blue;
    cout << c << endl;

    // union: all member will share same memory
    union MyUnion 
    {
        char c;
        int a;
    }test;
    test.a = 1;
    if (test.c == 1)
        cout << "little endian" << endl;
    else cout << "big endian" << endl;

    // Array
    //int iArrany[];

    // Vector
    vector<int> vectorData = {1,2,3};
    vectorData.push_back(100);
    cout << vectorData[vectorData.size() - 1] << endl;

    cout << vectorData.at(1)<< endl;
}
