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
    int tmp = arr[0];
    int cnt = 0;
    int right = 0;
    int left = 0;
    while(right < n){
        if(tmp == m){
            cnt++;
            tmp -= arr[left];
            left++;
            right++;   
            tmp += arr[right];
        }
        else if(tmp < m){
            right++;
            tmp += arr[right];
        }
        else if(tmp > m){
            tmp -= arr[left];
            left++;
        }
    }
    cout << cnt;
    return 0;
}