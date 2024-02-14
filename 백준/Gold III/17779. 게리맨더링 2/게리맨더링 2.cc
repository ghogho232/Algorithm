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

int n;
int popul[21][21];
int arr[21][21];
int ans = 987654321;

bool condition1(int d1, int d2) {
    return (d1 >= 1 && d2 >= 1);
}

bool condition2(int x, int d1, int d2) {
    return (x >= 1 && x < x + d1 + d2 && x + d1 + d2 <= n);
}

bool condition3(int y, int d1, int d2) {
    return (1 <= y - d1 && y - d1 < y && y < y + d2 && y + d2 <= n);
}

void divide(int x, int y, int d1, int d2) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            arr[i][j] = 5;
        }
    }
    int area = 0;
    for(int i = 1; i < x + d1; i++) {
        if(i >= x) {
            area++;
        }
        for(int j = 1; j <= y - area; j++) {
            arr[i][j] = 1;
        }
    }
    area = 0;
    for(int i = n; i > y; i--) {
        if(i <= y + d2) {
            area++;
        }
        for(int j = 1; j <= x + d2 - area; j++) {
            arr[j][i] = 2;
        }
    }
    area = 0;
    for(int i = 1; i < y - d1 + d2; i++) {
        if(i >= y - d1) {
            area++;
        }
        for(int j = n; j >= x + d1 + area; j--) {
            arr[j][i] = 3;
        }
    }
    area = 0;
    for(int i = n; i > x + d2; i--) {
        if(i <= x + d1 + d2) {
            area++;
        }
        for(int j = n; j >= y - d1 + d2 + area; j--) {
            arr[i][j] = 4;
        }
    }
}

void calc() {
    int num[6] = {-1, 0, 0, 0, 0, 0};
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            num[arr[i][j]] += popul[i][j];
        }
    }
    sort(num, num + 6);
    int tmp = num[5] - num[1];
    if(ans > tmp) {
        ans = tmp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> popul[i][j];
        }
    }

    for(int x = 1; x <= n; x++) {
        for(int y = 2; y <= n; y++) {
            for(int d1 = 1; d1 <= y; d1++) {
                for(int d2 = 1; d2 < n - y + 1; d2++) {
                    if(condition1(d1, d2) && condition2(x, d1, d2) && condition3(y, d1, d2)) {
                        divide(x, y, d1, d2);
                        calc();
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}