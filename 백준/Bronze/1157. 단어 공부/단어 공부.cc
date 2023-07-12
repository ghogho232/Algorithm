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

	int arr[26] = { 0 };
	int max = -1; 
	char res;
	string str;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') str[i] = str[i] - 'a' + 'A'; 

		if (++arr[str[i] - 'A'] > max) {
			max = arr[str[i] - 'A'];
			res = str[i];
		}
	}

	int check = 0; 

	for (int i = 0; i < 26; i++) {
		if (max == arr[i]) check++;
	}

	if (check == 1) cout << res;
	else cout << "?";

	return 0;
}