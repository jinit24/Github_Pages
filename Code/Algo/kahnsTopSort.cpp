#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
int n,m;
multiset <int> s;
vector <vector <int> > g; 
vector <int> in,ans;
bool cyclic;

// You can use a queue to reduce complexity but the answer is not the smallest lexicographic one
void Kahn(){
	for(int i=1;i<=n;i++)
		if(in[i]==0)
			s.insert(i);

	int count=0;
	while(!s.empty()){
		count++;
		int f = *s.begin();
		ans.push_back(f);
		s.erase(s.begin());

		for(auto it : g[f]){
			in[it]--;
			if(in[it]==0)
				s.insert(it);
		}
	}

	if(count!=n)
		cyclic = true;

}

int32_t main(){
	fast_io;
	cin >> n >> m;
	g = vector <vector <int> >(n+1);
	in = vector <int>(n+1);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		in[b]++;
	}
	cyclic = false;
	Kahn();
	if(cyclic)
		cout << "Sandro fails." << endl;
	else{
		for(auto it : ans)
			cout << it << " ";
		cout << endl;
	}

}	