#include<bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define sz(x) ((int)x.size())
template<typename T, typename U> inline void amin(T &a,U b) { a = (a > b ? b : a);}
template<typename T, typename U> inline void amax(T &a,U b) { a = (a > b ? a : b);}

#ifndef DEBUG_NOW
    #define debug(...) do {} while(0)
#else
    #include "debug.h"
#endif

const int mod = 1e9 + 7;

char xo[] = "OX";

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<pii> ranges;
    vector<int> pos[2];
    i64 g = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] == 'O') pos[0].push_back(i);
        if(s[i] == 'X') pos[1].push_back(i);
    }
    
    // if either character is absent -> ans = 0
    if(!sz(pos[0]) or !sz(pos[1])) {
        cout << 0 << '\n';
        return;
    }

    // push the ranges of continuous X's and O's
    int last = min(pos[0].front(), pos[1].front());
    int p = (last == pos[0].front() ? 0 : 1);
    int L = last, R = last, i = last;
    while(i < n && s[i] != xo[p^1]) {
        if(s[i] == xo[p]) R = i;
        ++i;
    }
    ranges.push_back({L, R});
    while(i < n) {
        p ^= 1;
        last = i;
        L = last, R = last;
        while(i < n && s[i] != xo[p^1]) {
            if(s[i] == xo[p]) R = i;
            ++i;
        }
        ranges.push_back({L, R});
    }
    ranges.push_back({n, n});

    // answer is computed through some precalculation
    debug(ranges);
    vector<i64> suf(sz(ranges) + 5, 0);
    i64 pre_sum = 0;
    for(int i = sz(ranges) - 2; i >= 0; --i) {
        suf[i] = suf[i + 1] + (ranges[i + 1].first - ranges[i].first);
        suf[i] %= mod;
    }
    for(int i = 0; i < sz(ranges) - 1; ++i) {
        pre_sum += ((i + 1) * 1LL * (ranges[i + 1].first - ranges[i].first)) % mod;
        pre_sum %= mod;
    }
    debug(pre_sum);
    debug(suf);
    debug(ranges);
    for(int i = 0; i < sz(ranges) - 1; ++i) {
        pre_sum -= suf[i];
        pre_sum += mod;
        pre_sum %= mod;
        if(!i) {
            g += (ranges[i].second + 1) * 1LL * pre_sum % mod;
            g %= mod;
        } else {
            g += (ranges[i].second - ranges[i - 1].second) * 1LL * pre_sum % mod;
            g %= mod;
        }
        debug(g);
    }
    cout << g << '\n';

}

int main()
{
    ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
    int tests = 1, id = 1; 
    cin >> tests;
    while(tests--){
        cout << "Case #" << id++ << ": ";
       solve(); 
    }
    ifstream cin("in");
    ofstream cout("out");
    #ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}
/* stuff you should look for
    * int overflow, array bounds 
    * special cases (n=1?)
    * DON'T GET STUCK ON ONE APPROACH
    * Try testing against a brute solution
*/