#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    
    // 从内向外逆时针不太好控制边界，不妨从外向内顺时针，从n*n开始
    while (cin >> n)
    {
        vector<vector <int> > vvsnake(n, vector<int>(n));
                
        int maxx = n - 1;
        int maxy = n - 1;
        int minx = 0;
        int miny = 0;
        int x, y;
        int n2 = n*n;
        int cnt = n2;
        while (cnt > 0)
        {
            x = maxx;
            y = maxy;
            while (y >= miny)
                vvsnake[x][y--] = cnt--;
            maxx--;
            
            x = maxx;
            y = miny;
            while (x >= minx)
                vvsnake[x--][y] = cnt--;
            miny++;
            
            x = minx;
            y = miny;
            while (y <= maxy)
                vvsnake[x][y++] = cnt--;
            minx++;
            
            x = minx;
            y = maxy;
            while (x <= maxx)
                vvsnake[x++][y] = cnt--;
            maxy--;
        }
        
        // output
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (j > 0)
	                cout << " ";
                cout << vvsnake[i][j];
                
                if ((i == j) || (i+j == n-1))
                    sum += vvsnake[i][j];
            }
            cout << endl;
        }
        cout << sum << endl;
    }
    return 0;
}