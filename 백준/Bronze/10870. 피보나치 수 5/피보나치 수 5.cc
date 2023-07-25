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

long long fibonachi(long long n) {
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    return fibonachi(n - 1) + fibonachi(n - 2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n;
    cin >> n;
    cout << fibonachi(n);
    
    return 0;
}