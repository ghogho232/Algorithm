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

    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i * i <= n; i++)
        cnt++;
    cout << cnt;
    return 0;
}
