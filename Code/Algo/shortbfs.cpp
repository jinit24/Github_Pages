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

	int start,end;
	cin >> start >> end;

	cout << "Path between "<< start <<" and "<< end << " is given by : " ;
	bfsWithEnd(start,end,&arr[0][0],n,&marked[0],&prev[0]);
	vector <int> path = constructPath(start,end,&prev[0],&marked[0]);
	for(int i=0;i<path.size();i++)
		cout << path[i] << " ";
	cout << endl;
	cout << "The path length is : " << (path.size() -1 ) << endl;

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



}