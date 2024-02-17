#define _CRT_SECURE_nO_WARnInGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
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
#define INF 987654321

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    char arr[51][51];
    cin >> n >> m;
    int length = max(n,m);
    int ans = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }
    for(int k = 1; k <= length; k++){
        for(int i = 1; i <= n ; i++){
            for(int j = 1; j <= m; j++){
                if(k + i > n || k + j > m) continue;
                int a1 = arr[i][j]-'0';
                int a2 = arr[i][j+k]-'0';
                int a3 = arr[i+k][j]-'0';
                int a4 = arr[i+k][j+k]-'0';
                if(a1==a2&&a2==a3&&a3==a4) ans = max(ans,(k+1)*(k+1));
            }
        }
    }
    cout << ans <<'\n';
    return 0;
}