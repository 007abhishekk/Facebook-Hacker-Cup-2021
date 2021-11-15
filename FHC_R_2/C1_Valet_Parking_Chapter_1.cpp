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
    int n, m, k; cin >> n >> m >> k;
    char a[n][m], b[n][m], c[n][m];
    vector<int> pos[m];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
            b[i][j] = c[i][j] = a[i][j];
            if(a[i][j] == 'X') {
                pos[j].push_back(i);
            }
        }
    }
    bool isClear = true;
    int ans = 0;
    for(int i = 0; i < m; ++i) {
        isClear &= a[k - 1][i] == '.';
        ans += a[k - 1][i] == 'X';
    }
    if(isClear) {
        debug("A");
        cout << 0 << '\n';
        return;
    }
    if(n == 1) {
        cout << ans << '\n';
        return;
    }
    int cur = ans;
    debug(cur);
    for(int i = 0; i < cur; ++i) {
        bool done = false;
        for(int x = 1; x < n; ++x) {
            for(int y = 0; y < m; ++y) {
                if(b[x - 1][y] == 'X') continue;
                if(b[x][y] == '.') continue;
                b[x - 1][y] = 'X';
                b[x][y] = '.';
                done = true;
            }
        }

        int cnt = 0;
        for(int y = 0; y < m; ++y) {
            cnt += b[k - 1][y] == 'X';
        }
        if(done)
            amin(cur, done * (i + 1) + cnt);
    }

    for(int i = 0; i < cur; ++i) {
        bool done = false;
        for(int x = n - 2; x >= 0; --x) {
            for(int y = 0; y < m; ++y) {
                if(c[x + 1][y] == 'X') continue;
                if(c[x][y] == '.') continue;
                c[x + 1][y] = 'X';
                c[x][y] = '.';
                done = true;
            }
        }

        int cnt = 0;
        for(int y = 0; y < m; ++y) {
            cnt += c[k - 1][y] == 'X';
        }
        if(done)
            amin(cur, done * (i + 1) + cnt);
    }
    cout << cur << '\n';
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