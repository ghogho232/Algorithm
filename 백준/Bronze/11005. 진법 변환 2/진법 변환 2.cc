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
	long long n;
	int b;
	stack<char> s;
	char ch;
	cin >> n >> b;
	while (n > 0) {
		ch = n % b;
		n /= b;
		if (ch >= 10)
			s.push(ch + 55);
		else
			s.push(ch + 48);
	}
	while(!s.empty()) {
		cout << s.top();
		s.pop();
	}
	return 0;
}