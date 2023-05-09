#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {

	bool ans = true;
	int cnt = 0;
	string str1, str2;
	int alphabet1[26] = { 0 };
	int alphabet2[26] = { 0 };
	cin >> str1;
	cin >> str2;


	for (int j = 0; j < str1.size(); j++) {
		alphabet1[str1[j] - 'a']++;
	}
	for (int i = 0; i < str2.size(); i++) {
		alphabet2[str2[i] - 'a']++;
	}
	for (int j = 0; j < 26; j++) {
		if (alphabet1[j] != alphabet2[j]) {
			cnt += abs(alphabet1[j] - alphabet2[j]);
		}
	}
	cout << cnt;

	return 0;
}