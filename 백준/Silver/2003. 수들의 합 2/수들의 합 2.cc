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
    int n,m;
    int arr[10001];
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int tmp = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        tmp += arr[i];
        if(tmp == m){
            cnt++;
        }
        if(tmp > m){
            tmp = 0;
            continue;
        }
        for(int j = i+1; j < n; j++){
            tmp += arr[j];
            if(tmp == m){
                cnt++;
            }
            if(tmp > m){
                tmp = 0;
                break;;
            }
            if(j == n-1){
                tmp = 0;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}