#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
int n,q;
stack <int> s;
vector <vector <int> > g,g_t,c; 
vector <int> v;

// First dfs is performed and vertices are pushed to stack. Then we reverse the graph and perform dfs 
// All the scc are stored separately in 'c'
void dfs(int i){
	v[i]=1;
	for(auto it : g[i])
		if(!v[it])
			dfs(it);
	s.push(i);
}

void dfs2(int i,vector <int> &temp){
	v[i]=1;
	temp.push_back(i);
	for(auto it : g_t[i])
		if(!v[it]){
			dfs2(it,temp);
		}
}

void scc(){
	v = vector <int>(n+1);
	while(!s.empty())
	{
		int top = s.top();
		s.pop();
		if(!v[top]){
			// cout << top << endl;
			vector <int> temp;
			dfs2(top,temp);
			c.push_back(temp);
			temp.clear();
		}
	}
}


int32_t main(){
	fast_io;
	cin >> n >> q;
	g = g_t = vector <vector <int> >(n+1);
	v = vector <int>(n+1);
	for(int i=1;i<=q;i++)
	{
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g_t[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
		if(!v[i])
			dfs(i);
	scc();
	for(auto it : c){
		for(auto i : it)
			cout << i << " ";
		cout << endl;
	}

}	