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
    int n, m;
    int arr[100001] = { 0 };
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        arr[i] = arr[i - 1] + tmp;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << arr[b] - arr[a-1] << "\n";
    }
    return 0;
}