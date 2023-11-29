#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
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
int n, m;
int arr[15];
vector<int> ans;
int visited[49];
set<vector<int>> s;
vector<int>v;
void dfs(int k, int asc){
    if(k == 6){
        for(auto it=ans.begin(); it != ans.end(); it++){
            cout << *it <<" ";
        }
        cout <<"\n";
        return;
    }
    for(int i = asc; i < n; i++){
        if(!visited[i]){
            visited[i] = 1;
            ans.push_back(arr[i]);
            dfs(k+1, i);
            visited[i] = 0;
            ans.pop_back();            
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(true){
        ans.clear();
        memset(visited,0,sizeof(visited));
        cin >> n;
        if(n == 0)
            break;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        dfs(0, 0);
        cout <<"\n";
    }

    return 0;
}   