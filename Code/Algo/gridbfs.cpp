// Sample Input Example
// Enter the size of grid (n) : 
// 10
// Enter starting position (x,y)  : 
// 2 3
// Enter ending position (x,y)  : 
// 4 5
// Enter no. of obstacles  : 
// 0
// Enter location of obstacles (x,y) , use 0 indexing  : 
// Path between (2,3) and (4,5) is given by :  (2,3)  (2,4)  (2,5)  (3,5)  (4,5) 
// The path length is : 4
// 
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

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

void bfsWithEnd(int start,int end,int *arr,int n,int *marked,int *prev){
	queue <int> q;
	*(marked + start) = 1;

	q.push(start);
	while(!q.empty())
	{
		int head = q.front();
		q.pop();
		for(int i=0;i<n;i++)
			if( (*((arr + (head*n)) + i) ==1) && marked[i]==0){
				q.push(i);
				*(prev + i) = head;
				*(marked + i) = 1;

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
	for(int i=0;i<n*n;i++){
		if(i%n!=n-1){
			grid[i][i+1]=1;
		}
		if(i+n<n*n){
			grid[i][i+n]=1;

		}
		if(i-n>=0){
			grid[i][i-n]=1;
		}
		if(i%n!=0){
			grid[i][i-1]=1;
		}
	}

	int prev[n*n]={ };
	for(int i=0;i<n*n;i++)
		prev[i]=-1;	

	// cout << "The adjacency matrix is : " << endl;
	// // Printing the adjacency matrix
	// for(int i=0;i<n*n;i++){
	// 	for(int j=0;j<n*n;j++){
	// 		cout << grid[i][j] << " ";
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
	bfsWithEnd(start,end,&grid[0][0],n*n,&marked[0],&prev[0]);
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

}