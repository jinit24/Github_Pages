// Using djikstra's Algorithm to find shortest distance between a given point and the rest. It takes t  test cases, indexing is from 1 onwards for 
// input and also enter from which pont, the distances are to be calculated.

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include<list>
#include<iterator>

using namespace std;
typedef pair<long long int, long long int> p; 
const long long int INF = 100000000000;

void dijkstra(long long int start,vector <p> arr[ ],long long int n,long long int *prev,long long int *dist,long long int *marked){
	priority_queue < p, vector <p> ,greater <p> > pq;
	pq.push(make_pair(0,start));
	*(dist + start) = 0;

	while(!pq.empty())
	{
		long long int current_distance = pq.top().first;
		long long int current_vertex = pq.top().second;
		pq.pop();

		if(*(marked + current_vertex))
			continue;
		*(marked + current_vertex) =1;

		for (auto it : arr[current_vertex]) 
        { 
			long long int neighbour = it.first;
			long long int weight = it.second;	
			long long int distance = current_distance + weight;

			if(*(dist + neighbour) > distance){
				// cout << "Distance for " << current_vertex << " to " << neighbour << " is " << distance << endl;
				// cout << current_vertex << " " << neighbour << " " << weight << endl;
				*(dist+ neighbour) = distance;
				pq.push(make_pair(distance,neighbour));
				*(prev + neighbour) = current_vertex;
			}			

		}

	}

}

vector <long long int> constructPath(long long int start,long long int end,long long int *prev){
	vector <long long int> path;
	long long int temp = end;
	long long int flag=0;
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
	long long int t;
	cin >> t;
	while(t--){
		long long int n,q;
		cin >> n >> q;	
		vector <p> arr[n];
		long long int marked[n]={ };
		long long int prev[n]={ };
		long long int dist[n];
		// for(long long int i=0;i<n;i++)
		// 	dist[i]=100000000000;
		fill(dist, dist + n, INF);
		// for(long long int i=0;i<n;i++)
		// 	prev[i]=-1;	
		fill(prev,prev+n,-1);

		// Making the adjacency matrix
		while(q--)
		{
			long long int a,b,c;
			cin >> a >> b >> c;
			arr[a-1].push_back(make_pair(b-1,c));
			arr[b-1].push_back(make_pair(a-1,c));
		}


		long long int start;
		cin >> start ;

		// cout << "The adjacency list is : " << endl;
		// // Prlong long inting the adjacency list
		// for(long long int i=0;i<n;i++){
		// 	cout << i << " -> " ;
		// 	for(long long int j=0;j<arr[i].size();j++){
		// 		cout << arr[i][j].first << " ";
		// 	}
		// 	cout << endl;
		// }

		dijkstra(start-1,arr,n,&prev[0],&dist[0],&marked[0]);

		// -1 in the matrix represents the starting polong long int in the component, from this polong long int dijkstra is started
		// cout << "The previous vertex containing array : ";
		// for(long long int i=0;i<n;i++)
		// 	cout << prev[i] << " ";
		// cout << endl;

		for(long long int i=0;i<n;i++){
			if(dist[i]==INF)
				cout << -1 << " " ;
			else if(dist[i]!=0)
				cout << dist[i] << " ";
		}
		cout << endl;		

		// vector <long long int> path = constructPath(0,n-1,&prev[0]);
		// if(path.size()==0)
		// 	cout << "-1" << endl;
		// else{
		// 	for(long long int i=0;i<path.size();i++)
		// 		cout << path[i] + 1<< " ";
		// 	cout << endl;
		// }


	}

}