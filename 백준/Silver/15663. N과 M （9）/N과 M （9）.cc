#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
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

int n, m;
int arr[9];
int visited[9] = {0};
vector<int>ans;
set<vector<int>>s;

void dfs(int depth){
    if(depth == m){
        vector<int> v;
        for(int i = 0; i < m; i++)
            v.push_back(ans[i]);
        s.insert(v);
        v.clear();
    }
    for(int i = 0; i < n; i++){
        if(visited[i])
            continue;
        ans.push_back(arr[i]);
        visited[i] = 1;
        dfs(depth+1);
        ans.pop_back();
        visited[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    dfs(0);
    for(auto vector : s){
        for(auto i : vector){
            cout << i <<" ";
        }
        cout <<"\n";
    }
    return 0;
}