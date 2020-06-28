#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int> 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector < vector <int> > g;
vector <int> m;
int n,q;
int counter;
void dfs(int v,int n,int start){
	m[v]=1;
	if(n==0){
		m[v]=0;
		// cout << v << " " << start << endl;
		if(find(g[v].begin(),g[v].end(),start)!=g[v].end()){
			cout << v << " " << start << endl;
			counter++;
		}
		return;
	}
    for (auto to : g[v]) {
        if (!m[to]);
        	dfs(to,n-1,start);
    }
    m[v]=0;
}

int32_t main(){
	fast_io;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> q;
        m = vector<int>(n);
        g = vector<vector<int>>(n);
        for (int i = 0; i <q;i++) {
            int a,b;
            cin >> a >> b;
            a--;b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        counter=0;
        for(int i=0;i<n-4;i++)
        {
        	dfs(i,4,i);
        	m[i]=1;
        }
        cout << counter/2 << endl;
        for(auto it : m)
        	cout << it << " ";
        cout << endl;
    }
}