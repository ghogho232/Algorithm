#include<cstdio>
#include<iostream>
#include<stack>

using namespace std;

int main() {
	int n;
	int sum = 0;
	cin >> n;
	stack<int> st;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a != 0)
			st.push(a);
		else if (a == 0)
			st.pop();		
	}
	while(1){
		if (st.size() == 0)
			break;
		sum += st.top();
		st.pop();
	}
	cout << sum;
}