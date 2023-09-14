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
const int MOD = 1234567891;
const int M = 31;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int L;
    cin >> L;
    ll sum = 0;
    ll R = 1;
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        sum = (sum + (str[i] - 'a' + 1) * R)%MOD;
        R = (R*M)%MOD;
    }
    cout << sum;
    return 0;
}