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

int n,m,x,y,k;
int arr[21][21];
int dice[6]={0};
int order;

const int east = 1, west = 2, north = 3, south = 4;

void moveEast(){
    y++;
    int tmp = dice[4];
    dice[4] = dice[0];
    dice[0] = dice[5];
    dice[5] = dice[2];
    dice[2] = tmp;
}
void moveWest(){
    y--;
    int tmp = dice[0];
    dice[0] = dice[4];
    dice[4] = dice[2];
    dice[2] = dice[5];
    dice[5] = tmp;
}
void moveSouth(){
    x++;
    int tmp = dice[0];
    dice[0] = dice[1];
    dice[1] = dice[2];
    dice[2] = dice[3];
    dice[3] = tmp;
}
void moveNorth(){
    x--;
    int tmp = dice[3];
    dice[3] = dice[2];
    dice[2] = dice[1];
    dice[1] = dice[0];
    dice[0] = tmp;
}

bool pos(int dir){
    if(dir == east){
        if(y+1 >= m){           
            return false;
            }
    }
    if(dir == west){
        if(y-1 < 0){          
            return false;
            }
    }
    if(dir == north){
        if(x-1 < 0){{       
            return false;
            }
        }
    }
    if(dir == south){
        if(x+1 >= n){      
            return false;
            }
    }
    return true;
}
void move(int order){
    if(order == east)
        moveEast();
    else if(order == west)
        moveWest();
    else if(order == north)
        moveNorth();
    else if(order == south)
        moveSouth();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < k; i++){
        cin >> order;
        if(!pos(order))
            continue;
        if(arr[x][y] == 0){
            arr[x][y] = dice[0];
        }
        else{
            dice[0] = arr[x][y];
            arr[x][y] = 0;
        }
        move(order);
        cout << dice[2]<<"\n";
    }
    return 0;
}