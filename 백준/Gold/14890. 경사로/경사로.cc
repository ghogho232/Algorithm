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
#include <iomanip>
#define ll long long

using namespace std;

int n, l;
int arr[101][101];
int arr2[101][101];
int ans = 0;

bool canMake(int arr[][101], int y, int x) {
    int height = arr[y][x];
    for (int i = x; i < x+l; i++) {
        if (arr[y][i] != height) {
            return false;
        }
    }
    return true;
}
int make(int arr[][101]) {
    int res = 0;

    for (int i = 0; i < n; i++) {
        bool isPossible = true;
        int cur = 1;
        for (int j = 0; j < n-1; j++) {
            //현재,다음 높이 같을 때
            if (arr[i][j] == arr[i][j + 1]) {
                cur++;
            }
            //다음이 더 클 때
            else if (arr[i][j] == arr[i][j + 1] + 1) {
                if (canMake(arr, i, j + 1)) {
                    j += l - 1;
                    cur = 0;
                }
                else {
                    isPossible = false;
                    break;
                }
            }
            //다음이 더 작을 때
            else if (arr[i][j] + 1 == arr[i][j + 1]) {
                if (cur >= l) {
                    cur = 1;
                }
                else {
                    isPossible = false;
                    break;
                }
            }
            //차이가 2이상일 때
            else if (abs(arr[i][j] - arr[i][j + 1]) >= 2) {
                isPossible = false;
                break;
            }
        }
        if (isPossible) {
            res++;
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            arr2[j][i] = arr[i][j];
        }
    }
    ans = make(arr) + make(arr2);
    cout << ans;
    return 0;
}