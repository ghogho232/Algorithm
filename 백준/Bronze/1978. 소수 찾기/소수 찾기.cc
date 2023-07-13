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
vector<int>v;

void isPrime(int n) { 
	int a = 0; 
	if (n == 1) ; 
	for (int i = 2; i < n; i++) {
		if (n % i != 0)
			a++; 
		if (a > n - 2)
			break; 
	}
	if (a == n - 2)
		v.push_back(n); 
	
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		isPrime(a);
	}
	cout << v.size();
}