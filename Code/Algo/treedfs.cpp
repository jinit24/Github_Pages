#include <bits/stdc++.h>
using namespace std;

int T;
// p - parent, d- depth from root
vector<int> p, d;
// tin - time when first entered
vector<int> tin, tout;
// g - graph
vector<vector<int>> g;

void dfs(int v, int par = -1, int dep = 0) {
	p[v] = par;
	d[v] = dep;
	tin[v] = T++;
	for (auto to : g[v]) {
		if (to == par) continue;
		dfs(to, v, dep + 1);
	}
	tout[v] = T++;
}

// v is ancestor to u
bool isAnc(int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	T = 0;
	p = d = vector<int>(n);
	tin = tout = vector<int>(n);
	g = vector<vector<int>>(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0);

	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		vector<int> v(k);
		int it;
		for (int i=0;i<k;i++) {
			cin >> it;
			it--;
			v[i] = it;
		}
		
		int u = v[0];
		for(int i=0;i<k;i++)
			if(d[v[i]]>d[u])
				u = v[i];

	// u now has maximum depth node

		for (int i=0;i<k;i++) {
			if (v[i] == u) continue;
			if (p[v[i]] != -1) v[i] = p[v[i]];
		}
		bool ok = true;
		for (int i=0;i<k;i++) ok &= isAnc(v[i], u);
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	// return 0;
}