//Finding bridging vertices and edges. Remove edge/vertex and check if number of components are more . Run loop over all edges/vertices.

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility> 

using namespace std;
void bfs(int start,int *arr,int n,int *marked,int *prev,int color){
	queue <int> q;
	*(marked + start) = color;

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
			}

	}
}

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

int Components(int *arr,int *marked,int n,int *prev){
	vector <int> unmarked;
	for(int i=0;i<n;i++)
		if( (*(marked + i) ==0) ) 
			unmarked.push_back(i);

	int compCount=0;
	while(!unmarked.empty()){
		compCount++;
		bfs(unmarked[0],arr,n,marked,prev,compCount);
		unmarked.clear();

		for(int i=0;i<n;i++)
			if( (*(marked + i) ==0) ) 
				unmarked.push_back(i);

	}

	return compCount;
}

vector <int> bridgingVertex(int *arr,int n,int comp,vector < pair<int,int> > edges){

	vector <int> bridgeArr;
	for(int i=0;i<n;i++)
	{
		vector < pair<int,int> > edgestoremove;
		for(int j=0;j<edges.size();j++)
		{
			if ( (edges[j].first == i ) || (edges[j].second == i) )
				{
					*(arr + edges[j].first*n + edges[j].second) = 0;
					*(arr + edges[j].second*n + edges[j].first) = 0;
					edgestoremove.push_back( make_pair(edges[j].first,edges[j].second) );
				}
		}
		int markednew[n] = { };
		int prevnew[n];
		for(int i=0;i<n;i++)
			prevnew[i]=-1;	

		int compnew = Components(arr,markednew,n,prevnew);
		if( ((compnew ) > comp + 1 ))
			bridgeArr.push_back(i);

		for(int j=0;j<edgestoremove.size();j++){
			int f = edgestoremove[j].first;
			int s = edgestoremove[j].second;
			*(arr + f*n + s) =1;
			*(arr + s*n + f) =1;

		}	

	}
	return bridgeArr;
}

vector < pair<int,int> > bridgingEdge(int *arr,vector < pair<int,int> > edges,int n,int comp){

	vector < pair<int,int> > bridgeArr;
	for(int i=0;i<edges.size();i++)
	{
		*(arr + edges[i].first*n + edges[i].second) = 0;
		*(arr + edges[i].second*n + edges[i].first) = 0;

		int markednew[n] = { };
		int prevnew[n];
		for(int i=0;i<n;i++)
			prevnew[i]=-1;	

		int compnew = Components(arr,markednew,n,prevnew);
		if( ((compnew ) > comp ))
			bridgeArr.push_back( 	make_pair(edges[i].first,edges[i].second)	);

		*(arr + edges[i].first*n + edges[i].second) = 1;
		*(arr + edges[i].second*n + edges[i].first) = 1;

	}
	
	return bridgeArr;

}

vector < pair<int,int> > bridgingEdgeForConnected(int *arr,vector < pair<int,int> > edges,int n,int comp){

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
	int tp[n][n]={ };

	int marked[n]={ };
	int degree[n]={ };
	int prev[n]={ };
	vector < pair<int,int> > edges;
	for(int i=0;i<n;i++)
		prev[i]=-1;	

	// Making the adjacency matrix
	while(q--)
	{
		int a,b;
		cin >> a >> b;
		arr[a][b]=1;
		arr[b][a]=1;
		tp[a][b]=1;
		tp[b][a]=1;
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
	for (int i = 0; i < n; ++i)
		cout << degree[i] << " ";
	cout << endl;

	// cout << bfsCount(0,&arr[0][0],n,&marked[0],&prev[0],1);
	bool connectedCheck = connected(0,&arr[0][0],n);
	if(connectedCheck==1)
		cout << "The graph is connected : " << "Yes" << endl;
	else
		cout << "The graph is connected : " << "No" << endl;


	int comp = Components(&arr[0][0],&marked[0],n,&prev[0]);
	cout << "Number of components are : " << comp << endl; 

	cout << "The marked vertices are : ";
	for(int i=0;i<n;i++)
		cout << marked[i] << " ";
	cout << endl;


	// -1 in the matrix represents the starting point in the component, from this point bfs is started
	cout << "The previous vertex containing array : ";
	for(int i=0;i<n;i++)
		cout << prev[i] << " ";
	cout << endl;

	vector <int> bridgevertex = bridgingVertex(&arr[0][0],n,comp,edges);
	cout << "The bridging vertices are : ";
	for (int i = 0; i < bridgevertex.size(); ++i)
		cout << bridgevertex[i] << " ";
	cout << endl;

	vector < pair<int,int> > bridgeEdge = bridgingEdge(&arr[0][0],edges,n,comp);;
	cout << "The bridging edges are : ";
	for (int i = 0; i < bridgeEdge.size(); ++i)
		cout << "( " << bridgeEdge[i].first << "," << bridgeEdge[i].second << " ) ";
	cout << endl;

	if(connectedCheck==1){
		vector < pair<int,int> > bridgeEdgeConnected = bridgingEdgeForConnected(&arr[0][0],edges,n,comp);
		cout << "The bridging edges are : ";
		for (int i = 0; i < bridgeEdgeConnected.size(); ++i)
			cout << "( " << bridgeEdgeConnected[i].first << "," << bridgeEdgeConnected[i].second << " ) ";
		cout << endl;		
	}




}
