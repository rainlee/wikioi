#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ��1��b�ֱ��a�е�ÿһλ��ˣ����õ��Ľ����ӡ�ע��a�еĸ�λ���油��
// ��2��a�е�ÿһλ��b�е�ÿһλ��ˣ�������ڶ�Ӧλ���ϣ�Ȼ���ٴ�����ÿһλ�Ľ�λ
int main()
{
    string sa(""), sb("");
    
    cin >> sa >> sb;
    if (sa == "0" || sb == "0")
    {
        cout << "0" << endl;
        return 0;
    }
    
    vector<int> vm(sa.size() + sb.size() - 1, 0);
    for (int i = 0; i < sa.size(); ++i)  // �Ӹ�λ����λ
        for (int j = 0; j < sb.size(); ++j)  // �ӵ�λ����λ
        //{
            vm[i + j] += (sa[i] - '0') * (sb[j] - '0');  // 0 ~ n-1, ��λ����λ
        	//cout << vm[i+j] << endl;
        //}
    int c = 0;
    string sm("");
    for (int i = vm.size()-1; i >= 0; --i)
    {
        int num = vm[i] + c;
        c = num / 10;
        num %= 10;
        sm = (char)(num + '0') + sm;
    }
    if (c)  // �������λ�Ľ�λ
        sm = (char)(c + '0') + sm;
    
    cout << sm << endl;
    
    return 0;
}