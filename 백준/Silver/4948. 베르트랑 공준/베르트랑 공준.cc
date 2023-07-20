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
    while (true) {
        int m;
        int cnt = 0;
        cin >> m;
        int mm = 2 * m;
        if (m == 0) return 0;
        vector<bool>v(mm+1);
        v[0] = v[1] = true;
        for (int i = 2; i*i <= mm; i++) {
            if (v[i]) continue;
            for (int j = i * i; j <= mm; j += i) {
                v[j] = true;
            }
        }
        for (int i = m + 1; i <= mm; i++) {
            if (!v[i])
                cnt++;
        }
        cout << cnt<<"\n";
    }  
    return 0;
}