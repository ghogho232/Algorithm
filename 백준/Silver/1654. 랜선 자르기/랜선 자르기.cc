#define _CRT_SECURE_NO_WARNINGS
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

using namespace std;

ll sum = 0, ans = 0;
ll binary_search(int arr[], int n, int k){
    ll left = 1;
    ll right = sum/n;
    while(left <= right){
        ll mid = (left + right)/2;
        ll tmp = 0;
        for(int i = 0; i < n; i++){
            tmp += arr[i]/mid;
        }
        if(tmp >= k){
            left = mid + 1;
            if(mid > ans){
                ans = mid;
            }
        }
        else{
            right = mid - 1;
        }
    }
    return ans;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr + n);
    cout << binary_search(arr, n, k);
    return 0;
}