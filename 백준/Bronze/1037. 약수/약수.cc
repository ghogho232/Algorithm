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
    int MAX = 0;
    int MIN = 1000000;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        MAX = max(a, MAX);
        MIN = min(a, MIN);
    }
    cout << MAX*MIN;
    return 0;
}