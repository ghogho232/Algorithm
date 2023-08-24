#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<deque>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    int n;
    int row = 0, col = 0, r_cnt = 0, c_cnt = 0;

    cin >> n;
    int arr[101][101] = { 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch;
            cin >> ch;
            if (ch == '.')
                arr[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j])
                r_cnt++;
            else
                r_cnt = 0;
            if (r_cnt == 2)
                row++;
        }
        r_cnt = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j][i])
                c_cnt++;
            else
                c_cnt = 0;
            if (c_cnt == 2)
                col++;
        }
        c_cnt = 0;
    }
    cout << row << " " << col;
    return 0;
}