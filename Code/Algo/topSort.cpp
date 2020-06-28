#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
int n,q;
stack <int> s;
vector <vector <int> > g; 
vector <int> v,v1,p;
bool cyclic;

bool checkcycle(int a){
	v1[a]=1;
	p[a]=1;
	for(auto it : g[a])
	{
		if(p[it]==1){
			return true;
		}
		else if(!v1[it] && checkcycle(it))
			return true;
			
	}
	p[a]=2;
	return false;
}

void printS(){
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

void topSort(int a){
	if(v[a])
		return;
	v[a]=1;
	for(auto it : g[a])
	{
		if(!v[it])
			topSort(it);
	}
	s.push(a);
}

int32_t main(){
	fast_io;
	cin >> n >> q;
	g = vector <vector <int> >(n+1);
	p = v1 = v = vector <int>(n+1);
	for(int i=1;i<=q;i++)
	{
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
	}
	cyclic = false;
	for(int i=1;i<=n;i++)
		cyclic = cyclic || checkcycle(i);

	for(int i=1;i<=n;i++)
		topSort(i);

	if(!cyclic)
		printS();
	else
		cout << "Sandro fails." << endl;
}	