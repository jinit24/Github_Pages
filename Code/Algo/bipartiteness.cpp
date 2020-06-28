// Used to find if graph is bipartite or not. Uses BFS to mark all vertices either 1 or 2. (Assigning colors). Then a loop is run over intial array to
// make sure no edge exists between two vertices assigned the same color. Indexing is from 1 for edges for input. Input edges as 1 2, 3 2,etc.
// Output is in indexing 0 : paths, marking etc.

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void bipartite(int start,int *arr,int n,int *marked,int *prev,int color)
{
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
				if(*(marked + head) == 1)
					*(marked + i) = 2;
				else if(*(marked + head) == 2)
					*(marked + i) = 1;

			}

	}
}

int main(){
	int t,cases=1;
	cin >> t ;
	while(t--){
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
			arr[a-1][b-1]=1;
			arr[b-1][a-1]=1;
		}

		// Printing the adjacency matrix
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<n;j++){
		// 		cout << arr[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }


		vector <int> unmarked;
		for(int i=0;i<n;i++)
			if(marked[i]==0)
				unmarked.push_back(i);

		while(!unmarked.empty()){
			bipartite(unmarked[0],&arr[0][0],n,&marked[0],&prev[0],1);
			unmarked.clear();

			for(int i=0;i<n;i++)
				if(marked[i]==0)
					unmarked.push_back(i);

		}
		// // Different numbers 1,2 etc give different components
		// cout << "The marked vertices are : ";
		// for(int i=0;i<n;i++)
		// 	cout << marked[i] << " ";
		// cout << endl;

	 	int flag=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(	(arr[i][j]==1) && (marked[i]==marked[j]) ){
					flag=1;
					break;				
				}

			}
			if(flag==1)
				break;
		}

		if(flag){
			cout << "Graph " << cases << " is bipartite!" << endl;
        }
        else{
        	cout << "Grpah " << cases << " is not bipartite!"<< endl;
        }

		cases++;
	}
	
}