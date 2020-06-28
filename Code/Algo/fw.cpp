// Using Floyd-Warshall's Algorithm to find shortest distance between a given point and the rest. It takes t - test cases, indexing is from 1 onwards for 
// input and also enter from which point, the distances are to be calculated.
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

void fw(int *dp,int n,int *next){

for(int k=0;k<n;k++)
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(( *(dp + i*n + k) + *(dp + k*n + j)) < *(dp+ i*n + j)){
				*(dp+ i*n + j) = *(dp + i*n + k) + *(dp + k*n + j); 
				*(next + i*n + j) = *(next + i*n + k);
			}
}

// vector <int> constructPath(int start,int end,int *prev){
// 	vector <int> path;
// 	int temp = end;
// 	int flag=0;
// 	while( temp != start )
// 	{
// 			if(*(prev + temp) == -1){
// 				flag=1;
// 				break;
// 			}
// 			else{
// 				path.push_back(temp);
// 				temp = *(prev + temp);
		
// 			}
// 	}
// 	if(flag==0)
// 		path.push_back(start);

// 	// Reversing the vector (in O(n))
// 	reverse(path.begin(),path.end());		

// 	return path;
// }

int main(){

		int n,q;
		cin >> n >> q;	
		// vector <p> arr[n];
		int arr[n][n] = { };
		int dp[n][n] = { };
		int next[n][n] = { };
		for(int i=0;i<n;i++)
			fill(next[i],next[i]+n,-1);

		// Making the adjacency matrix
		while(q--)
		{
			int a,b,c;
			cin >> a >> b >> c;

			next[a-1][b-1] = b-1;
			if(arr[a-1][b-1]==0){
				arr[a-1][b-1]=c;
				arr[b-1][a-1]=c;
				dp[a-1][b-1]=c;
				dp[b-1][a-1]=c;
			}
			// For multiple edges,taking the smallest for algorithm
			else if(arr[a-1][b-1]!=0 && (c<arr[a-1][b-1])){
					arr[a-1][b-1]=c;
					arr[b-1][a-1]=c;
					dp[a-1][b-1]=c;
					dp[b-1][a-1]=c;
			}

		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(dp[i][j]==0 && i!=j)
					dp[i][j]=INF;


		cout << "The adjacency matrix is : " << endl;
		// Printing the adjacency matrix
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << "The adjacency matrix is : " << endl;
		// Printing the adjacency matrix
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dp[i][j]==INF)
					cout << "INF ";
				else
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}

		fw(&dp[0][0],n,&next[0][0]);

		cout << "The distance matrix is : " << endl;
		// Printing the adjacency matrix
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				if(dp[i][j]==INF)
					cout << "INF ";
				else
				cout << dp[i][j] << " ";
			cout << endl;
		}


}