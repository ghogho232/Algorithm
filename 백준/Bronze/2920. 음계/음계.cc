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
#include <iomanip>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int arr[9];
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < 8; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < 8; i++){
        if(arr[i]+1 == arr[i+1])
            cnt1++;
        if(arr[i]-1 == arr[i+1])
            cnt2++;
    }
    if(cnt1 == 7)
        cout << "ascending\n";
    else if(cnt2 == 7)
        cout << "descending\n";
    else cout << "mixed\n";
}