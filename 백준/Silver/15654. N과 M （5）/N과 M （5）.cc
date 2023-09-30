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

void dfs(int depth){ 
  if(depth == m){
    for(auto i : ans){
      cout<< i <<" ";
    }
    cout<<"\n";
    return;
  }
    for(int i = 0; i < n; i++){
        if(visited[i])
            continue;
        ans.push_back(arr[i]);
        visited[i] = 1;
        dfs(depth+1);
        ans.pop_back();
        visited[i] = false;
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    dfs(0);
    return 0;
}