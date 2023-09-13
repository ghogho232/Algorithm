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

int gcd(int p, int q){
    if(q==0)
        return p;
    return gcd(q,p%q);
}

int lcm(int p, int q){
    return (p*q)/gcd(p,q);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    cin >> a >> b;
    cout << gcd(a,b)<<"\n";
    cout << lcm(a,b);
    return 0;
}