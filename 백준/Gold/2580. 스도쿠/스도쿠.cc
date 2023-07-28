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
#include<deque>
#include <sstream>

using namespace std;

const int MAX = 10;

int n;
int s[MAX][MAX]; //스도쿠 입력받을 배열
vector<pair<int, int>>v; //빈칸을 입력할 벡터

//좌표에 i라는 수가 대입될 때 그게 유효한지 판단하는 함수
bool check(int y,int x, int i) { 
    for (int j = 0; j < 9; j++) { //동일한 라인을 돌면서
        if (s[y][j] == i || s[j][x] == i) { //같은 수가 존재한다면
            return false; //false
        }
    }
    for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++) { //3*3사각형 내에
        for (int k = (x / 3) * 3; k < (x / 3) * 3 + 3; k++) {
            if (s[j][k] == i) //같은 수가 존재한다면
                return false; //flase
        }
    }
    return true; //위에 해당이 없다면 true
}

//현재 빈 좌표에 대해 백트래킹
bool dfs(int cur) {
    if (cur == v.size()) { //모든 좌표가 채워졌다면
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << s[i][j] << " "; //스도쿠 출력
            }
            cout << "\n";
        }
        return true; //true반환(스도쿠완성)
    }
    int x = v[cur].second;
    int y = v[cur].first;
    for (int i = 1; i <= 9; i++) { //1부터 9까지 빈칸에 넣어보며
        if (check(y, x, i)) { //유효한지 확인
            s[y][x] = i; //유효하다면 빈칸에 i삽입
            if(dfs(cur + 1)) //다음 빈칸 재귀 처리 true라면
                return true; //dfs도 true반환
            s[y][x] = 0; //현재 i가 답이 아니라면 초기화 후 백트래킹
        }
    }
    return false; //false반환으로 백트래킹
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> s[i][j];
            if (s[i][j] == 0) {
                v.push_back({ i,j });
            }
        }
    }       
    dfs(0);
    return 0;
}
