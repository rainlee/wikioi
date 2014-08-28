#include <iostream>
using namespace std;

int main()
{
    int n;
    int max,min;
    
    while (cin >> n)
    {
        int temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if (0 == i)
            {
                max = min = temp;
            }
            else
            {
                if (temp > max)
                    max = temp;
                if (temp < min)
                    min = temp;
            }
        }
        cout << min << " " << max << endl;
    }
    return 0;
}