#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<deque>
#include <sstream>
#include <iomanip>
#define ll long long
using namespace std;
const int MAX = 100001;
int inorder[MAX], postorder[MAX], idx[MAX];

void preorder(int instart, int inend, int poststart, int postend){
    if(instart > inend || poststart > postend)
        return;
    int rootNode = idx[postorder[postend]];
    int leftSize = rootNode - instart;
    int rightSize = inend - rootNode;
    cout << inorder[rootNode] << " ";

    preorder(instart, rootNode-1, poststart, poststart + leftSize - 1);
    preorder(rootNode + 1, inend, poststart + leftSize, postend-1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> inorder[i];
        idx[inorder[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        cin >> postorder[i];
    }
    preorder(1,n,1,n);
    return 0;
}