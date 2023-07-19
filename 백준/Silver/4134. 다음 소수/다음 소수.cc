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

bool isPrime(long long a) {
    if (a == 0 || a == 1)
        return false;

    for (long long i = 2; i * i <= a; i++) {
        if (a % i == 0)
            return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    while (n--) {
        long long a;
        cin >> a;
        for (a;; a++) {
            if (isPrime(a)) {
                cout << a << "\n";
                break;
            }
        }
    }
    return 0;
}

