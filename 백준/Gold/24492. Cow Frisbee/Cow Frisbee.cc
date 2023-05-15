#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include <time.h>
typedef long long ll;
using namespace std;


int main() {
	    int N; cin >> N;
    vector<ll> V(N); for(auto &v : V) cin >> v;
    
    // set<int> st;
    stack<ll> st;
    ll ans = 0;
    
    for(int i = 0; i < N; i++){
        while(!st.empty() && V[st.top()] < V[i]){
            ans += i - st.top() + 1;
            st.pop();
        }
        if(!st.empty()) ans += i - st.top() + 1;
        st.push(i);
    } 
    cout << ans << endl;
    return 0;
}
