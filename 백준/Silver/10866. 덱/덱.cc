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

using namespace std;

class Deque {
private:
	int* deque = {};
	int begin, end;
public:
	Deque(int n) {
		deque = new int[n];
		begin = -1;
		end = -1;
	}

	void push_front(int num);
	void push_back(int num);
	void pop_front();
	void pop_back();
	void size();
	bool empty();
	void front();
	void back();

	~Deque() {
		delete[] deque;
	}
};

void Deque::push_front(int num) {
	if (empty()) {
		begin = 0;
		end = 0;
		deque[begin] = num;
	}
	else {
		for (int i = end; i >= begin; i--) {
			deque[i + 1] = deque[i];
		}
		deque[begin] = num;
		end++;
	}
}

void Deque::push_back(int num) {
	if (empty()) {
		begin = 0;
		end = 0;
		deque[begin] = num;
	}
	else {
		end++;
		deque[end] = num;
	}
}

void Deque::pop_front() {
	if (empty()) {
		cout << -1 << endl;
	}
	else {
		cout << deque[begin] << endl;
		deque[begin] = NULL;
		begin++;
	}
}

void Deque::pop_back() {
	if (empty()) {
		cout << -1 << endl;
	}
	else {
		cout << deque[end] << endl;
		deque[end] = NULL;
		end--;
	}
}

void Deque::size() {
	if (empty()) {
		cout << 0 << endl;
	}
	else {
		cout << end - begin + 1 << endl;
	}
}

bool Deque::empty() {
	if (begin == -1 || begin > end) {
		return true;
	}
	else {
		return false;
	}
}

void Deque::front() {
	if (empty()) {
		cout << -1 << endl;
	}
	else {
		cout << deque[begin] << endl;
	}
}

void Deque::back() {
	if (empty()) {
		cout << -1 << endl;
	}
	else {
		cout << deque[end] << endl;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int n;
	cin >> n;
	Deque d(n);

	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;

		if (cmd == "push_front") {
			int num;
			cin >> num;

			d.push_front(num);
		}

		else if (cmd == "push_back") {
			int num;
			cin >> num;

			d.push_back(num);
		}

		else if (cmd == "pop_front") {
			d.pop_front();
		}

		else if (cmd == "pop_back") {
			d.pop_back();
		}

		else if (cmd == "size") {
			d.size();
		}

		else if (cmd == "empty") {
			cout << d.empty() << endl;
		}

		else if (cmd == "front") {
			d.front();
		}

		else if (cmd == "back") {
			d.back();
		}
	}

	return 0;
}
