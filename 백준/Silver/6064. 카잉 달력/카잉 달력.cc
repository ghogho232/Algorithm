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
#include <iomanip>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int m, n, x, y;
        bool flag = true;
        cin >> m >> n >> x >> y;
        x--;
        y--;
        for(int k = x; k < m*n; k+=m){
            if(k % n == y){
                cout << k + 1 <<"\n";
                flag = false;
                break;
            }
        }
        if(flag) cout << -1 <<"\n";
        
    }
    return 0;
}