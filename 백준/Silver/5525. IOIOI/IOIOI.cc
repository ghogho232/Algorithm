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
    int n, m, flag = 0, cnt = 0;
    string str;
    cin >> n >> m >> str;
    for(int i = 0; i < m; i++){
        int k = 0;
        if(str[i] == 'O')
            continue;
        while(str[i + 1] == 'O' && str[i + 2] == 'I'){
            k++;
            if(k == n){
                cnt++;
                k--;
            }
            i += 2;
        }
    }
    cout << cnt;
    return 0;
}