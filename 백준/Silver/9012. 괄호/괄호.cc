#include <iostream>
#include <stack>

using namespace std;

bool VPS(string str) {
    stack<char> st; //문자열 입력받을 스택
    for (int i = 0; i < str.length(); i++) { //문자열 끝까지
        if (str[i] == '(') //"(" 일 때 push
            st.push(str[i]); 
        else if (str[i] == ')') {//")"일 때 
            if (st.empty()) //비었는지 확인
                 return false; //비어있다면 짝이 없으므로 false
            else
               st.pop();    //비어있지 않으면 pop
        }
    }
    return (st.empty()); //반복문 후에 괄호가 있다면 짝 없음
}

int main() {
    int caseSize;
    cin >> caseSize; //테스트 케이스 입력

    for (int i = 0; i < caseSize; i++) {
        string str;
        cin >> str; //문자열 입력받기
        if (VPS(str)) 
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}