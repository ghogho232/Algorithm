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

    int N, sum = 0, cntmax = 0, val = 0;
    cin >> N;
    vector<int> v(N);
    vector<int> cnt(8001); 

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        sum += v[i]; 

        cnt[v[i] + 4000]++;
    }

    sort(v.begin(), v.end());


    for (int i = 0; i <= 8000; ++i) {
        if (cnt[i] > cntmax) {
            cntmax = cnt[i];
            val = i;
        }
    }


    for (int i = val + 1; i <= 8000; ++i) {
        if (cnt[i] == cntmax) {
            val = i;
            break;
        }
    }
    sum = round(double(sum) / N);

    cout << sum << "\n";
    cout << v[(N - 1) / 2] << "\n"; 
    cout << val - 4000 << "\n"; 
    cout << v[N - 1] - v[0]; 
    return 0;
}