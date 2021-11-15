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

void solve(){
    int n, m; cin >> n >> m;
    vector<array<int,3>> init(m);
    for(int i = 0; i < m; ++i) {
        cin >> init[i][0];
        init[i][1] = 0;
        init[i][2] = i;
    } 
    vector<int> changes(m, 0), alt(m, 0);
    vector<int> done(m, 0);
    for(int r = 0; r < n; ++r) {
        multiset<int> mt;
        vector<int> seq(m);
        for(int c = 0; c < m; ++c) {
            cin >> seq[c];
            mt.insert(seq[c]);
            done[c] = 0;
        }
        sort(init.rbegin(), init.rend());
        for(int c = 0; c < m; ++c) {
            if(mt.find(init[c][0]) != mt.end()) {
                done[init[c][2]] = 1;
                mt.erase(mt.find(init[c][0]));
            }
        }
        for(int c = 0; c < m; ++c) {
            if(done[init[c][2]]) continue;
            if(!alt[init[c][2]]) {
                debug("ALT", init[c][0], *mt.begin());
                alt[init[c][2]] = 1;
            } else {
                debug("CHANGE", init[c][0], *mt.begin());
                ++changes[init[c][2]];
            }
            init[c][0] = *mt.begin();
            init[c][1] = 1;
            mt.erase(mt.begin());
        }
        debug(alt);
        debug(changes);
    }
    i64 ans = accumulate(all(changes), 0LL);
    amax(ans, 0);
    cout << ans << '\n';
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