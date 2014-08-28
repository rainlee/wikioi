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
        
        // ̰��
        // ��ǰ�����룬ǰ�治�����油��ǰ���Ľ�������
        int avrg = sum / n;
        int step = 0;
        for (int i = 0; i < n; ++i)
        {
            if (avrg != vnum[i])
            {
                vnum[i+1] += vnum[i] - avrg;  // n-1�϶�������ģ�ǰ�涼�ź���
                step++;
            }
        }
        cout << step << endl;
    }
    return 0;
}