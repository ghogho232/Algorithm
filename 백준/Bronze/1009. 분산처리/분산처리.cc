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

    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int tmp = 1;
        for(int i = 0; i < b; i++){
            tmp *= a;
            tmp %= 10;
        }
        if(tmp == 0)
            cout << 10<<"\n";
        else
            cout << tmp<<"\n";
        
    }
    return 0;
}