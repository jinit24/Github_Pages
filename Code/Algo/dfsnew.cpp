#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> graph;
vector <int> marked,pre;
int n;

void dfs(int curr,int p=-1){
	pre[curr] = p;
	marked[curr] = 1;
	for(auto it : graph[curr]){
		if(marked[it]==0){
			dfs(it,curr);
		}
	}
}

int main(){
	int q;
	cin >> n >> q;
	graph =  vector<vector<int> >(n);
	marked = pre = vector<int> (n);
	while(q--){
		int a,b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}

	dfs(0);
	for(auto i : pre)
		cout << i << " ";
	cout << endl;
}