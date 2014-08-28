#include <iostream>
#include <vector>
using namespace std;

const int mdep = 100;

int maxdep;
void dfs(vector<pair<int, int> > &vtree, vector<int> &vlnodes, int dep, int inode)
{
    vlnodes[dep]++;
    maxdep = (dep > maxdep) ? dep : maxdep;
    //cout << "dep: " << dep << ", inode: " << inode << endl;
    
    if (vtree[inode].first != 0)  // 左孩子
        dfs(vtree, vlnodes, dep+1, vtree[inode].first);
    if (vtree[inode].second != 0)  // 右孩子
        dfs(vtree, vlnodes, dep+1, vtree[inode].second);
    return;
}

int main()
{
    int n;
    cin >> n;
    //vector<pair<int, int> > vtree(mdep, pair<int,int>(0, 0));
    vector<pair<int, int> > vtree(n+1);  // 为方便，第i行是第i个结点
    for (int i = 1; i <= n; ++i)
        cin >> vtree[i].first >> vtree[i].second;
    
    vector<int> vlnodes(n, 0);    // 每层的结点数
    //vector<int> vlnodes(mdep, 0);    // 每层的结点数, n是输入的行数，不是树深
    maxdep = 0;
    dfs(vtree, vlnodes, 0, 1);   // 1从根节点开始
    
    int maxwidth = 0;    
    for (int i = 0; i <= maxdep; ++i)  // 不会超过maxdep
        maxwidth = (vlnodes[i] > maxwidth) ? vlnodes[i] : maxwidth;
    
    cout << maxwidth << " " << (maxdep+1) << endl;  // dep从0开始
        
    return 0;
}