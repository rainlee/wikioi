// ֱ��͵�����ÿ⺯����
// �����ò�������ܷ���
#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    multiset<int> msdata;
    
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        msdata.insert(a);
    }
    
    for (multiset<int>::iterator it = msdata.begin(); it != msdata.end(); ++it)
    {
        if (it != msdata.begin())
            cout << " ";
        cout << *it;
    }
    cout << endl;
    
    return 0;
}