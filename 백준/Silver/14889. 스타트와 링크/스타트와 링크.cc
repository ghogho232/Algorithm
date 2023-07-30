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

int n; // 사람 수
int arr[21][21]; // 능력치 배열
int check[21]; // 뽑혔는지 확인 할 배열

int dfs(int v, int next) { // next로 이미 중복 방지
    if (v == n / 2) { // 반이 뽑혔으면 다른 반은 자동으로 완성
        int star = 0, link = 0; // 각 팀의 초기 능력치값
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (check[i] && check[j]) // 뽑힌 사람
                    star += arr[i][j]; // 능력치 합
                if (!check[i] && !check[j])
                    link += arr[i][j];
            }
        }
        int tmp = abs(star - link); // 두 팀의 능력치 차
        return tmp; // 최소값 반환
    }

    int minDiff = 1000000000;
    for (int i = next; i <= n; i++) { // 중복없이
        check[i] = 1; // i번째 사람 체크
        int diff = dfs(v + 1, i + 1); // 그 뒤로 계속 체크
        check[i] = 0; // 백트래킹
        minDiff = min(minDiff, diff); // 최소값 갱신
    }

    return minDiff; // 최소값 반환
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    int MIN = dfs(0, 1); // 최소값 계산
    cout << MIN;
}
