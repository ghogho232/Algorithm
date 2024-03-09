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

int board[11][11]={0};
int n;
int score = 0;
int blck_cnt = 0;

void init(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10;j++){
            board[i][j] = 0;
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 4; j++){
            board[i][j] = 1; //보드의 가용 칸
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 10; j++){
            board[i][j] = 1; //보드의 가용 칸
        }
    }
}

void green(int t, int x, int y){   
    int size = 0;
    if(t==1) size=1; 
    else if(t==2) size=2;
    else {
        size = 1;
        x++;
    }
    int curx = x, cury = y;
    int acnt = 11;
    for(int i = 0; i < size; i++){
        x = curx, y = cury;
        int cnt = 0;
        while((board[x+1][y+i] != 0) && (board[x+1][y+i] != 3)){
            cnt++;
            x++;
        }
        acnt = min(acnt,cnt);
    }
    for(int i = 0; i < size; i++){
        board[curx][cury+i] = 1;
        board[curx+acnt][cury+i] = 3;
    }            
    if(t == 3){
        board[curx-1][cury] = 1;
        board[curx+acnt-1][cury] = 3;
    }
}
void blue(int t, int x, int y){
    int size = 0;
    if(t==1) size=1; 
    else if(t==3) size=2;
    else {
        size = 1;
        y++;
    }
    int curx = x, cury = y;
    int acnt = 11;
    for(int i = 0; i < size; i++){
        x = curx, y = cury;
        int cnt = 0;
        while((board[x+i][y+1] != 0) && (board[x+i][y+1] != 3)){
            cnt++;
            y++;
        }
        acnt = min(acnt,cnt);
    }
    for(int i = 0; i < size; i++){
        board[curx+i][cury] = 1;
        board[curx+i][cury+acnt] = 3;
    }   
    if(t == 2){
        board[curx][cury-1] = 1;
        board[curx][cury+acnt-1] = 3;
    }

}

void delete_row(int row){
    for(int i = 0; i < 4; i++){
        board[row][i] = 1;
    }
    for(int i = row; i >= 4; i--){
        for(int j = 0; j < 4; j++){
            board[i][j] = board[i-1][j];
        }
    }
    score++;
}
void delete_col(int col){
    for(int i = 0; i < 4; i++){
        board[i][col] = 1;
    }
    for(int i = col; i >= 4; i--){
        for(int j = 0; j < 4; j++){
            board[j][i] = board[j][i-1];
        }
    }
    score++;
}
void blue_delete_check(){
    for(int i = 9; i >= 4; i--){
        bool flag = true;
        for(int j = 0; j < 4; j++){
            if(board[i][j] != 3){
                flag = false;
                break;
            }
        }
        if(flag){
            delete_row(i);
            i++;
        }
    }
}
void green_delete_check(){
    for(int i = 9; i >= 4; i--){
        bool flag = true;
        for(int j = 0; j < 4; j++){
            if(board[j][i] != 3){
                flag = false;
                break;
            }
        }
        if(flag){
            delete_col(i);
            i++;
        }
    }
}
void green_check(){
    int cnt = 0;
    for(int i = 4; i <=5; i++){
        for(int j = 0; j < 4; j++){
            if(board[i][j] == 3){
                cnt++;
                break;
            }
        }
    }
    for(int k = 0; k < cnt; k++){
        for(int i = 0; i < 4; i++){
            board[9][i] = 1;
        }
        for(int i = 9; i >= 4; i--){
            for(int j = 0; j < 4; j++){
                board[i][j] = board[i-1][j];
            }
        }
    }
}
void blue_check(){
    int cnt = 0;
    for(int i = 4; i <=5; i++){
        for(int j = 0; j < 4; j++){
            if(board[j][i] == 3){
                cnt++;
                break;
            }
        }
    }
    for(int k = 0; k < cnt; k++){
        for(int i = 0; i < 4; i++){
            board[i][9] = 1;
        }
    for(int i = 9; i >= 4; i--){
        for(int j = 0; j < 4; j++){
            board[j][i] = board[j][i-1];
        }
    }
    }
}
void count_blck(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(board[i][j] == 3){
                blck_cnt++;
            }
        }
    }
}
void mono(int t, int x, int y){
    if(t == 1){ //1*1
        board[x][y] = 3;
    }
    else if(t == 2){ //1*2
        board[x][y] = 3;
        board[x][y+1] = 3;
    }
    else{ //2*1
        board[x][y] = 3;
        board[x+1][y] = 3;
    }
    green(t,x,y);    
    blue(t,x,y);
    green_delete_check();
    blue_delete_check();
    green_check();
    blue_check();
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    cin >> n;
    while(n--){
        int t,x,y;
        cin >> t >> x >> y;
        mono(t,x,y);
    }
    // for(int i = 0; i < 10; i++){
    //     for(int j = 0; j < 10; j++){
    //         cout << board[i][j]<<" ";
    //     }
    //     cout <<"\n";
    // }
    count_blck(); 
    cout << score<<"\n";
    cout << blck_cnt<<"\n";
    return 0;
}