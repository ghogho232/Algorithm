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
void dfs(int k, int asc){
    if(k == m){
        for(auto it=ans.begin(); it != ans.end(); it++){
            cout << *it <<" ";
        }
        cout <<"\n";
        return;
    }
    for(int i = asc; i < n; i++){
        if(!visited[i]){
            ans.push_back(arr[i]);
            visited[i]=1;
            dfs(k+1, i+1);
            ans.pop_back();
            visited[i] = 0;
        }
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
    dfs(0, 0);
    return 0;
}   