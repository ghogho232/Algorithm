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

int arr[500001];

int Find(int x){
    if (x == arr[x])
        return x;
    return arr[x] = Find(arr[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x != y)
        arr[y] = x;
}

bool IsUnion(int x, int y){
    x = Find(x);
    y = Find(y);

    return (x == y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m, cnt = 0;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        arr[i] = i;
    }

    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        if(!IsUnion(a,b)){
            Union(a,b);
        }
        else {
            if(cnt ==0){
                cnt = i+1;
            }
        }
    }
    cout << cnt;

    return 0;
}