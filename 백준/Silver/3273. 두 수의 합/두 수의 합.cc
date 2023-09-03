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

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x, cnt = 0;
    int arr[100001];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> x;
    sort(arr,arr+n);
    int start = 0, end = n-1;


    while(start < end){
        int sum = arr[start] + arr[end];
        if (sum == x) {
            cnt++;
            start++; 
        } else if (sum > x) {
            end--;
        } else {
            start++;
        }
    }
    cout << cnt;
    return 0;
}