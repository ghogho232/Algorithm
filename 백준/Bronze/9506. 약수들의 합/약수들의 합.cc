#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>


using namespace std;

int main() {
    while (1) {
        int n;
        cin >> n;
        int sum = 0;

        if (n == -1)
            break;
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                v.push_back(i);
            }
        }
        for (int i = 0; i < v.size() - 1; i++) {
            sum += v[i];
        }
        
        if (sum == n) {
            cout << n << " = ";
            for (int i = 0; i < v.size() - 2; i++) {
                cout << v[i] << " + ";
            }
            cout << v[v.size() - 2] << "\n";
        }
        else
            cout << n << " is NOT perfect." <<"\n";
        
    }
    return 0;
}