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
    int a, b,c,d;
    cin >> a >> b >> c >> d;
    int down = lcc(b, d);
    a = a * (down / b);
    c = c * (down / d);
    int up = a + c;
    int nup, ndown;
    if (gcd(up, down)>=2) {
        nup = up/gcd(up, down);
        ndown = down/gcd(up, down);
        cout << nup << " " << ndown;
    }
    else
        cout << up << " " << down;
    return 0;
}
