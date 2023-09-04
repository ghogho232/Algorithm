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
    int n, cnt = 0;
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }
    vector<int> arr;
    vector<int> v(n + 1, 1);
    for(int i = 2; i <= sqrt(n); i++){
        if(!v[i])
            continue;
        for(int j = i*i; j <= n; j+=i)
            v[j] = 0;
    }

    for(int i = 2; i <= n; i++){ 
        if(v[i])
            arr.push_back(i);
    }  

    int start = 0, end = 0, sum = 0;
    while(end <= arr.size()) {
        if(sum < n) {
            sum += arr[end];
            end++;
        }
        else if(sum >= n) {
            sum -= arr[start];
            start++;
        }

        if(sum == n) cnt++;
    }

    cout << cnt;
    return 0;
}