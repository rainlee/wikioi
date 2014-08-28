#include <iostream>
#include <cmath>
using namespace std;

bool isPrimer(int a)
{
    if ((a > 2) && (a%2 == 0))
        return false;
    
    int sqrta = sqrt(a) + 1;    
    for (int i = 3; i <= sqrta; i += 2)  // 检查2-sqrt(a)的所有奇数
        if (0 == a%i)
        	return false;
    return true;
}

int main()
{
    int a;
    while (cin >> a)
    {
        if (isPrimer(a))
            cout << "\\t";
        else
            cout << "\\n";
    }
    return 0;
}