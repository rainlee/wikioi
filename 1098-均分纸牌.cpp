#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> vnum(n);
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            int num;
            cin >> num;
            vnum[i] = num;
            sum += num;
        }
        
        // 贪心
        // 从前往后补齐，前面不够后面补，前面多的交给后面
        int avrg = sum / n;
        int step = 0;
        for (int i = 0; i < n; ++i)
        {
            if (avrg != vnum[i])
            {
                vnum[i+1] += vnum[i] - avrg;  // n-1肯定是满足的，前面都排好了
                step++;
            }
        }
        cout << step << endl;
    }
    return 0;
}