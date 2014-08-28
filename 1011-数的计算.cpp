#include <iostream>
#include <cmath>
using namespace std;

int g_cnt;
    
void addanum(int n, int sum)
{
    for (int i = 1; i <= n/2; ++i)
    {
        g_cnt++;
        int addn = i * pow(10, (int)log10(sum-1)+1);
        sum += addn;
        // cout << sum << endl;
        addanum(i, sum);
        sum -= addn;
    }
}

int main()
{
    int n;
    
    while (cin >> n)
    {
        g_cnt = 1;
        //cout << n << endl;
        int sum = n;
        addanum(n, sum);
        cout << g_cnt << endl;
    }
    return 0;
}