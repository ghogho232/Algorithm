#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
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

char graph[3072][6144] = {' '};
void star(int x, int y, int n){
    if(n == 3){
        graph[x][y] = '*';
        graph[x+1][y-1] = '*';
        graph[x+1][y+1] = '*';
        for(int i = y-2; i <= y + 2; i++){
            graph[x+2][i] = '*';
        }
        return;
    }
    star(x, y, n/2);
    star(x + n/2, y - n/2, n/2);
    star(x + n/2, y + n/2, n/2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2*n - 1; j++){
            graph[i][j] = ' ';
        }
    }
    star(0, n-1, n);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2*n - 1; j++){
            cout << graph[i][j];
        }
        cout << "\n";
    }
    return 0;
}