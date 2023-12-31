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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    ll ans = 0;
    cin >> n >> m;
    priority_queue<ll, vector<ll>, greater<ll>>pq;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        pq.push(a);
    }
    while(m--){
        ll tmp1 = pq.top();
        pq.pop();
        ll tmp2 = pq.top();
        pq.pop();
        pq.push(tmp1+tmp2);
        pq.push(tmp1+tmp2);
    }
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
    return 0;
}