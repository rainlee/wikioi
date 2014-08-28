#include <iostream>
using namespace std;

// ��n���̴�a�ƶ���c��������b
void hannoi(int n, char A, char B, char C)
{
    if (1 == n)
    	cout << n << " from " << A << " to " << C << endl;
    else
    {
        hannoi(n-1, A, C, B);  // ��n-1����a�ƶ���b��������c
        cout << n << " from " << A << " to " << C << endl;
        hannoi(n-1, B, A, C);  // ��n-1����b�ƶ���c��������a
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