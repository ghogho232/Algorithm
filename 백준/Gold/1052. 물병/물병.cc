#define _CRT_SECURE_nO_WARnInGS
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
#define INF 987654321

using namespace std;

int buy(int bottle){
    int cnt = 0;
    while(bottle > 0){
        if(bottle % 2){
            cnt++;
        }
        bottle /= 2;
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int ans = 0;
    if(n <= k){
        ans = 0;
    }
    else{
        while(1){
            if(buy(n)<=k)
                break;
            ans++;
            n++;
        }
    }
    cout << ans;
    return 0;
}