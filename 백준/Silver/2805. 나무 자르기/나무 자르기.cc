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
    int arr[1000001];

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    long long left = 0, right = arr[n - 1];

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long ans = 0; 

        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) {
                ans += arr[i] - mid;
            }
        }

        if (ans >= m) { 
            left = mid + 1;
        }
        else { 
            right = mid - 1;
        }
    }

    if (right >= 0) { 
        cout << right << "\n"; 
    }

    return 0;
}