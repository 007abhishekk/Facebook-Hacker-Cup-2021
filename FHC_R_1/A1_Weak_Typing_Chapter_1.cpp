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
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    vector<int> pos[2];
    for(int i = 0; i < n; ++i) {
        if(s[i] == 'O') pos[0].push_back(i);
        if(s[i] == 'X') pos[1].push_back(i);
    }
    if(!sz(pos[0]) or !sz(pos[1])) {
        cout << 0 << '\n';
        return;
    }
    int last = min(pos[0].front(), pos[1].front());
    int p = (last == pos[0].front() ? 0 : 1);
    while(true) {
        if(lower_bound(all(pos[p ^ 1]), last) == pos[p ^ 1].end()) break;
        last = *lower_bound(all(pos[p ^ 1]), last);
        p ^= 1;
        ++ans;
    }
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