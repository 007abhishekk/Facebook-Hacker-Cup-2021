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

const int N = 8e5 + 7, lg = __lg(N) + 2;
int par[N][lg], dist[N];
vector<int> adj[N], tin(N);
vector<pair<int,int>> same_f[N];
int timer, ans;

int lca(int u, int v) {
   if(dist[u] < dist[v])
      swap(u, v);

   int diff = dist[u] - dist[v];
   while(diff > 0) {
      int j = __lg(diff);
      u = par[u][j];
      diff -= (1 << j);
   }
   if(u == v) {
      return u;
   }
   
   for(int i = lg - 1; i >= 0; --i) {
      int p_u = par[u][i], p_v = par[v][i];
      if(p_u != p_v and p_u != -1 and p_v != -1) {
         u = p_u;
         v = p_v;
      }
   }
   return par[u][0];
}

void dfs_(int v, int p, int dis = 0) {
   par[v][0] = p;
   dist[v] = dis;
   tin[v] = timer++;
   for(int z: adj[v]) {
      if(z != p) {
        dfs_(z, v, dis + 1);
      }
   }
}

void pre(int n) {
   for(int i = 1; i < lg; ++i) {
      for(int j = 0; j < n; ++j) {
         if(par[j][i - 1] == -1) continue;
         int p = par[j][i - 1];
         par[j][i] = par[p][i - 1];
      }
   }
}

void pre_LCA(int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < lg; ++j)
            par[i][j] = -1;
    }
    dfs_(0, -1);
    pre(n);
}

int dfs(int v, int p, vector<int> &path) {
    int sum = 0;
    for(int to: adj[v]) {
        if(to == p) continue;
        sum += dfs(to, v, path);
    }
    sum += path[v];
    if(!sum && v) ++ans;
    return sum;
}

void solve(){
    int n;
    cin >> n;
    timer = 0;
    vector<int> path(n, 0);
    ans = 0;
    for(int i = 0; i < n; ++i) {
        adj[i].clear();
        same_f[i].clear();
    }
    for(int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pre_LCA(n);
    for(int i = 0; i < n; ++i) {
        int F;
        cin >> F;
        same_f[F - 1].push_back({tin[i], i});
    }
    tin.resize(n);
    for(int j = 0; j < n; ++j) {
        if(sz(same_f[j]) > 1) {
            sort(all(same_f[j]));
            for(int i = 0; i < sz(same_f[j]) - 1; ++i) {
                int U = same_f[j][i].second;
                int V = same_f[j][i + 1].second;
                int L = lca(U, V);
                /* range path sum */
                path[U]++;
                path[V]++;
                path[L] -= 2;
            }       
        }
    }
    debug(path);
    dfs(0, -1, path);
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