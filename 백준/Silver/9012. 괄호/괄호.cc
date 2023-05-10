#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

bool VPS(string str) {
	stack<char> s;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') 
			s.push(str[i]);
		else if (str[i] == ')') {
			if (s.empty()) 

				return false; 

			else
				s.pop();
		}
		
	}return (s.empty());
}
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string str;
		cin >> str;
		if (VPS(str)) {
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;
	}
}

