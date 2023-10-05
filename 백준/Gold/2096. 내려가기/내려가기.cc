#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
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
    int arr[3];
    int dpmin[3];
    int dpmax[3];
    int n;
    cin >> n;
    cin >> arr[0] >> arr[1] >> arr[2];

    for(int i = 0; i < 3; i++){
        dpmax[i] = dpmin[i] = arr[i];
    }

    for(int i = 1; i < n; i++){
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;

        int tmpMax0 = dpmax[0];
        int tmpMax1 = dpmax[1];
        int tmpMax2 = dpmax[2];

        dpmax[0] = max(dpmax[0], dpmax[1]) + n0;
        dpmax[1] = max(max(tmpMax0, dpmax[1]),dpmax[2]) + n1;
        dpmax[2] = max(tmpMax1, dpmax[2]) + n2;

        int tmpMin0 = dpmin[0];
        int tmpMin1 = dpmin[1];
        int tmpMin2 = dpmin[2];

        dpmin[0] = min(dpmin[0], dpmin[1]) + n0;
        dpmin[1] = min(min(tmpMin0, dpmin[1]),dpmin[2]) + n1;
        dpmin[2] = min(tmpMin1, dpmin[2]) + n2;
    }
    int MAX = max(max(dpmax[0],dpmax[1]),dpmax[2]);
    int MIN = min(min(dpmin[0], dpmin[1]), dpmin[2]);
    cout << MAX <<" " << MIN;
    return 0;
}