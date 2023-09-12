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

int arr[200001];
int Size[200001];

int Find(int x){
    if (x == arr[x])
        return x;
    return arr[x] = Find(arr[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x != y){
        if(Size[x] < Size[y])
            swap(x, y);
        arr[y] = x;
        Size[x] += Size[y];
        Size[y] = 0;
    }
}


bool IsUnion(int x, int y){
    x = Find(x);
    y = Find(y);

    return (x == y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, F;
    cin >> T;
    while(T--){
        cin >> F;
        map<string,int>m;
        int idx = 0;
        for(int i=0 ; i<200001 ; i++) {
            arr[i] = i;
            Size[i] = 1;
        }

        for(int i = 0; i < F; i++){
            string str1, str2;
            cin >> str1 >> str2;
            if(m.find(str1) == m.end())
                m[str1] = idx++;
            if(m.find(str2) == m.end())
                m[str2] = idx++;

            int tmp1 = Find(m[str1]);
            int tmp2 = Find(m[str2]);

            if(tmp1 == tmp2){
                cout << max(Size[tmp1],Size[tmp2]) <<"\n";
            }
            else{
                Union(tmp1,tmp2);
                cout << max(Size[tmp1],Size[tmp2])<<"\n";
            }
        }
    }
    return 0;
}