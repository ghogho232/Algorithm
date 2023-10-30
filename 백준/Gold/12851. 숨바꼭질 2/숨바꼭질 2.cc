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
queue<pair<int,int>>q;
bool visited[100001];
int cnt = 0;
int minTime = 0;
void bfs(int n, int k){
    q.push({n, 0});
    while(!q.empty()){
        int cur = q.front().first;
        int time = q.front().second;
        q.pop();
        visited[cur] = true;
        if(cnt && cur == k && minTime == time)
            cnt++;
        if(!cnt && cur == k){
            cnt++;
            minTime = time;
        }
        if(cur - 1 >= 0 && !visited[cur-1])
            q.push({cur-1, time + 1});
        if(cur + 1 <= 100000 && !visited[cur+1])
            q.push({cur+1, time+1});
        if(cur * 2 <= 100000 && !visited[2*cur])
            q.push({2*cur, time+1});
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    bfs(n,k);
    cout << minTime<< "\n" << cnt ;
    return 0;
}