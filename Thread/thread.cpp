#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
int main()
{
    cout << "Enter length of array" << endl;
    int size;
    cin >> size;
    int *ps = new int[size];
    for (int i = 0; i < size; i++)
        ps[i] = 3;
    int k = 4;
    SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
    while (k > 0)
    {
        for (int bi = 0; bi < size; bi++)
        {
            cout << ps[bi];
        }
        cout << endl;
        int i = size - 1;
        if (ps[i] == 3)
        {
            ps[i] = 4;
            continue;
        }
        if (ps[i] == 4)
        {
            while (ps[i] == 4)
            {
                ps[i] == 3;
                i--;
            }
            ps[i] = 4;
            if (i < k)
                k--;
        }
    }
    return 0;
}