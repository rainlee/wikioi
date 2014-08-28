#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> srandom;
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        srandom.insert(a);
    }
    cout << srandom.size() << endl;
    
    for (set<int>::iterator it = srandom.begin(); it != srandom.end(); ++it)
    {
        if (it != srandom.begin())
            cout << " ";
        cout << *it;
    }
    cout << endl;
    
    return 0;
}