// Use DFS to check if all vertices are marked and check if number of edges are equal to n-1

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

void dfs(long long int current,vector <int> arr[],long long int n,long long int* marked){

	*(marked + current ) =1;
	for (auto it : arr[current]) 
        if(*(marked + it)==0)
			dfs(it,arr,n,marked);

}
int main(){
	long long int n,q;
	cin >> n >> q;
	vector <int> arr[n];
	long long int marked[n]={ };
	int edges=0;

	while(q--)
		{
			long long int a,b;
			cin >> a >> b;
			if(find(arr[a-1].begin(), arr[a-1].end(), b-1) == arr[a-1].end())
				edges++;
			arr[a-1].push_back(b-1);
			arr[b-1].push_back(a-1);
		}

	dfs(0,arr,n,&marked[0]);
	int count=0;
	for(int i=0;i<n;i++)
		if(marked[i]==1)
			count++;

	if(edges==n-1 && count==n)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}