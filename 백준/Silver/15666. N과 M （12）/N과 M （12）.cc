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
int arr[8];
int res[8];
void dfs(int level, int begin){
    if(level == m){
        for(int i = 0; i < m; i++){
            cout << res[i] <<" ";
        }
        cout <<"\n";
        return;
    }
    int tmp = 0;
    for(int i = begin; i < n; i++){
        if(tmp != arr[i]){
            tmp = arr[i];
            res[level] = arr[i];
            dfs(level + 1, i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    dfs(0,0);
    

    return 0;
}