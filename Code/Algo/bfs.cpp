// Used to find constituent and number of compoenents. Indexing uses 0. Enter edges in pair like 0 1, 2 3, etc.
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


// Uses Linkedlist for array and also measures distances from starting point
void bfsWithDistances(int start,vector <int> arr[],int n,int *marked,int *prev,int *dist){
	queue <int> q;
	*(marked + start) = 1;
	*(dist + start) = 0;

	q.push(start);
	while(!q.empty())
	{
		// cout << "HAA" << endl;
		int head = q.front();
		q.pop();
		for (auto it : arr[head]) 
        	if(*(marked + it)==0){
				*(dist + it) = *(dist + head) + 1;
				q.push(it);
				*(prev + it) = head;
				*(marked + it) = 1;
			}

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
	scanf("%d %d",&n,&q);	
	int arr[n][n]={ };
	int marked[n]={ };
	int prev[n]={ };
	for(int i=0;i<n;i++)
		prev[i]=-1;	

	// Making the adjacency matrix
	while(q--)
	{
		int a,b;
		cin >> a >> b;
		arr[a][b]=1;
		arr[b][a]=1;
	}

	cout << "The adjacency matrix is : " << endl;
	// Printing the adjacency matrix
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	// Finding constituents and number of components; and path between any two points 
	vector <int> unmarked;
	for(int i=0;i<n;i++)
		if(marked[i]==0)
			unmarked.push_back(i);

	int compCount=0;
	while(!unmarked.empty()){
		compCount++;
		bfs(unmarked[0],&arr[0][0],n,&marked[0],&prev[0],compCount);
		unmarked.clear();

		for(int i=0;i<n;i++)
			if(marked[i]==0)
				unmarked.push_back(i);

	}
	// Different numbers 1,2 etc give different components
	cout << "The marked vertices are : ";
	for(int i=0;i<n;i++)
		cout << marked[i] << " ";
	cout << endl;


	// -1 in the matrix represents the starting point in the component, from this point bfs is started
	cout << "The previous vertex containing array : ";
	for(int i=0;i<n;i++)
		cout << prev[i] << " ";
	cout << endl;

	cout << "Number of components are : " << compCount << endl; 

	cout << "Path between 0 and 2 is given by : " ;
	vector <int> path = constructPath(0,2,&prev[0],&marked[0]);
	for(int i=0;i<path.size();i++)
		cout << path[i] << " ";
	cout << endl;
}