#include <string>
#include <vector>
#define ll long long

using namespace std;

bool valid(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t, ll mid){
    ll gold = 0;
    ll silver = 0;
    ll total = 0;
    for(int i = 0; i < g.size(); i++){
        ll time = t[i];
        ll rtt = 2 * time;
        ll cnt = mid / rtt;
        if(mid % rtt >= time) cnt++;
        ll max_cnt = w[i] * cnt;
        
        gold += min((ll)g[i], max_cnt);
        silver += min((ll)s[i], max_cnt);
        total += min((ll)(s[i]+g[i]), max_cnt);
    }
    if((gold >= a) && (silver >= b) && (total >= a+b)) return true;
    return false;
}
long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    ll begin = 0;
    ll end = 4 * 1e14;
    answer = end;
    while(begin <= end){
        ll mid = (begin + end)/2;
        if(valid(a,b,g,s,w,t,mid)){
            answer = min(answer,mid);
            end = mid - 1;
        }
        else
            begin = mid + 1;
    }
    return answer;
}