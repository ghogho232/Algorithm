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

using namespace std;

int board[101][101];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, l;
    int cnt = 0;
    int idx = 1;
    queue<pair<int,char>>turn;
    deque<pair<int,int>>snake;
    cin >> n >> k;

    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        board[a][b] = 2;
    }
    cin >> l;
    for(int i = 0; i < l; i++){
        int x; 
        char c;
        cin >> x >> c;
        turn.push({x,c});
    }
    board[1][1] = 1;
    snake.push_back({1,1});

    while(true){
        cnt++;
        int nx = snake.back().first + dy[idx];
        int ny = snake.back().second + dx[idx];
        if(nx <= 0 || nx > n || ny <= 0 || ny > n || board[nx][ny] == 1)
            break;
        if(board[nx][ny] != 2){
            board[snake.front().first][snake.front().second]=0;
            snake.pop_front();
        }
        board[nx][ny] = 1;
        snake.push_back({nx,ny});

        if(cnt == turn.front().first){
            if(turn.front().second == 'D'){
                idx = (idx + 1) % 4;
            }
            else
                idx = (idx + 3) % 4;
            turn.pop();
        }
    }
    cout << cnt;
    return 0;
}