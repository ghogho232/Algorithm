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
int n, x, y, d, g;
int arr[101][101];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int cnt;
vector<int> dir; 

void dragoncurve(){
    int size = dir.size();
    for (int i = size - 1; i >= 0; i--){
        int nd = (dir[i] + 1) % 4;
        y += dy[nd];
        x += dx[nd];
        arr[y][x] = 1;
        dir.push_back(nd);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while (n--){
        cin >> x >> y >> d >> g;
        dir.clear();

        arr[y][x] = 1;
        y += dy[d];
        x += dx[d];
        arr[y][x] = 1;

        dir.push_back(d);

        while (g--){
            dragoncurve();
        }
    }
    for (int i = 0; i < 101; i++){
        for (int j = 0; j < 101; j++){
            if (arr[i][j] == 1 && arr[i][j + 1] == 1 && arr[i + 1][j] == 1 && arr[i + 1][j + 1] == 1)
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}