#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 法1：b分别和a中的每一位相乘，将得到的结果相加。注意a中的高位后面补零
// 法2：a中的每一位和b中的每一位相乘，结果放在对应位置上，然后再处理结果每一位的进位
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
    for (int i = 0; i < sa.size(); ++i)  // 从高位到低位
        for (int j = 0; j < sb.size(); ++j)  // 从低位到高位
        //{
            vm[i + j] += (sa[i] - '0') * (sb[j] - '0');  // 0 ~ n-1, 高位到低位
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
    if (c)  // 处理最高位的进位
        sm = (char)(c + '0') + sm;
    
    cout << sm << endl;
    
    return 0;
}