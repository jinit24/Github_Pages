// Used to find shortest distance between starting and ending points on a grid.
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

void bfsWithEnd(int start,int end,vector <int> arr[],int n,int *marked,int *prev){
	queue <int> q;
	*(marked + start) = 1;

	q.push(start);
	while(!q.empty())
	{
		int head = q.front();
		q.pop();
		for(int i=0;i<arr[head].size();i++){
			if(marked[arr[head][i]]==0){
				q.push(arr[head][i]);
				*(prev + arr[head][i]) = head;
				*(marked + arr[head][i]) = 1;
			}
		}
		if(*(marked+end)==1)
			break;

	}
}

vector <int> constructPath(int start,int end,int *prev,int *marked){
	vector <int> path;
	int temp = end;
	int flag=0;
	if(*(marked + start) == *(marked + end)){
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
	}

	return path;
}

int main(){
	int n,q;
	cout << "Enter the size of grid (n) : " << endl;	
	cin >> n ;
	int marked[n*n]={ };
	int grid[n*n][n*n]={ };
	vector <int> arr[n*n];

	for(int i=0;i<n*n;i++){
		if(i%n!=n-1){
			arr[i].push_back(i+1);
		}
		if(i+n<n*n){
			arr[i].push_back(i+n);
		}
		if(i-n>=0){
			arr[i].push_back(i-n);
		}
		if(i%n!=0){
			arr[i].push_back(i-1);
		}
	}

	int prev[n*n]={ };
	fill(prev,prev+n*n,-1);

	// cout << "The adjacency list is : " << endl;
	// // Printing the adjacency list
	// for(long long int i=0;i<n*n;i++){
	// 	cout << i << " -> " ;
	// 	for(long long int j=0;j<arr[i].size();j++){
	// 		cout << arr[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

 
	int start_x,start_y,end_x,end_y;
	cout << "Enter starting position (x,y)  : " << endl;

	cin >> start_x >> start_y;
	cout << "Enter ending position (x,y)  : " << endl;
	cin >> end_x >> end_y;

	int num_obstacles;
	cout << "Enter no. of obstacles  : " << endl;
	cin >> num_obstacles;
	int x,y;
	cout << "Enter location of obstacles (x,y) , use 0 indexing  : " << endl;
	for(int i=0;i<num_obstacles;i++)
	{
		cin >> x >> y;
		marked[x*n+y]=1;
	}	
	int start,end;
	start = n*start_x + start_y;
	end = n*end_x + end_y;

	cout << "Path between "<< "(" << start_x << "," << start_y << ")" <<" and "<< "(" << end_x << "," << end_y << ")" << " is given by : " ;
	bfsWithEnd(start,end,arr,n*n,&marked[0],&prev[0]);
	vector <int> path = constructPath(start,end,&prev[0],&marked[0]);

	for(int i=0;i<path.size();i++){
		// cout << path[i] << " " ;
		cout <<" ("<<path[i]/n<<","<<path[i]%n<<") ";
	}
	cout << endl;
	if(path.size()==0)
		cout << "No path exists." << endl;
	else
		cout << "The path length is : " << (path.size() -1 ) << endl;

	// // Different numbers 1,2 etc give different components
	// cout << "The marked vertices are : ";
	// for(int i=0;i<n*n;i++)
	// 	cout << marked[i] << " ";
	// cout << endl;


	// // -1 in the matrix represents the starting point in the component, from this point bfs is started
	// cout << "The previous vertex containing array : ";
	// for(int i=0;i<n*n;i++)
	// 	cout << prev[i] << " ";
	// cout << endl;



}