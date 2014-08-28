#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return (a.second < b.second);
}

// �ſ�����
// �ž�����ĿΣ�����ͻ
// �Ȱ�����ʱ������ѡ������ģ�̰�ģ�
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
            cin >> a >> b;  // �����˵㡭��
            vvline[i].first = (a <= b) ? a : b;
            vvline[i].second = (a >= b) ? a : b;
        }
        sort(vvline.begin(), vvline.end(), cmp);
        
        int lmax = -1000;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (vvline[i].first >= lmax) // ������
            {
                cnt++;
                lmax = vvline[i].second;
            }
        }
        cout << cnt << endl;
    //}
        
    return 0;
}