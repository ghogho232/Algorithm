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
int n,m;
int sum=0;
int arr[20];
vector<int>ans;
int cnt = 0;

void dfs(int v){
    if(v == n){
        if(sum == m){
            cnt++; 
        }
        return;
    }
    sum += arr[v];
    dfs(v+1);
    sum -= arr[v];
    dfs(v+1);
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    dfs(0);
    if(m == 0)
        cnt--;
    cout << cnt;
    return 0;
}