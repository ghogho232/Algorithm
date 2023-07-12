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
	string subject;
	double g;
	string grade;
	double score[21] = { 0 };
	double sum = 0;
	double n ;
	double m = 0.0;
	for(int i = 0 ; i < 20;i++) {
		cin >> subject >> g >> grade;
		if (grade == "P")
			continue;
		if (grade[0] == 'A') n = 4;
		else if (grade[0] == 'B') n = 3;
		else if (grade[0] == 'C') n = 2;
		else if (grade[0] == 'D') n = 1;
		else if (grade[0] == 'F') n = 0;

		if (grade[1] == '+') n += 0.5;

		sum += g * n;
		m += g;
	}
	double average = sum / m;

	cout << average;
}