#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return ((b == 0) ? a : gcd(b, a%b));
}
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;   // a*b�������
}
int main()
{
    int a, b;
    
    while (cin >> a >> b)
    {
        int cnt = 0;
        int ab = a * b;
    	for (int i = a; i <= b; ++i)  // ֻ�����һ�飬��ȷ��һ����
        {
            if (0 == b%i)
            {
                int j = ab / i;
                if (a == gcd(i, j))
                    cnt++;
            }
        }
		cout << cnt << endl;
    }
    return 0;
}