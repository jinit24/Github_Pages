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
int dp[100001][17];
int wmax[100001][17];


void dfs(int v, int par = -1, int dep = 0){
    p[v] = par;
    d[v] = dep;
    tin[v] = T++;
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

string toBinary(int n)
{
    string r="";
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

// Binary lifting is used to calculate the lca,
// O(log(n)) with "O(n*log(n)) pre-processing"
int Pre()
{
    for(int i=0;i<n;i++){
        dp[i][0] = p[i];
    }

    int maxd = *(max_element(d.begin(),d.end()));
    int temp = log2(maxd);

    if((1<<temp)== maxd)
        maxd = temp;
    else
        maxd = temp + 1;

    for(int h=1;h<=maxd;h++)
        for(int i=0;i<n;i++){
            if(dp[i][h-1]==-1)
                dp[i][h]=-1;
            else
                dp[i][h] = dp[dp[i][h-1]][h-1];
        }

    return maxd;
}


int lca(int a,int b)
{
    if(d[a]>d[b])
        swap(a,b);

    // Making the nodes of the have same height
    int dif = d[b] - d[a];
    string temp = toBinary(dif);
    for(int i=0;i<temp.size();i++){
        if((temp[i]-'0')==1){
            b = dp[b][temp.size()-i-1];

        }
    }
    // If they are equal, a is the lca
    if(a==b)
        return a;

    // Keep moving up the tree ,if after jump they are equal, we have crossed the lca
    // Hence, skip that jump and continue otherwise
    // we will reach just one below the lca
    temp = toBinary(d[a]);
    for(int i=temp.size()-1;i>=0;i--){
        int n1 = dp[a][i];
        int n2 = dp[b][i];
        if(n1==n2)
            continue;
        else{
            a = n1;
            b = n2;
        }

    }
    return p[a];
}


int32_t main() {
    fast_io;
    int t;
    cin >> t;
    while(t--){
        memset(dp,0,sizeof(dp));
        cin >> n;
        T = 0;
        p =d = vector<int>(n);
        tin = tout = vector<int>(n);
        g = vector<vector<int>>(n);
        for (int i = 0; i < n - 1; ++i) {
            int a,b;
            cin >> a >> b;
            a--;b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(0);
        int maxd = Pre();
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<=maxd;j++)
        //         cout << dp[i][j] << " ";
        //     cout << endl;
        // }
        // cout << lca(0,4) << endl;
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
                cout << lca(i,j) << " " << i <<" " << j << endl;
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