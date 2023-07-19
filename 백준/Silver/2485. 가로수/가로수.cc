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

int gcd(int a, int b) {
    while (true) {
        int r = a % b;
        if (r == 0)
            return b;
        a = b;
        b = r;
    }
}
int lcc(int a, int b) {
    return (a * b) / gcd(a, b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int cnt = 0;
    cin >> n;
    vector<int>v1(n);
    vector<int>v2(n-1);
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < n-1; i++) {
        v2[i] = v1[i + 1] - v1[i];
    }
    int tmp = v2[0];
    for (int i = 1; i < n - 1; i++) {
        tmp = gcd(tmp, v2[i]);
    }
    for (int i = 0; i < n-1; i++) {
        cnt += (v2[i] / tmp) - 1;
    }
    cout << cnt;
    return 0;
}
