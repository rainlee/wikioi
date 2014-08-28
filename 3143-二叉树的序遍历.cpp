#include <iostream>
#include <vector>
using namespace std;

void preOrder(vector<pair<int, int> > &vtree, int inode)
{
    cout << inode << " ";
    
    if (vtree[inode].first != 0)   // left child
        preOrder(vtree, vtree[inode].first);
    if (vtree[inode].second != 0)  // right child
        preOrder(vtree, vtree[inode].second);
    return;
}

void inOrder(vector<pair<int, int> > &vtree, int inode)
{   
    if (vtree[inode].first != 0)   // left child
        inOrder(vtree, vtree[inode].first);
    
    cout << inode << " ";
    
    if (vtree[inode].second != 0)  // right child
        inOrder(vtree, vtree[inode].second);
    return;
}

void postOrder(vector<pair<int, int> > &vtree, int inode)
{
    if (vtree[inode].first != 0)   // left child
        postOrder(vtree, vtree[inode].first);
    if (vtree[inode].second != 0)  // right child
        postOrder(vtree, vtree[inode].second);
    
    cout << inode << " ";
    
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > vtree(n+1);  // 下标从1开始
    for (int i = 1; i <= n; ++i)
        cin >> vtree[i].first >> vtree[i].second;

    preOrder(vtree, 1);
    cout << endl;
    inOrder(vtree, 1);
    cout << endl;
    postOrder(vtree, 1);
    cout << endl;
    
    return 0;
}