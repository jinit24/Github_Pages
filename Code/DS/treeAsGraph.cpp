// Finds the endpoints on longest path in  a tree using DFS twice to find the endpoints one after another
// Here the tree is seen as an acyclic undirected graph

#include<bits/stdc++.h>
using namespace std;

void dfs(vector <int> tree[],int start,int marked[],int dists[]){
	marked[start] = 1;

	for(int i=0;i<tree[start].size();i++){
		if(!marked[tree[start][i]]){
			dists[tree[start][i]] = dists[start] + 1;
			dfs(tree,tree[start][i],marked,dists);
		}
	}

}


int main(){
	int n;
	cin >> n;
	vector <int> tree[n];
	int a,b;
	for(int i=0;i<n-1;i++){
		cin >> a >>b;
		tree[a-1].push_back(b-1);
		tree[b-1].push_back(a-1);
	}

	// Printing the adjacency List
	// for(int i=0;i<n;i++){
	// 	cout << i << "-> ";
	// 	for(int j=0;j<tree[i].size();j++){
	// 		cout << tree[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	int marked[n] = {};
	int dists[n] = {};
	dfs(tree,0,marked,dists);
	int max=-1;
	int max_i=0;
	for(int i=0;i<n;i++)
		if(dists[i]>max){
			max = dists[i];
			max_i = i;
		}
	int marked1[n] = {};
	int dists1[n] = {};
	dfs(tree,max_i,marked1,dists1);	
	int max1=-1;
	int max_i1=0;
	for(int i=0;i<n;i++)
		if(dists1[i]>max1){
			max1 = dists1[i];
			max_i1 = i;
		}

	cout << max_i+1 << " " << max_i1+1 << endl;


}