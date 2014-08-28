#include <iostream>
using namespace std;

int main()
{
    int price;
    float rate;
    
    while (cin >> price >> rate)
        cout << (int)(price * (rate/10) + 5)/10 * 10 << endl;
        
    return 0;
}