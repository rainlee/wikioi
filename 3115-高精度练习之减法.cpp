#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sa(""), sb(""), sc("");
    
    cin >> sa >> sb;
    bool lflag = false;  // if sa < sb
    if ((sa.size() < sb.size()) || ((sa.size() == sb.size()) && (sa.compare(sb) < 0)))
    {
        lflag = true;
        sa.swap(sb);
    }
    int c = 0;
    for (int i = 0; (i < sa.size()) || (i < sb.size()); ++i)
    {
        int a = (i < sa.size()) ? (sa[sa.size() - i - 1] - '0') : 0;
        int b = (i < sb.size()) ? (sb[sb.size() - i - 1] - '0') : 0;
        int sum = a - b + c;
        c = (sum < 0) ? -1 : 0;
        sum = (sum < 0) ? (10 + sum) : sum;
        if ((sum == 0) && (i == max(sa.size()-1, sb.size()-1)))
            break;
        sc = (char)(sum + '0') + sc;
    }
    if (lflag)
        sc = '-' + sc;
    cout << sc << endl;
    return 0;
}