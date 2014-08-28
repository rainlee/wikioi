#include <iostream>
using namespace std;

int main()
{
    int n;
    
        while (cin >> n) {    
        int fz=1, fm=1;   // 先找到在哪一行，然后再模拟遍历该行
        int i = 0;
        while (++i)
            if (i * (i + 1)/2 >= n)
                break;
        if (i%2) // 奇数
        {
            fz = i;
            fm = 1;
        }
        else
        {
            fz = 1;
            fm = i;
        }
        n -= i * (i - 1)/2;
        while (--n > 0)
        {
            if (i %2)
            {
                fz--;
                fm++;
            }
            else
            {
                fz++;
                fm--;
            }
        }
        cout << fz << "/" << fm << endl;
    }
    return 0;
}