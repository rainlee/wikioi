#include <iostream>
using namespace std;

int g_cnt = 0;

void f(int n)
{
    if (1 == n)
        return;
    g_cnt++;
    if (n & 0x01)
        f(3*n + 1);
    else
        f(n/2);
    return;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        g_cnt = 0;
        cin >> n;
        f(n);
        cout << g_cnt << endl;
    }
    return 0;
}