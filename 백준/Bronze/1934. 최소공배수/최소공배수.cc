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

using namespace std;

int gcd(int a, int b) {
    while (true) {
        int r = a % b;
        if (r == 0)
            return b;
        a = b;
        b = r;
    }
}
int lcc(int a, int b) {
    return (a * b) / gcd(a, b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << lcc(a, b)<<"\n";
    }

    return 0;
}
