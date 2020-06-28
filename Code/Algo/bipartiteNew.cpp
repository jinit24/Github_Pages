#include<bits/stdc++.h>
using namespace std;
vector<vector <int>> graph;
vector <int> marked;
int check;

// Marked stores colors used for nodes, if ever come across neighbour with same color check=1 
// Colors are either 1 or 2
// If check==0, then marked can be used as coloring sequence for graph
void bipartite(int start){
	queue <int> q;
	marked[start] = 1;

	q.push(start);
	while(!q.empty())
	{
		int head = q.front();
		q.pop();

		for(auto it : graph[head]){
			if(marked[it]==marked[head]){
				check=1;
				break;
			}

			if(marked[it]==0){
				q.push(it);
				if(marked[head]==1)
					marked[it] = 2;
				else if(marked[head]==2)
					marked[it]=1;
			}
		}
	}

}

int main(){
		int n;
		scanf("%lld",&n);
		graph = vector< vector <int> >(n);
		marked = vector <int>(n,0);

		for(long long int i=0;i<n;i++){
			int a,b;
			scanf("%lld %lld",&a,&b);
			graph[a-1].push_back(b-1);
			graph[b-1].push_back(a-1);

		}

		check=0;
		// Making sure all nodes are colored, (necessary for disconnected graphs)
		vector <int> unmarked;
		for(int i=0;i<n;i++)
			unmarked.push_back(i);

		while(!unmarked.empty()){
			bipartite(unmarked[0]);
			unmarked.clear();

			for(int i=0;i<n;i++)
				if(marked[i]==0)
					unmarked.push_back(i);
		}

		if(check)
			cout << " Not Bipartite" << endl;
		else
			cout << " Bipartite" << endl;
	
}