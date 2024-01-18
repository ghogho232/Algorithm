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
#define MAX INT_MAX
#define MOD 1000000003
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    int arr[1000001];;
    int b,c;
    ll cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> b >> c;
    for(int i = 0; i < n; i++){
        arr[i] -= b;
        cnt++;
        if(arr[i]<=0)
            continue;
        if(arr[i]%c>0)
            cnt += arr[i]/c+1;
        else 
            cnt += arr[i]/c;
    }
    cout << cnt;
    return 0;
}