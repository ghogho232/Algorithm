#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<bool>v(m+1);
    v[1] = true;
    for (int i = 2; i*i <= m; i++) {
        if (v[i]) continue;
        for (int j = i * i; j <= m; j += i) {
            v[j] = true;
        }
    }
    for (n; n <= m; n++) {
        if (!v[n])
            cout << n << "\n";
    }
    return 0;
}