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
    
    if (vtree[inode].first != 0)  // ����
        dfs(vtree, vlnodes, dep+1, vtree[inode].first);
    if (vtree[inode].second != 0)  // �Һ���
        dfs(vtree, vlnodes, dep+1, vtree[inode].second);
    return;
}

int main()
{
    int n;
    cin >> n;
    //vector<pair<int, int> > vtree(mdep, pair<int,int>(0, 0));
    vector<pair<int, int> > vtree(n+1);  // Ϊ���㣬��i���ǵ�i�����
    for (int i = 1; i <= n; ++i)
        cin >> vtree[i].first >> vtree[i].second;
    
    vector<int> vlnodes(n, 0);    // ÿ��Ľ����
    //vector<int> vlnodes(mdep, 0);    // ÿ��Ľ����, n���������������������
    maxdep = 0;
    dfs(vtree, vlnodes, 0, 1);   // 1�Ӹ��ڵ㿪ʼ
    
    int maxwidth = 0;    
    for (int i = 0; i <= maxdep; ++i)  // ���ᳬ��maxdep
        maxwidth = (vlnodes[i] > maxwidth) ? vlnodes[i] : maxwidth;
    
    cout << maxwidth << " " << (maxdep+1) << endl;  // dep��0��ʼ
        
    return 0;
}