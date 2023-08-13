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

#define MOD 1000000007

vector<vector<long long>> multiply(vector<vector<long long>> &a, vector<vector<long long>> &b){
    vector<vector<long long>> ans = { {0,0},{0,0} };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                ans[i][j] += a[i][k] * b[k][j];
                ans[i][j] %= MOD;
            }
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n;
    cin >> n;
    vector<vector<long long>> ans = { {1,0},{0,1} };
    vector<vector<long long>> a = { {1,1},{1,0} };
    while (n > 0) {
        if (n % 2 == 1) {
            ans = multiply(ans, a);
        }
        a = multiply(a, a);
        n /= 2;
    }
    cout << ans[0][1];
    return 0;
}