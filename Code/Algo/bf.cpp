// Using Bellman-Ford's Algorithm to find shortest distance between a given point and the rest. It takes t - test cases, indexing is from 1 onwards for 
// input and also enter from which point the distances are to be calculated.
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include<list>
#include<iterator>

using namespace std;
typedef pair<int, int> p;
const int INF = 10000000;

void fw(int start,int *arr,int n,int *prev,int *dist,vector <p> edges){
	*(dist + start ) = 0;

	// Relaxing the edges n-1 times
	for(int i=0;i<n-1;i++)
		for(auto it : edges){
			int edge_from = it.first;
			int edge_to = it.second;
			// cout << edge_from << " " << edge_to << endl;

			if( (*(dist + edge_from) + *(arr + edge_from*n + edge_to)) <  *(dist + edge_to)){
				*(dist + edge_to) = (*(dist + edge_from) + *(arr + edge_from*n + edge_to)) ;
				*(prev + edge_to ) = edge_from;
			}
		}

	//Detecting negative cycles 
	for(int i=0;i<n-1;i++)
		for(auto it : edges){
			int edge_from = it.first;
			int edge_to = it.second;
			if( (*(dist + edge_from) + *(arr + edge_from*n + edge_to)) <  *(dist + edge_to))
				*(dist + edge_to) = -INF;
		}
}

vector <int> constructPath(int start,int end,int *prev){
	vector <int> path;
	int temp = end;
	int flag=0;
	while( temp != start )
	{
			if(*(prev + temp) == -1){
				flag=1;
				break;
			}
			else{
				path.push_back(temp);
				temp = *(prev + temp);
		
			}
	}
	if(flag==0)
		path.push_back(start);

	// Reversing the vector (in O(n))
	reverse(path.begin(),path.end());		

	return path;
}

int main(){
	// int t;
	// cin >> t;
	// while(t--){

		int n,q;
		cin >> n >> q;	
		// vector <p> arr[n];
		int arr[n][n] = { };
		int prev[n]={ };
		int dist[n];
		vector < p > edges;
		fill(dist, dist + n, INF);
		fill(prev,prev+n,-1);

		// Making the adjacency matrix
		while(q--)
		{
			int a,b,c;
			cin >> a >> b >> c;

			if(arr[a-1][b-1]==0){
				arr[a-1][b-1]=c;
				arr[b-1][a-1]=c;
				edges.push_back({a-1,b-1});	
				edges.push_back({b-1,a-1});	

			}
			// For multiple edges,taking the smallest for algorithm
			else if(arr[a-1][b-1]!=0 && (c<arr[a-1][b-1])){
					arr[a-1][b-1]=c;
					arr[b-1][a-1]=c;
			}

		}

		// int start;
		// cin >> start ;

		// cout << "The adjacency matirx is : " << endl;
		// // Printing the adjacency list
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<n;j++){
		// 		cout << arr[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		fw(0,&arr[0][0],n,&prev[0],&dist[0],edges);

		// -1 in the matrix represents the starting point in the component, from this point fw is started
		// cout << "The previous vertex containing array : ";
		// for(int i=0;i<n;i++)
		// 	cout << prev[i] << " ";
		// cout << endl;

		// for(int i=0;i<n;i++){
		// 	if(dist[i]==INF)
		// 		cout << -1 << " " ;
		// 	else if(dist[i]!=0)
		// 		cout << dist[i] << " ";
		// }
		// cout << endl;		

		vector <int> path = constructPath(0,n-1,&prev[0]);
		if(path.size()==0)
			cout << "-1" << endl;
		else{
			for(int i=0;i<path.size();i++)
				cout << path[i] + 1<< " ";
			cout << endl;
		}
	// }

}