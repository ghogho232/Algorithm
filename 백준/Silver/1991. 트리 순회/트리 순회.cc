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

char tree[27][2];
int visited[27] = {0};

void preorder(int v){
    if(visited[v])
        return;
    visited[v] = 1;
    char root = v + 'A';
    cout << root;
    int left = tree[v][0]-'A';
    if(left >= 0)
        preorder(left);
    int right = tree[v][1]-'A';
    if(right >= 0)
        preorder(right);
}

void inorder(int v){
    if(visited[v])
        return;
    visited[v] = 1;
    int left = tree[v][0]-'A';
    if(left >= 0)
        inorder(left);    
    char root = v + 'A';
    cout << root;
    int right = tree[v][1]-'A';
    if(right >= 0)
        inorder(right);
}

void postorder(int v){
    if(visited[v])
        return;
    visited[v] = 1;
    int left = tree[v][0]-'A';
    if(left >= 0)
        postorder(left);
    int right = tree[v][1]-'A';
    if(right >= 0)
        postorder(right);
    char root = v + 'A';
    cout << root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        char root, left, right;
        cin >> root >> left >> right;
        tree[root-'A'][0] = left;
        tree[root-'A'][1] = right;
    }

    preorder(0);
    cout << "\n";
    memset(visited, 0, sizeof(visited));
    inorder(0);
    cout << "\n";
    memset(visited, 0, sizeof(visited));
    postorder(0);
    cout << "\n";
    return 0;
}