#include <iostream>
#include <vector>
using namespace std;

char gn2m[] = {
    '0', '1', '2', '3', '4', '5',
    '6', '7', '8', '9', 'A', 'B',
    'C', 'D', 'E',
};

int main()
{
    int n,m;
    
    while (cin >> n >> m)
    {
        if (0 == n)
        {
            cout << 0 << endl;
            continue;
        }
        vector<char> rem;
        while (n)
        {
            rem.push_back(gn2m[n%m]);
            n /= m;
        }
        
        for (int i = rem.size()-1; i >= 0; --i)
            cout << rem[i];
        cout << endl;
    }
    return 0;
}