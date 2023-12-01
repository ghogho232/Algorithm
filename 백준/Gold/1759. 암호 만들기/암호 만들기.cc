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

    using namespace std;
    int l, c;
    int a=0,b=0;
    char arr[16];
    vector<char> ans;
    int visited[16];
    vector<int>v;
    bool is_consonant(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return false;
        return true;
    }
    void dfs(int k, int asc, int a, int b){
        if(k == l&& (a >= 2 && b >= 1)){
            for(auto it=ans.begin(); it != ans.end(); it++){
                cout << *it;
            }
            cout <<"\n";
            a=0,b=0;
            return;
        }
        else if(k == l && (a<2 || b <1))
            return;
        for(int i = asc; i < c; i++){
            if(!visited[i]){
                visited[i] = 1;
                ans.push_back(arr[i]);
                if(is_consonant(arr[i]))
                    dfs(k+1, i,a+1,b);
                else
                    dfs(k+1, i, a, b+1);
                visited[i] = 0;
                ans.pop_back();            
            }
        }
    }

    int main(void) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        cin >> l >> c;
        for(int i = 0; i < c; i++){
            cin >> arr[i];

        }
        sort(arr, arr+c);
        dfs(0, 0, a, b);

        return 0;
    }   