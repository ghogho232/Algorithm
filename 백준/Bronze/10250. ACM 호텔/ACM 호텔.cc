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

    int T,h,w,n;
    cin >> T;
    while(T--){
        cin >> h >> w >> n;
        int hcnt = 0;  
        int ans = 1;    
        for(int i = 1; i<=n; i++){
            if(hcnt == h){
                ans -= h*100;
                ans +=1;
                hcnt = 0;
            }
            ans += 100;
            hcnt++;
        }
        cout << ans<<"\n";
    }


    return 0;
}