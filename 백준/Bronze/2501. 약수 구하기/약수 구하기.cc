#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>


using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> v;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            v.push_back(i);
        }
    }

    if (K > v.size()) {
        cout << 0;
    }
    else {
        cout << v[K - 1];
    }

    return 0;
}