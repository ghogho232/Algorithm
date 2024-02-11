#define _CRT_SECURE_nO_WARnInGS
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
#define INF 987654321

using namespace std;

int n;
int popul[11];
int arr[11][11];
int visited[11];
int ans = INF;
bool state1, state2 = false;

void calc(vector<int>a, vector<int>b){
    int pop1 = 0;
    int pop2 = 0;
    for(int i = 0; i < a.size(); i++){
        pop1 += popul[a[i]];
    }
    for(int i = 0; i < b.size(); i++){
        pop2 += popul[b[i]];
    }
    int tmp = abs(pop1 - pop2);
    if(tmp < ans){
        ans = tmp;
    }
}
bool bfs(vector<int>v){
    memset(visited,0,sizeof(visited));
    queue<int>q;
    q.push(v[0]);
    visited[v[0]] = 1;
    int cnt = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 1; i < v.size(); i++){
            if(arr[cur][v[i]] && !visited[v[i]]){
                visited[v[i]]=1;
                cnt++;
                q.push(v[i]);
            }
        }
    }
    if(cnt == v.size()){
        return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> popul[i];
    }
    for(int i = 1; i <= n; i++){
        int cnt;
        cin >> cnt;
        for(int j = 1; j <= cnt; j++){
            int a;
            cin >> a;
            arr[i][a] = arr[a][i] = 1;
        }
    }
    for(int k = 1; k <= n/2; k++){

        vector<int>support(n,0);
        for(int i = n-k; i < n; i++){
            support[i] = 1;
        }
        do{
            vector<int>area1;
            vector<int>area2;
            vector<int> cand(n);
            for(int i = 0; i < support.size(); i++){
                if(support[i]){
                    cand[i] = 1;
                }
            }
            
            for(int i = 0; i < cand.size(); i++){
                if(cand[i]){
                    area1.push_back(i+1);
                }
                else if(!cand[i]){
                    area2.push_back(i+1);
                }
            }
            state1 = bfs(area1);
            state2 = bfs(area2);
            if(state1 && state2){
                calc(area1,area2);
            }

        }while(next_permutation(support.begin(),support.end()));
        
    }
    if(ans == INF){
        cout << -1;
    }
    else {
        cout << ans<<"\n";

    }
    return 0;
}