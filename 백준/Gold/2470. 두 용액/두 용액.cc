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
    int n, min = 2000000001;
    ll arr[100001];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int start = 0, end = n-1;
    int ms, me;
    while(start < end){
        int sum = (arr[start] + arr[end]);
        int absum = abs(sum);

        if(absum < min){
            min = absum;
            ms = arr[start];
            me = arr[end];
        }
        if(sum < 0)
            start++;
        else
            end--;
    }
    cout << ms <<" " << me;
    return 0;
}