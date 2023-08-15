#include <iostream>
#include<algorithm>

using namespace std;

bool pages[101] = { false }; //존재하는 페이지를 입력 할 배열 false로 선언

int main() {
    int n, m; //N=마지막 페이지 M=현재 존재하는 페이지
    cin >> n >> m;
     
    for (int i = 0; i < m; i++) {
        int page;
        cin >> page;
        pages[page] = true;
    }
    int start, end = 0;
    int ink = 0;

    for (int i = 1; i <= n; i++) {
        if (pages[i])
            continue;
        if (end == 0) {
            start = i;
            end = i;
        }
        else if (end + 3 >= i) {
            end = i;
        }
        else {
            ink += 5 + (end - start + 1) * 2;
            start = i;
            end = i;
        }
    }

    if (end != 0)
        ink += 5 + (end - start + 1) * 2;
    
    cout << ink;
}