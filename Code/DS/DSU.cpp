#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector <int> d;
int n;

int par(int a){
	vector <int> path;
	while(a!=d[a]){
		path.push_back(a);
		a = d[a];
	}

	for(auto it : path)
		d[it] = a;
	return a;
}

void join(int a,int b){
	d[par(b)] = par(a);
}

int find(int a){
	return par(a);
}

int main(){
	cin >> n;
	d = vector <int>(n);
	for(int i=0;i<n;i++)
		d[i] = i;

	for(auto it : d)
		cout << it << " ";
	cout << endl;

	join(1,3);
	join(1,4);
	join(2,1);


	for(auto it : d)
		cout << it << " ";
	cout << endl;
}