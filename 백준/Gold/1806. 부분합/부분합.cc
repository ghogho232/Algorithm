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

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n >> s;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int start = 0, end = 0;
    int cnt = 0;
    int sum = 0;

    int Min = n + 1; 

    while (end <= n) {
        if (sum < s) {
            sum += arr[end];
            end++;
        } else if (sum >= s) {
            Min = min(Min, end - start);
            sum -= arr[start];
            start++;
        }
    }

    if (Min == n + 1) {
        cout << 0; 
    } else {
        cout << Min;
    }

    return 0;
}