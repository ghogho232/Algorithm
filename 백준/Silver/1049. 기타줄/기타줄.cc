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
    int n, m;
    cin >> n >> m;
    int arr6[51], arr1[51];
    for (int i = 0; i < m; i++) {
        cin >> arr6[i] >> arr1[i];
    }
    sort(arr6, arr6 + m);
    sort(arr1, arr1 + m);   
    int ans = 0;
    int line = n;
    while(line > 0){
        if(line >= 6){
            if(arr6[0] <= arr1[0] * 6){
                ans += arr6[0];
                line -= 6;
            }
            else{
                ans += arr1[0] * line;
                line -= line;
            }
            
        }
        else{
            if(arr6[0] < arr1[0] * line){
                ans += arr6[0];
                line -= 6;
            }
            else{
                ans += arr1[0] * line;
                line -= line;
            }
            
        }
    }
    cout << ans;
    return 0;
}

