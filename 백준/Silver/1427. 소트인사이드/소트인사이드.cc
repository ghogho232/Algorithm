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

int main(){
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		for (int j = i + 1; j < str.length(); j++) {
			if (str[i] < str[j]) {
				int temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
	cout << str;
	return 0;
}