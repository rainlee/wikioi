#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return (a.second < b.second);
}

// 排课问题
// 排尽量多的课，不冲突
// 先按结束时间排序，选结束早的（贪心）
int main()
{
    int n;
    //while (cin >> n)
    //{
        cin >> n;
        vector<pair<int, int> > vvline(n, pair<int, int>(0,0));
        for (int i = 0; i < n; ++i)
        {
            int a,b;
            cin >> a >> b;  // 两个端点……
            vvline[i].first = (a <= b) ? a : b;
            vvline[i].second = (a >= b) ? a : b;
        }
        sort(vvline.begin(), vvline.end(), cmp);
        
        int lmax = -1000;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (vvline[i].first >= lmax) // 不覆盖
            {
                cnt++;
                lmax = vvline[i].second;
            }
        }
        cout << cnt << endl;
    //}
        
    return 0;
}