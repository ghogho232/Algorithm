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

string arr[5];
int k;
int d[5];

void r() {
    for (int i = 1; i <= 4; i++) {
        if (d[i] == 1) {
            string tmp = "";
            tmp=arr[i].back();
            arr[i].insert(0,tmp);
            arr[i].pop_back();
        }
        else if(d[i]==-1){
            char tmp = arr[i].front();
            arr[i].push_back(tmp);
            arr[i].erase(arr[i].begin());
        }
    }

}
void rotation(int num, int dir) {
    d[num] = dir;

    for (int left = num-1; left >= 1; left--) {
        int right = left + 1;
        if (arr[left][2] == arr[right][6])
            break;
        else
            d[left] = -d[right];
    }

    for (int right = num + 1; right <= 4; right++) {
        int left = right - 1;
        if (arr[left][2] == arr[right][6])
            break;
        else
            d[right] = -d[left];
    }   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = 0;
    for (int i = 1; i <= 4; i++) {
        cin >> arr[i];
    }
    cin >> k;
    for (int i = 0; i < k; i++) {

        int a, b;
        cin >> a >> b;
        rotation(a, b);
        r();        
        memset(d, 0, sizeof(d));
    }

    for (int i = 1; i <= 4; i++) {
        if (arr[i][0] == '1') {
            ans += pow(2, i-1);
        }
    }
    cout << ans;
    return 0;
}