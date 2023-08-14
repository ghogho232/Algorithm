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
long long k, n, ans = 0;    
long long sum = 0;
long long arr[100001];

int binary_search() {
    long long left = 1;
    long long right = sum/n;


    while (left <= right) {    
        long long tmp = 0;
        long long mid = (left + right) / 2;
        for (int i = 0; i < k; i++) {
            tmp += arr[i] / mid;
        }

        if (tmp >= n) {
            left = mid + 1;
            if (mid > ans)
                ans = mid;
        }
        else {
            right = mid - 1;
        }

    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + k);
    cout << binary_search() << "\n";

    return 0;
}