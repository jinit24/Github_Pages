#include <bits/stdc++.h>
using namespace std;

int counts;

void dfsP(vector <int> graph[],int start,int marked[],vector <int> &compo){
	counts++;
	compo.push_back(start);
	marked[start]=1;
	cout << start << " ";
	int flag=0;
	for(int i=0;i<graph[start].size();i++){
		if(marked[graph[start][i]]==0){
			dfsP(graph,graph[start][i],marked,compo);
			flag=1;
		}
	}
}

void dfs(vector <int> graph[],int start,int marked[],stack <int> &s){
	marked[start]=1;
	int flag=0;
	for(int i=0;i<graph[start].size();i++){
		if(marked[graph[start][i]]==0){
			dfs(graph,graph[start][i],marked,s);
			flag=1;
		}
	}
	s.push(start);
}

void dfsExtended(int current,vector <int> arr[],int n,vector <int> marked,vector <int> s,int* max_length){

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


void print(stack <int> s){
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

int comp(vector <int> graph[],stack <int> &s,int marked[]){
	int max=0;
	while(!s.empty()){
		int top = s.top();
		s.pop();

		if(marked[top]==0){
			counts=0;
			vector <int> compo;
			cout << "Component : ";
			dfsP(graph,top,marked,compo);
			cout << endl;
			cout << "Vector is : ";

			for(int i=0;i<compo.size();i++)
				cout << compo[i] << " "; 
			cout << endl;
			compo.clear();
			if(counts>max)
				max = counts;
			cout << "The count is : " << counts;
			cout << endl;
		}
	}

	return max;
}


int main(){
	int t;
	cin >> t;
	while(t--){
		int n,q;
		cin >> n >> q;
		vector <int>  graph[n];
		vector <int>  graph_t[n];
		stack <int> s;
		while(q--){
			int a, b;
			cin >> a >> b;
			if(find(graph[a].begin(), graph[a].end(), b)==graph[a].end())
				graph[a].push_back(b);
			if(find(graph_t[b].begin(), graph_t[b].end(), a)==graph_t[b].end())
				graph_t[b].push_back(a);
		}
		cout << "The adjacency list is : " << endl;
		for(long long int i=0;i<n;i++){
			cout << i << " -> " ;
			for(long long int j=0;j<graph[i].size();j++){
				cout << graph[i][j] << " ";
			}
			cout << endl;
		}
		for(long long int i=0;i<n;i++){
			cout << i << " -> " ;
			for(long long int j=0;j<graph_t[i].size();j++){
				cout << graph_t[i][j] << " ";
			}
			cout << endl;
		}




		int marked[n]={};
		dfs(graph,0,marked,s);
		// for(int i=0;i<n;i++)
		// 	cout << marked[i] << " ";

		// cout << endl;
		// print(s);
		int marked_new[n]={};
		vector <int> marked_t;
		vector <int> s_t;

		// cout << "HAAA " << comp(graph_t,s,marked_new) << endl;
		int max_length=0;
		dfsExtended(s.top(),graph_t,n,marked_t,s_t,&max_length);
		s.pop();
		dfsExtended(s.top(),graph_t,n,marked_t,s_t,&max_length);
		s.pop();
		dfsExtended(s.top(),graph_t,n,marked_t,s_t,&max_length);
		

		cout << max_length << endl;
	}
}