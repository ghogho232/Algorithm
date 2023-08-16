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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int>v;
    v.push_back(0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a > v.back())
            v.push_back(a);
        else {
            int idx = lower_bound(v.begin(), v.end(), a)-v.begin();
            v[idx] = a;
        }    
     }
    cout << v.size()-1;
}