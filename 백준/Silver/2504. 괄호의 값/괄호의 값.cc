#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;


int main() {
	string str;
	stack<char> stk;
	int ans = 0;
	int temp = 1;

	cin >> str;
	
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			temp *= 2;
			stk.push(str[i]);
		}
		else if (str[i] == '[') {
			temp *= 3;
			stk.push(str[i]);
		}
		else if (str[i] == ')') {
			if (stk.empty() || stk.top() != '('){
				ans = 0;
				break;
			}
			if (str[i - 1] == '(') {
				ans += temp;
				temp /= 2;
				stk.pop();
			}
			else {
				temp /= 2;
				stk.pop();
			}
		}
		else if (str[i] == ']') {
			if (stk.empty() || stk.top() != '[') {
				ans = 0;
				break;
			}
			if (str[i - 1] == '[') {
				ans += temp;
				temp /= 3;
				stk.pop();
			}
			else {
				temp /= 3;
				stk.pop();
			}
		}
		
	}

	if (!stk.empty())
		ans = 0;
	cout << ans;

	return 0;

}