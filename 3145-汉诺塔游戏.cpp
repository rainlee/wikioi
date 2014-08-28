#include <iostream>
using namespace std;

// 把n个盘从a移动到c，辅助盘b
void hannoi(int n, char A, char B, char C)
{
    if (1 == n)
    	cout << n << " from " << A << " to " << C << endl;
    else
    {
        hannoi(n-1, A, C, B);  // 把n-1个从a移动到b，辅助盘c
        cout << n << " from " << A << " to " << C << endl;
        hannoi(n-1, B, A, C);  // 把n-1个从b移动到c，辅助盘a
    }
}

int step(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        sum = 2*sum + 1;
    return sum;
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << step(n) << endl;
        hannoi(n, 'A', 'B', 'C');
    }
    return 0;
}