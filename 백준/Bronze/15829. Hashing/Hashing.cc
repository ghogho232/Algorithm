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
    int n;
    cin >> n;
    string str;
    cin >> str;
    int arr[51];
    int sum = 0;
    for(int i = 0; i < n; i++){
        arr[i] = str[i] - 'a' + 1;
        sum += arr[i] * pow(31,i);
    }
    cout << sum;
    return 0;
}