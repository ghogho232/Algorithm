#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
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
using namespace std;

int graph[10001];

void postOrder(int begin, int end) {
    if (begin >= end)
        return;
    if (begin == end - 1) {
        cout << graph[begin] << "\n";
        return;
    }
    int idx = begin + 1;
    while (idx < end) {
        if (graph[begin] < graph[idx])
            break;
        idx++;
    }
    postOrder(begin + 1, idx);
    postOrder(idx, end);
    cout << graph[begin] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,Idx = 0;
    while (cin >> n) {
        graph[Idx++] = n;
    }

    postOrder(0, Idx);
    return 0;
}