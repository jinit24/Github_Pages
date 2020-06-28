// Used to find the minimum spanning tree for undirected graphs
#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define p pair<int,int>
#define INF 1000000000
int n,q;
stack <int> s;
vector <vector <p> > g; 
vector <int> v,par;
vector <bool> mst;
priority_queue <p, vector<p>, greater<p>> pq;

int minKey(){
	int min=INF,mini=0;
	for(int i=1;i<=n;i++)
		if(mst[i]==0 && v[i]<=min){
			mini = i;
			min = v[i];
		}
	return mini; 
}

// Works only for 'undirected Graphs'
// A vertex's value is first set to 0 then all its neighbours' values are updated,then the next smallest is chosen and same process is repeated
void prims(){
	v[1] = 0;
	for(int i=0;i<n-1;i++)
	{
		int u = minKey();
		mst[u]=1;
		for(auto it : g[u])
		{
			// cout << it.second << "";
			if(v[it.first]>it.second)
				v[it.first] = it.second;

		}
	}
}

// Using a priority queue to do the same as above, hence better complexity of O(E + V*log(E))
// Start with all univisted,add root node with 0 distance then update the value of neighbours and push to queue
// Make sure you push only unmarked/ vertices not in the mst Set already
void primsUsingPQ(){
	pq.push({0,1});
	v[1]=0;
	while(!pq.empty()){
		int to = pq.top().second;
		pq.pop();
		mst[to]=true;

		for(auto it : g[to]){
			if(!mst[it.first] && v[it.first]>it.second){
				v[it.first] = it.second;
				pq.push({v[it.first],it.first});
				par[it.first]= to;
			}
		}

	}
}


int32_t main(){
	fast_io;
	cin >> n >> q;
	g = vector <vector <p> >(n+1);
	par = v = vector <int>(n+1,INF);
	mst  = vector <bool>(n+1,false);
	for(int i=1;i<=q;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	primsUsingPQ();
	int sum=0;
	for(int i=1;i<=n;i++)
		sum +=v[i];
	cout << sum << endl;
}	