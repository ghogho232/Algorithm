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
int n, m;
int arr[100001];

void binary_search(int target) {
    int left = 0;
    int right = n-1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            cout << 1 << "\n";
            return;
        }
        else if (arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    cout << 0 << "\n";
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        binary_search(a);
    }

    return 0;
}