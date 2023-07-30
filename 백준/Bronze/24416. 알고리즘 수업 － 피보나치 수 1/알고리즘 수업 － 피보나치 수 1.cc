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
#include<deque>
#include <sstream>

using namespace std;
int f[41];
int cnt1 = 0, cnt2 = 0;
int fib(int n) {
    if (n == 1 || n == 2) {
        cnt1++;
        return 1;
    }
    else
        return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n) {
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
        cnt2++;
    }
    return f[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    fib(n);
    fibonacci(n);
    cout << cnt1 << " " << cnt2;
}