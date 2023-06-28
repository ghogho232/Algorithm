#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

bool palindrome(int n) {
	string str = to_string(n);
	int cnt = 0;
	for (int i = 0; i < str.length() / 2; i++) {
		if (str[i] != str[str.length() - i - 1])
			cnt++;
	}
	if (cnt == 0)
		return true;
	else
		return false;
}
bool isPrime(int n) {
	if (n < 2)
		return false;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) 
			return false;
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	while (1) {
		if (isPrime(n) && palindrome(n)) {
			cout << n;
			break;
		}
		n++;
	}
	return 0;
}