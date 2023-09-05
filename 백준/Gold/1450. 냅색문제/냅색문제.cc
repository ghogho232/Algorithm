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

vector<ll> arr;
vector<ll> v1,v2;

void recursion(int l, int r, vector<long long>&v, long long sum){
    if(l>r){
        v.push_back(sum);
        return;
    }
    recursion(l+1,r,v,sum);
    recursion(l+1,r,v,sum+arr[l]);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,c;
    ll ans = 0;
    arr.resize(n);
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    recursion(0, n / 2, v1, 0);
    recursion(n/2 + 1, n-1, v2, 0);

    sort(v2.begin(),v2.end());

    for(int i=0; i<v1.size(); i++)
        ans += upper_bound(v2.begin(), v2.end(), c - v1[i]) - v2.begin();

    cout << ans;
    return 0;
}