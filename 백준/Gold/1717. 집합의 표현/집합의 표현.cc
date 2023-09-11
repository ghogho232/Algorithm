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

int arr[1000001];

int Find(int x){
    if (x == arr[x])
        return x;
    return arr[x] = Find(arr[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x>y)
        arr[x] = y;
    else    
        arr[y] = x;
}

void IsUnion(int x, int y){
    x = Find(x);
    y = Find(y);
    if (x == y)
        cout << "YES\n";
    else 
        cout <<"NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        arr[i] = i;
    }
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >>c; 
        if(a == 0)
            Union(b,c);
        else
            IsUnion(b,c);
    }
    return 0;
}