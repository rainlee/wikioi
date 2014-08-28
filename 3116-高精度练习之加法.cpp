#include <iostream>
using namespace std;

int main()
{
    string sa(""), sb(""), sc("");
    
    cin >> sa >> sb;
    int c = 0;    
    for (int i = 0; (i < sa.size()) || (i < sb.size()); ++i)
    {
        int a = (i < sa.size()) ? (sa[sa.size() - i - 1] - '0') : 0;
        int b = (i < sb.size()) ? (sb[sb.size() - i - 1] - '0') : 0;
        int sum = a + b + c;
        c = sum / 10;
        sum %= 10;
        sc = (char)(sum + '0') + sc;
    }
    if (c)
        sc = '1' + sc;
    cout << sc << endl;
    
    return 0;
}