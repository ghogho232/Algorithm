#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include <cstring>
#include<deque>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;
int a, b;
int visited[10000] = {0};
int D(int n){
    return (2 * n) % 10000;
}
int S(int n){
    return n - 1 < 0 ? 9999 : n - 1; 
}
int L(int n){
    return (n % 1000) * 10 + n/1000;
}
int R(int n){
    return (n % 10) * 1000 + n/10;
}
void bfs(){
    queue<pair<int, string>> q;
    q.push({a,""});
    visited[a] = 1;

    while(!q.empty()){
        int cur_n = q.front().first;
        string cur_s = q.front().second;
        q.pop();

        if(cur_n == b){
            cout << cur_s <<"\n";
            return;
        }
        if(!visited[D(cur_n)]){
            visited[D(cur_n)] = 1;
            q.push({D(cur_n), cur_s + "D"});
        }
        if(!visited[S(cur_n)]){
            visited[S(cur_n)] = 1;
            q.push({S(cur_n), cur_s + "S"});
        }
        if(!visited[L(cur_n)]){
            visited[L(cur_n)] = 1;
            q.push({L(cur_n), cur_s + "L"});
        }
        if(!visited[R(cur_n)]){
            visited[R(cur_n)] = 1;
            q.push({R(cur_n), cur_s + "R"});
        }        
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        memset(visited, 0, sizeof(visited));
        bfs();
    }
    return 0;
}