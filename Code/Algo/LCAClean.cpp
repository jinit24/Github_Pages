#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int> 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int T;
vector<int> d,p;
vector<int> tin, tout;
vector<vector<int>> g;
int n,q;
vector <vector <int>> dp;

void dfs(int v, int par = -1, int dep = 0){

    p[v] = par;
    dp[v][0] = par;
    d[v] = dep;
    tin[v] = T++;
    
    for(int i=1;i<=ceil(log2(n));i++)
        if(dp[v][i-1]!=-1)
            dp[v][i] = dp[dp[v][i-1]][i-1];

    for (auto to : g[v]) {
        if (to == par)continue;
        dfs(to, v, dep + 1);
    }

    tout[v] = T++;
}

// v is ancestor to u
bool isAnc(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int lca(int a,int b){
    if(d[a]>d[b])
        swap(a,b);
    if(isAnc(a,b))
        return a;
    for(int i= ceil(log2(n));i>=0;i--)
        if(!isAnc(dp[b][i],a) && dp[b][i]!=-1)
            b = dp[b][i];

    return dp[b][0];

}

int32_t main() {
    fast_io;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        T = 0;
        p =d = vector<int>(n);
        tin = tout = vector<int>(n);
        g = vector<vector<int>>(n);
        dp.assign(n, vector<int>(ceil(log2(n)) + 1));
        for (int i = 0; i < n - 1;i++) {
            cout << i << endl;
            int a,b;
            cin >> a >> b;
            a--;b--;
            g[a].push_back(b);
            g[b].push_back(a);
            cout << i << endl;
        }
        dfs(0);
        // for(int i=0;i<n;i++)
        //     for(int j=i;j<n;j++)
        //         cout << lca(i,j) << " " << i <<" " << j << endl;
        // cin >> q;
        // while(q--){
        //     int a,b;
        //     cin >> a >> b;
        //     a--;b--;
        //     cout << lca(a,b) + 1 << end;;
        //     cout << maxv << endl;
        // }
    }
}