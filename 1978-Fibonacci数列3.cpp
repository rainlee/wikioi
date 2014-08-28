#include <iostream>
using namespace std;

int main()
{
    int f[41] = {0, 1,};  // 把所有的都算出来
    for (int i = 2; i < 41; ++i)
        f[i] = f[i-1] + f[i-2];
    
    int n;
    while (cin >> n)
    	cout << f[n] << endl;
    
    return 0;
}