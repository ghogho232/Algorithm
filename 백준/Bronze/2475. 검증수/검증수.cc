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

using namespace std;

int main(){
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    int sum;
    sum = a*a+b*b+c*c+d*d+e*e;
    sum %= 10;
    cout << sum;
}