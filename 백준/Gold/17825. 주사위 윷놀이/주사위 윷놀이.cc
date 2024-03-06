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

int dice[10];
int nxt[35];
int turn[35];
int score[35];
int pos[4];
bool check[35];

int ans = 0;

void init(){
    for(int i = 0; i <= 20; i++){
        nxt[i] = i+1;
    }
    nxt[21] = 21, nxt[27] = 20;
    for(int i = 22; i <= 26; i++){
        nxt[i] = i+1;
    }
    nxt[28] = 29; nxt[29] = 30; nxt[30] = 25, nxt[31] = 32; nxt[32] = 25;
    turn[5] = 22, turn[10] = 31, turn[15] = 28;
    for(int i = 0; i <= 20; i++){
        score[i] = 2*i;
    }
    score[22] = 13; score[23] = 16; score[24] = 19, score[25] = 25; score[26] = 30; score[27] = 35;
    score[28] = 28; score[29] = 27; score[30] = 26, score[31] = 22; score[32] = 24;
}

void dfs(int cnt, int sum){
    if(cnt == 10){
        ans = max(ans, sum);
        return;
    }
    for(int i = 0; i < 4; i++){
        int before = pos[i];
        int cur = before;
        int move_cnt = dice[cnt];

        if(turn[cur] > 0){
            cur = turn[cur];
            move_cnt--;
        }
        while(move_cnt--){
            cur = nxt[cur];
        }
        if(cur != 21 && check[cur])
            continue;
        check[before] = false;
        check[cur] = true;
        pos[i] = cur;

        dfs(cnt+1,sum+score[cur]);

        check[before] = true;
        check[cur] = false;
        pos[i] = before;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 0; i < 10; i++){
        cin >> dice[i];
    }
    init();
    dfs(0,0);
    cout << ans;
    return 0;
}