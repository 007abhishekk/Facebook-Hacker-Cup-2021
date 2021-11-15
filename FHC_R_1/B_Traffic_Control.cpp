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
    int A, B; cin >> A >> B;
    vector<vector<int>> a(n, vector<int> (m, 1000));
    if(A < n + m - 1 or B < n + m - 1) {
        cout << "Impossible\n";
        return;
    }
    for(int i = 0; i < n; ++i) a[i][0] = a[i][m - 1] = 1;
    for(int i = 0; i < m; ++i) a[0][i] = 1;
    a[n - 1][0] = (B - (n + m - 2));
    a[n - 1][m - 1] = (A - (n + m - 2));
    cout << "Possible\n";
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << a[i][j] << " \n"[j == m - 1];
        }
    }
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