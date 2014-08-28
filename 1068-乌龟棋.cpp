#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 类似爬楼梯，一次走1/2步，只不过这里变成了4种情况
// 动态规划，枚举所有的情况(数据保证必须使用所有卡片才能走到终点)
// score[i][j][k][l]，表示用i张1卡，j张2卡，k张3卡，l张4卡最多能获得的分数。
// 转移方程：
// score[i][j][k][l] = max{ score[i-1][j][k][l]+a[(i-1)+j*2+k*3+l*4+1] ,
//                          score[i][j-1][k][l]+a[i+(j-1)*2+k*3+l*4+2] ,
//                          score[i][j][k-1][l]+a[i+j*2+(k-1)*3+l*4+3] ,
//                          score[i][j][k][l-1]+a[i+j*2+k*3+(l-1)*4+4] }
// a[m]表示第m个格子，从0开始

int main()
{
    int n,m;
    cin >> n >> m;
    cout << "reach here 0" << endl;
    int num[4];            // num of cards
    vector<int> a(n, 0);   // score of each gird
    int score[41][41][41][41];  // max score
    cout << "reach here 1" << endl;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << "reach here" << endl;
    for (int i = 0; i < m; ++i)
    {
        int tmp;
        cin >> tmp;
        num[tmp-1]++;
    }
    cout << num[0] << ", " << num[1] << ", "  << num[2] << ", "  << num[3] << endl;

	memset(score, 0, sizeof(score));
    score[0][0][0][0] = a[0];         // init, in a[0]
    for (int i = 0; i <= num[0]; ++i)
    {
        for (int j = 0; j <= num[1]; ++j)
        {
            for (int k = 0; k <= num[2]; ++k)
            {
                for (int l = 0; l <= num[3]; ++l)
                {
                    int step = i + j*2 + k*3 + l*4;
                    if (i)
                        score[i][j][k][l] = max(score[i][j][k][l], score[i-1][j][k][l] + a[step]);
                    if (j)
                        score[i][j][k][l] = max(score[i][j][k][l], score[i][j-1][k][l] + a[step]);
                    if (k)
                        score[i][j][k][l] = max(score[i][j][k][l], score[i][j][k-1][l] + a[step]);
                    if (l)
                        score[i][j][k][l] = max(score[i][j][k][l], score[i][j][k][l-1] + a[step]);
                    cout << score[i][j][k][l] << endl;
                }
            }
        }
    }
    cout << score[num[0]][num[1]][num[2]][num[3]] << endl;
    return 0;
}
