#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<deque>
#include <sstream>
#include <iomanip>
#define ll long long
#define INF 987654321

using namespace std;


int main() {
    char mo[5] = {'a', 'e', 'i', 'o', 'u'};

    while (true) {
        string str;
        cin >> str;
        if (str == "end") break;

        bool is_mo = false, can = true;
        char tmp[20];

        // 모음/자음 구분
        for (int i = 0; i < str.size(); i++) {
            bool isVowel = false;
            for (int j = 0; j < 5; j++) {
                if (str[i] == mo[j]) {
                    isVowel = true;
                    is_mo = true;
                    break;
                }
            }
            tmp[i] = isVowel ? 'm' : 'j';
        }

        // 같은 글자 연속 검사 (e, o 제외)
        for (int i = 1; i < str.size(); i++) {
            if (str[i] == str[i - 1] && str[i] != 'e' && str[i] != 'o') {
                can = false;
                break;
            }
        }

        // 모음/자음 3연속 검사
        int cnt = 1;
        for (int i = 1; i < str.size(); i++) {
            if (tmp[i] == tmp[i - 1]) {
                cnt++;
                if (cnt == 3) {
                    can = false;
                    break;
                }
            } else {
                cnt = 1;
            }
        }

        // 최종 판별
        if (can && is_mo) {
            cout << "<" << str << "> is acceptable.\n";
        } else {
            cout << "<" << str << "> is not acceptable.\n";
        }
    }

    return 0;
}