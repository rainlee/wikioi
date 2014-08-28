#include <iostream>
using namespace std;

int main()
{
    int n;
    int sum = 0;
    int temp;
    
    cin >> n;
    while (n--)
    {
        cin >> temp;
        sum += temp;
    }
    cout << sum << endl;
    
    return 0;
}
		