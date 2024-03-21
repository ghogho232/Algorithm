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
    int n;
    string arr[51];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int size = arr[0].length();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < size; j++){
            for(int k = 0; k < n; k++){
                if(arr[i][j] != arr[k][j]){
                    arr[i][j] = '?';
                }
            }
        }
    }
    cout << arr[n-1];
    return 0;
}