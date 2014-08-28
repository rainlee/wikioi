#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
int main()
{
    string s;
    string t;
    
    while (cin >> s >> t)
        cout << s.find(t, 0)+1 << endl;
	return 0; 
}
*/

// KMP
void get_nextval(const string &t, vector<int> &next)
{
    const int m = t.size();
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < m-1)
    {
        if ((-1 == k) || (t[j] == t[k]))
        {
            ++k;
            ++j;
            if (t[k] != t[j])
                next[j] = k;
            else
                next[j] = next[k];
        }
        else
            k = next[k];
    }
}

int kmp(const string &s, const string &t)
{
    const int n = s.size();
    const int m = t.size();
    
    vector<int> next(m, 0);
    get_nextval(t, next);
    
    int i = 0;
    int j = 0;
    while ((i < n) && (j < m))
    {
        if ((-1 == j) || (s[i] == t[j]))
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j >= m)
        return i - j;
    else
        return -1;
}

int main()
{
    string s,t;
    while (cin >> s >> t)
        cout << (kmp(s, t) + 1) << endl;
    return 0;
}