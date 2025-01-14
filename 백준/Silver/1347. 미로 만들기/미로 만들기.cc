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
#define INF 987654321

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n;
    char map[100][100];
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            map[i][j] = '#';
        }
    }
    cin >> n;
    string move;
    cin >> move;
    int curdir = 2;
    map[50][50] = '.';
    int minx = 50, maxx = 50, miny = 50, maxy = 50;
    int curx = 50;
    int cury = 50;  
    for(int i = 0; i < n; i++){
        char cur = move[i];    
    
        if(cur == 'R') {
            curdir = (curdir+1)%4;
        }
        else if(cur == 'L') {
            curdir = (curdir+3)%4;
        }
        else{
            curx += dx[curdir];
            cury += dy[curdir];
            map[curx][cury] = '.';
            
            minx = min(minx, curx);
            miny = min(miny, cury);
            maxx = max(maxx, curx);
            maxy = max(maxy, cury);
        }
    }
    for(int i = minx; i <= maxx; i++){
        for(int j = miny; j <= maxy; j++){
            cout << map[i][j];
        }
        cout <<"\n";
    }
    return 0;
}