#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a, b;
    
    while (cin >> a >> b)
    	cout << ((abs(a-b) <= 1e-8) ? "yes" : "no") << endl;
        
    return 0;
}