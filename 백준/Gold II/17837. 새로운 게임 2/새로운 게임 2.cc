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

struct piece{ //말 정보
    int x, y, dir;
};

int n, k;
int board[12][12]; //보드 색 저장
piece chess[11]; //각 말 저장 배열
vector<int>state[12][12]; //보드에 어떤 말이 있는지
int dx[]={0,0,0,-1,1}; //1부터 우,좌,상,하
int dy[]={0,1,-1,0,0};

int del_piece(int curx, int cury, int piece_num){
    //해당 위치의 뒤에서부터 이동하는 말이 나올 때까지 카운트
    int cnt = 0;
    for(int i = state[curx][cury].size()-1; i >= 0; i--){
        if(state[curx][cury][i] == piece_num)
            break;
        cnt++;
    }
    return cnt+1;
}
int reverse_dir(int piece_num){
    int dir = chess[piece_num].dir;
    if(dir == 1) return 2;
    else if(dir == 2) return 1;
    else if(dir == 3) return 4;
    else if(dir == 4) return 3;
}
void move(int curx, int cury, int nx, int ny, int piece_num, int pos, int color){
    if(color == 0){
        for(int i = pos; i < state[curx][cury].size(); i++){
            state[nx][ny].push_back(state[curx][cury][i]); //이동 위치로 말 원래 순서대로 이동
            int idx = state[curx][cury][i]; //현재 말 위치 수정
            chess[idx].x = nx;
            chess[idx].y = ny;
        }
        int del = del_piece(curx, cury, piece_num); //기존 위치에서 말 삭제
        for(int i = 0; i < del; i++){
            state[curx][cury].pop_back();
        }
    }
    else if(color == 1){
        for(int i = state[curx][cury].size()-1; i >= pos; i--){ //역순으로 말을 옮기기 때문에 뒤에서부터 접근
            state[nx][ny].push_back(state[curx][cury][i]);
            int idx = state[curx][cury][i];
            chess[idx].x = nx;
            chess[idx].y = ny;
        }
        int del = del_piece(curx, cury, piece_num);
        for(int i = 0; i < del; i++){
            state[curx][cury].pop_back();
        }
    }
    else if(color == 2){ 
        int dir = reverse_dir(piece_num); //해당 말의 진행방향 변경
        chess[piece_num].dir = dir;
        int nnx = curx + dx[dir]; //새로 이동
        int nny = cury + dy[dir];

        if(nnx >= 0 && nnx < n && nny >= 0 && nny < n){
            if(board[nnx][nny]!=2)
                move(curx,cury,nnx,nny,piece_num,pos,board[nnx][nny]);
        }
    }
}

int position(int curx, int cury, int idx){
    //해당 말이 보드의 한 위치에서 몇번째에 있는지 리턴
    for(int i = 0; i < state[curx][cury].size(); i++){
        if(state[curx][cury][i]== idx)
            return i;
    }
}
bool check(){
    //보드에 말이 네개이상 쌓였으면 true
    for(int i = 0; i < k; i++){
        int x = chess[i].x;
        int y = chess[i].y;
        if(state[x][y].size() >= 4)
            return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < k; i++){
        int x, y, dir;
        cin >> x >> y >> dir;
        x--,y--; //(0,0)기준으로 하기위해
        chess[i] = {x,y,dir};
        state[x][y].push_back(i);
    }

    bool flag = false; //게임 종료위한 플래그
    int time = 0;
    while(true){
        if(time > 1000)
            break;
        for(int i = 0; i < k; i++){
            int curx = chess[i].x;
            int cury = chess[i].y;
            int dir = chess[i].dir;

            int nx = curx+dx[dir];
            int ny = cury+dy[dir];
            int pos = position(curx,cury,i); //보드의 한 위치에서 말의 위치(순서)

            if(nx>=0 && nx<n && ny>=0 && ny<n)
                move(curx,cury,nx,ny,i,pos,board[nx][ny]);
            else move(curx,cury,nx,ny,i,pos,2); //보드 밖으로 이동이면 2(파란색처럼 취급)
            if(check()){ //종료조건 확인
                flag = true;
                break;
            }
        }
        if(flag == true) //종료조건 만족했으면 반복종료
            break;
        time++; //아니면 다음 턴 한번 더
    }
    if(flag)
        cout << time+1;
    else
        cout << -1;
    return 0;
}