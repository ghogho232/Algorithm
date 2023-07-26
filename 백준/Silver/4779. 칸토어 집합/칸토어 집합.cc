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

string str;

void kantoer(int left, int right) {
	if (right - left== 1) {
		return;
	}

	int s = right-left;
	int third = s / 3;

	for (int i = left + third; i < right-third; i++) {
		str[i] = ' ';
	}

	kantoer(left, left + third);
	kantoer(right - third, right);

}

int main() {
	int n;
	while (cin >> n) {
		int size = pow(3, n);
		str.clear();
		str.append(size, '-');
		kantoer(0, size);
		cout << str<<"\n";

	}
}

