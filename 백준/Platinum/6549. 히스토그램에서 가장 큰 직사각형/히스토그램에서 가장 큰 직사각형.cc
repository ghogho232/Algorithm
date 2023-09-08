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
const int MAX = 100001;
vector<ll> h;
ll solve(ll left, ll right){
    if(left == right)
        return h[left];
    ll mid = (left + right)/2;
    ll ret = max(solve(left,mid), solve(mid + 1,right));
    ll lo = mid, hi = mid + 1;
    ll height = min(h[lo],h[hi]);
    ret = max(ret, height * 2);
    while(left < lo || hi < right){
        if(hi < right && (lo == left || h[lo-1] < h[hi+1])){
            hi++;
            height = min(height,h[hi]);
        }
        else{
            lo--;
            height = min(height, h[lo]);
        }
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(1){
        h.clear();
        int n;
        cin >> n;
        if(n == 0)
            break;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            h.push_back(a);
        }
        cout << solve(0,n-1) << "\n";
    }

    return 0;
}