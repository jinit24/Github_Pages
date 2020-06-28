#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility> 

using namespace std;

int bfsCount(int start,int *arr,int n,int *marked,int *prev,int color){
	int count=0;
	queue <int> q;
	*(marked + start) = color;
	count++;

	q.push(start);
	while(!q.empty())
	{
		int head = q.front();
		q.pop();
		for(int i=0;i<n;i++)
			if( (*((arr + (i*n)) + head) ==1) && marked[i]==0){
				q.push(i);
				*(prev + i) = head;
				*(marked + i) = color;
				count++;
			}

	}
	return count;
}

bool connected(int start,int *tp,int n){
	int markedNew[n]={ };
	int prevNew[n]={ };
	for(int i=0;i<n;i++)
		prevNew[i]=-1;

	if(bfsCount(start,tp,n,&markedNew[0],&prevNew[0],1)==n)
		return true;

	return false;	

}

vector < pair<int,int> > bridgingEdgeForConnected(int *arr,vector < pair<int,int> > edges,int n){

	vector < pair<int,int> > bridgeArr;
	for(int i=0;i<edges.size();i++)
	{
		*(arr + edges[i].first*n + edges[i].second) = 0;
		*(arr + edges[i].second*n + edges[i].first) = 0;

		if( !connected(0,arr,n) ){
			bridgeArr.push_back( 	make_pair(edges[i].first,edges[i].second)	);
		}

		*(arr + edges[i].first*n + edges[i].second) = 1;
		*(arr + edges[i].second*n + edges[i].first) = 1;

	}
	
	return bridgeArr;

}

int main(){
	int n,q;
	scanf("%d %d",&n,&q);	
	int arr[n][n]={ };
	int marked[n]={ };
	int degree[n]={ };
	vector < pair<int,int> > edges;

	// Making the adjacency matrix
	while(q--)
	{
		int a,b;
		cin >> a >> b;
		arr[a][b]=1;
		arr[b][a]=1;
		degree[a]++;
		degree[b]++;
		edges.push_back(make_pair(a,b));

	}

	// Printing the edges
	cout << "The edges are : " ;  
	for (int i = 0; i < edges.size(); ++i)
		cout << "( " << edges[i].first << "," << edges[i].second << " ) ";
	cout << endl;
	//// Printing the adjacency matrix
	cout << "The adjacency matrix is :" << endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	// Printing the degrees of vertices
	cout << "The degrees of vertices are :" << endl;
	for (int i = 0; i < n; ++i){
		cout << degree[i] << " ";
	}
	cout << endl;	

	int flag=0;
	for(int i=0;i<n;i++)
		if(degree[i]%2==1){
			flag=1;
			break;
		}

	if(flag)
		cout << "Euler Cycle : No" << endl;
	else
	{
		cout << "Euler Cycle : Yes" << endl;
		vector < pair<int,int> > bridgeEdgeConnected = bridgingEdgeForConnected(&arr[0][0],edges,n);;
		cout << "The bridging edges are : ";
		for (int i = 0; i < bridgeEdgeConnected.size(); ++i)
			cout << "( " << bridgeEdgeConnected[i].first << "," << bridgeEdgeConnected[i].second << " ) ";
		cout << endl;

		int bridgingArr[n][n] = { };
		if(bridgeEdgeConnected.size()!=0)
			for(int i=0;i<n;i++){
				bridgingArr[bridgeEdgeConnected[i].first][bridgeEdgeConnected[i].second]=1;
				bridgingArr[bridgeEdgeConnected[i].second][bridgeEdgeConnected[i].first]=1;
			}

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout << bridgingArr[i][j] << " ";
			cout << endl;
		}

		vector <int> euler;
		euler.push_back(0);
		while(!edges.empty())
		{
			
			int last = euler.back();
			for(int i=0;i<n;i++){
				if(arr[i][last]==1){
					edges.erase(std::remove(edges.begin(), edges.end(), make_pair(last,i)), edges.end());
					edges.erase(std::remove(edges.begin(), edges.end(), make_pair(i,last)), edges.end());
					euler.push_back(i);
				}
			}

		}

		for(int i=0;i<n;i++){
				cout << euler[i]<< " ";
		}		
		cout << endl;

		




	}

}
