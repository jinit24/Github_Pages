// Best Approach,Used to find longest paths in a tree. Start at any random point and find the farthest node using bfs, this will be one of the endpoints of the longest path.
// Find the other longest path agai using bgs

// Naive approach , use DFS to find longest path for each node. Take maximum of all the paths

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <stack>


using namespace std;

void dfs(long long int current,vector <int> arr[],long long int n,vector <int> marked,vector <int> s,int* max_length){

	marked.push_back(current);
	s.push_back(current);

	int flag=0;
	// cout << "The current is : " << current  << endl;
	for (auto it : arr[current]) 
        if(find(marked.begin(), marked.end(), it) == marked.end()){
			dfs(it,arr,n,marked,s,max_length);
			// cout << it << " " << current << endl;
			flag=1;
		}

	if(flag==0){
		cout << "The stack is : " << endl;
		if(s.size()>*max_length)
			*max_length = s.size();

		for(int i=0;i<s.size();i++)
			cout << s[i] << " " ;
		s.clear();
		cout << endl;
	}

}


void bfs(int start,vector <int> arr[],int n,int *marked,int *prev,int *dist){
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


int main(){
	int n,q;
	cin >> n;
	q=n-1;
	vector <int> marked;
	vector <int> arr[n];
	int marked2[n] = { };
	int prev[n];
	int dist[n] = { };
	fill(prev,prev+n,-1);

	int marked3[n] = { };
	int prev2[n];
	int dist2[n] = { };
	fill(prev2,prev2+n,-1);


	while(q--)
		{
			long long int a,b;
			cin >> a >> b;
			arr[a-1].push_back(b-1);
			arr[b-1].push_back(a-1);
		}

	// vector <int> s;
	// int max_length=0;
	// for(int i=0;i<n;i++){
	// 	if(arr[i].size()==1){
	// 		dfs(i,arr,n,marked,s,&max_length);
	// 		marked.clear();
	// 		if(max_length==n)
	// 			break;
	// 	}
	// }
	// cout << max_length - 1<< endl;
	bfs(0,arr,n,&marked2[0],&prev[0],&dist[0]);
	int max_ind=0;
	for(int i=0;i<n;i++)
		if(dist[i]>dist[max_ind])
			max_ind = i;

	bfs(max_ind,arr,n,&marked3[0],&prev2[0],&dist2[0]);
	cout << *max_element(dist2,dist2+n) << endl;

}