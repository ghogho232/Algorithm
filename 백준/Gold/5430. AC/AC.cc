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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    while (n--) {
        deque<int>d;
        string str,input;
        int a;
        cin >> str >> a;
        cin >> input;
        stringstream ss(input);
        char discard;
        int num;
        while (ss >> discard >> num) {
            d.push_back(num);
        }

        bool isReverse = false; // 덱의 순서가 뒤집혀있는지 여부
        bool error = false; // D 연산 시 덱이 비어있는지 여부
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'R') {
                isReverse = !isReverse; // 덱의 순서를 뒤집음
            }
            else {
                if (d.empty()) {
                    error = true; // 덱이 비어있으면 오류 발생
                    break;
                }
                if (isReverse) {
                    d.pop_back(); // 덱이 뒤집혀있는 경우 맨 뒤 원소를 삭제
                }
                else {
                    d.pop_front(); // 덱이 정상인 경우 맨 앞 원소를 삭제
                }
            }
        }

        if (error) {
            cout << "error\n";
        }
        else {
            cout << '[';
            if (isReverse) {
                while (!d.empty()) {
                    cout << d.back();
                    d.pop_back();
                    if (!d.empty()) cout << ',';
                }
            }
            else {
                while (!d.empty()) {
                    cout << d.front();
                    d.pop_front();
                    if (!d.empty()) cout << ',';
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}
