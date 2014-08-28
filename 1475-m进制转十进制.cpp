#include <iostream>
#include <vector>
using namespace std;

int geta(char a)
{
    int b;
    if ((a >= '0') && (a <= '9'))
        b = a - '0';
    else
        b = a - 'A' + 10;
    return b;
}

int main()
{
    string n;
    int m;
    
    while (cin >> n >> m)
    {
        int sum = 0;
        for (int i = 0; i < n.size(); ++i)
            sum = sum * m + geta(n[i]);
            
        cout << sum << endl;
    }
    return 0;
}