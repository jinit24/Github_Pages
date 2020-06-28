// Using djikstra's Algorithm to find shortest distance between a given point and the rest. It takes t - test cases, indexing is from 1 onwards for 
// input and also enter from which point, the distances are to be calculated.

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;
typedef pair<int, int> p; 
const int INF = 10000000;


void bfs(int start,int *arr,int n,int *prev,int *dist,int *marked){
	priority_queue < p, vector <p> ,greater <p> > pq;
	pq.push(make_pair(0,start));
	*(dist + start) = 0;

	while(!pq.empty())
	{
		int current_distance = pq.top().first;
		int current_vertex = pq.top().second;
		pq.pop();

		if(*(marked+current_vertex))
			continue;
		*(marked+current_vertex)=1;
		for(int i=0;i<n;i++){

			if( *(arr + i*n + current_vertex)!=0){
				int neighbour = i;
				int weight = *(arr + neighbour*n + current_vertex);
				int distance = current_distance + weight;

				if(*(dist+i) > distance){
					*(dist+i) =	distance;
					pq.push(make_pair(distance,neighbour));
					*(prev + i) = current_vertex;

				}				
			}

		}



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
	int t;
	cin >> t;
	while(t--){
		int n,q;
		scanf("%d %d",&n,&q);	
		int arr[n][n]={ };
		int marked[n]={ };
		int prev[n]={ };
		int dist[n];
		fill(dist,dist+n,INF);
		fill(prev,prev+n,-1);
		// Making the adjacency matrix
		while(q--)
		{
			int a,b,c;
			cin >> a >> b >> c;
			if(arr[a-1][b-1]==0){
				arr[a-1][b-1]=c;
				arr[b-1][a-1]=c;			
			}
			// For multiple edges,taking the smallest for algorithm
			else if(arr[a-1][b-1]!=0 && (c<arr[a-1][b-1])){
					arr[a-1][b-1]=c;
					arr[b-1][a-1]=c;
			}

		}
		int start;
		cin >> start ;

		// cout << "The adjacency matrix is : " << endl;
		// // Printing the adjacency matrix
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<n;j++){
		// 		cout << arr[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		bfs(start-1,&arr[0][0],n,&prev[0],&dist[0],&marked[0]);
		// Different numbers 1,2 etc give different components
		// cout << "The marked vertices are : ";
		// for(int i=0;i<n;i++)
		// 	cout << marked[i] << " ";
		// cout << endl;


		//// -1 in the matrix represents the starting point in the component, from this point bfs is started
		// cout << "The previous vertex containing array : ";
		// for(int i=0;i<n;i++)
		// 	cout << prev[i] << " ";
		// cout << endl;

		for(int i=0;i<n;i++){
			if(dist[i]==1000000000)
				cout << -1 << " " ;
			else if(dist[i]!=0)
				cout << dist[i] << " ";
		}
		cout << endl;		

		// vector <int> path = constructPath(0,n-1,&prev[0]);
		// if(path.size()==0)
		// 	cout << "-1" << endl;
		// else{
		// 	for(int i=0;i<path.size();i++)
		// 		cout << path[i] + 1<< " ";
		// 	cout << endl;
		// }


	}

}