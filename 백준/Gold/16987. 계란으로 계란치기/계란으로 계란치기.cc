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
int n;
vector<pair<int,int>>egg(8);
int cnt = 0, ans = 0;
int broken[8];

void dfs(int depth, int tot){
    int end = 0;
    bool flag = false;
    for(int i = 0; i < n; i++){
        if(broken[i] == 0){
            end++;
        }
    }
    if(end <= 1)
        flag = true;
    if(depth == n || flag){
        ans = max(ans, tot);
        return;
    }
    else if(broken[depth]){
        dfs(depth+1,tot);
    }
    else {
        for(int i = 0; i < n; i++){
                if(depth == i || broken[i])
                    continue;
                egg[depth].first -= egg[i].second;
                egg[i].first -= egg[depth].second;
                int cnt = 0;
                if(egg[depth].first <= 0){
                    cnt++;
                    broken[depth] = 1;
                }
                if(egg[i].first <= 0){
                    cnt++;
                    broken[i] = 1;
                }
                dfs(depth+1,tot+cnt);
                egg[depth].first += egg[i].second;
                egg[i].first += egg[depth].second;
                broken[depth] = 0;
                broken[i] = 0;
        } 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> egg[i].first >> egg[i].second;
    }
    dfs(0,0);
    cout << ans;
    return 0;
}