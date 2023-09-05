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
int visited[MAX];
vector<int>v[MAX];
int parent[MAX];

void dfs(int a){
    visited[a] = 1;
    for(int i = 0; i < v[a].size(); i++){
        int next = v[a][i];
        if(!visited[next]){
            parent[next] = a;
            dfs(next);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    for(int i = 2; i<= n;i++){
        cout << parent[i] <<" ";
    }
    return 0;
}