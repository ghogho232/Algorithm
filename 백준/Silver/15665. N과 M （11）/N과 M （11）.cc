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
int arr[9];
vector<int> ans;
int visited[9];
set<vector<int>> s;
vector<int>v;
void dfs(int k){
    if(k == m){
        for(auto it=ans.begin(); it != ans.end(); it++){
            v.push_back(*it);
            // cout << *it <<" ";
        }
        s.insert(v);
        v.clear();
        // cout <<"\n";
        return;
    }
    for(int i = 0; i < n; i++){
            ans.push_back(arr[i]);
            dfs(k+1);
            ans.pop_back();
        
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    dfs(0);
    // for (auto it = s.begin(); it != s.end(); it++) {
    //     for (int i = 0; i < it->size(); i++) {
    //         cout << (*it)[i] << " ";
    //     }
    //     cout << "\n";
    // }
    for(auto& vec:s){
        for(auto& element:vec){
            cout << element <<" ";
        }
        cout <<"\n";
    }
    return 0;
}   