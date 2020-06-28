// Used to find longest paths,cycles and both their lengths. Indexing uses 0. Enter edges in pair like 0 1, 2 3, etc.
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

// Simplified keeps track of only marked vertices and uses linked list
void dfsSimple(long long int current,vector <int> arr[],long long int n,long long int* marked){

	*(marked + current ) =1;
	for(auto it : arr[current]) 
        if(*(marked + it)==0)
			dfsSimple(it,arr,n,marked);

}

// Gives all possibles paths printed out but still cannot store in vector 's', as we are passing copy in function
void dfsExtended(long long int current,vector <int> arr[],long long int n,vector <int> marked,vector <int> s,int* max_length){

	marked.push_back(current);
	s.push_back(current);

	int flag=0;
	// cout << "The current is : " << current  << endl;
	for (auto it : arr[current]) 
        if(find(marked.begin(), marked.end(), it) == marked.end()){
			dfsExtended(it,arr,n,marked,s,max_length);
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


void dfs(int current,int *arr,int n,vector <int> marked,vector <int> path){

	vector <int> neighbours;
	marked.push_back(current);

	// cout << "Neighbours are for current vertex "<< current  << " are: " ;
	for(int i=0;i<n;i++){
		if(*((arr + i*n)+current)==1){
			neighbours.push_back(i);
			// cout << i << " " ;
		}
	}
	// cout << endl;
	path.push_back(current);
	// cout << "Unvisited neighbours are for current vertex "<< current  << " are: " ;

	vector <int> unv;
	// cout << "Current vertex is " << current << " and its unvisited neigbours are :" ;
	for(int i=0;i<neighbours.size();i++){
		if((find(marked.begin(), marked.end(), neighbours[i]) != marked.end())==0){
			unv.push_back(neighbours[i]);
			// cout << neighbours[i] << " ";
		}
	}
	// cout << endl;

	if(path.size()>2){
		if( *(arr+ n*path.front() + path.back()) ==1) {
			cout << "There exists cycle with length : " << path.size() << " and cycle is :";
			for(int i=0;i<path.size();i++)
				cout << path[i] << " " ;
			cout << path[0] ;
			cout << endl;

		}

	}

	if(unv.size()==0){
		// cout << "End of Path for current vertex " << current << endl;
		// cout << "Path is : " ;
		// for(int i=0;i<path.size();i++)
		// 	cout << path[i] << " " ;
		// cout << endl;
		// if( *(arr+ n*path.front() + path.back()) ==1) {
		// 	cout << "There exists cycle with length : " << path.size() << " and cycle is :";
		// 	for(int i=0;i<path.size();i++)
		// 		cout << path[i] << " " ;
		// 	cout << path[0] ;
		// 	cout << endl;

		// }
	}

	// cout << endl;
	vector <int> pathnew;
	vector <int> markednew;

	// cout << "Current path is : ";
	for(int l=0;l<path.size();l++){
		pathnew.push_back(path[l]);
		markednew.push_back(marked[l]);
		// cout << path[l] << " ";
	}
	// cout << endl;

	for(int i=0;i<unv.size();i++){
		dfs(unv[i],arr,n,markednew,pathnew);
	}


}

// void cycle(int start,int current,int *arr,int n,int *marked,vector <int> path){

// 	vector <int> neighbours;
// 	*(marked + current) =1;

// 	cout << "Neighbours are for current vertex "<< current  << " are: " ;
// 	for(int i=0;i<n;i++){
// 		if(*((arr + i*n)+current)==1){
// 			neighbours.push_back(i);
// 			cout << i << " " ;
// 		}
// 	}
// 	cout << endl;
// 	path.push_back(current);
// 	// cout << "Unvisited neighbours are for current vertex "<< current  << " are: " ;
// 	int count=0;
// 	for(int i=0;i<neighbours.size();i++){
// 		if(*(marked + neighbours[i])==0){
// 			// cout << current << " " << neighbours[i] << " " << endl;
// 			// cout << "marked are: " << *(marked+0) << " " << *(marked + 1) << endl;
// 			// *(marked + neighbours[i])=1;		
// 			// cout << neighbours[i] << "HA " << endl;
// 			// path.push_back(neighbours[i]);
// 			cycle(start,neighbours[i],arr,n,marked,path);
// 			count++;
// 		}
// 	}

// 	if(count==0){
// 		cout << "End of Path for current vertex " << current << endl;

// 		cout << "Path is : " ;
// 		for(int i=0;i<path.size();i++)
// 			cout << path[i] << " " ;
// 		cout << endl;

// 		if(*((arr + n*current) + start)==1){
// 			cout << "Cycle is present " << endl;
// 			cout << "Length is :" << path.size()<< endl;
// 		}
// 	}

// }


int main(){
	int n,q;
	scanf("%d %d",&n,&q);	
	int arr[n][n]={ };
	vector <int> path;
	vector <int> marked;
	// Making the matrix
	while(q--)
	{
		int a,b;
		cin >> a >> b;
		arr[a][b]=1;
		arr[b][a]=1;
	}

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout << arr[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	for(int i=0;i<n;i++){
		dfs(i,&arr[0][0],n,marked,path);
		cout << "The path is : " ;
		// for(int i=0;i<path.size();i++)
		// 	cout << path[i] << " " ;
		// cout << endl;
		marked.clear();
		path.clear();

	}


}