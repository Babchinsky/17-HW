#include <Windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;

typedef int (*FOO_IN_DLL)(int, int);

int main()
{
    HINSTANCE hInstLib = LoadLibrary(TEXT("DllFor16HW.dll"));

    if (hInstLib == NULL)
    {
        cout << "Can`t load library DllFor16HW.dll" << endl;
        return 0;
    }

    FOO_IN_DLL Sum = (FOO_IN_DLL)GetProcAddress(hInstLib, "Sum");

    if (Sum == NULL)
    {
        cout << "Can`t load function Sum" << endl;
    }
    else
    {
        cout << "Sum: " << Sum(3,2) << endl;
    }

    FOO_IN_DLL Difference = (FOO_IN_DLL)GetProcAddress(hInstLib, "Difference");
    if (Difference == NULL)
    {
        cout << "Can`t load function Difference" << endl;
    }
    else
    {
        cout << "Difference: " << Difference(3, 2) << endl;
    }

    FOO_IN_DLL Product = (FOO_IN_DLL)GetProcAddress(hInstLib, "Product");
    if (Product == NULL)
    {
        cout << "Can`t load function Product" << endl;
    }
    else
    {
        cout << "Product: " << Product(3, 2) << endl;
    }

    FOO_IN_DLL Quotient = (FOO_IN_DLL)GetProcAddress(hInstLib, "Quotient");
    if (Quotient == NULL)
    {
        cout << "Can`t load function Quotient" << endl;
    }
    else
    {
        cout << "Quotient: " << Quotient(3, 2) << endl;
    }


    FreeLibrary(hInstLib);
}