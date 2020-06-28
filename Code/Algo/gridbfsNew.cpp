#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

// Instead of forming new adjacency matrix or list, We move up,down,right and left for next neighbours
// See constraints carefully 

int n,q;
int g[25][25];
// sp gives shortest path between two points
int sp[600][600];
int conv(int i,int j){
	return i*n + j%n;
}

void bfs(int start,vector <int> marked){
	queue <int> q;
	q.push(start);
	// marked[start]=1;
	sp[start][start]=0;
	while(!q.empty())
	{	
		int head = q.front();
		// cout << head << endl;
		q.pop();
		if(!marked[head]){
			if(head+n<n*n && marked[head+n]==0 ){
				q.push(head+n);
				sp[start][head+n]=sp[start][head]+1;
			}
			if((head+1)%n!=0 && marked[head+1]==0){
				q.push(head+1);
				sp[start][head+1]=sp[start][head]+1;
			}
			if((head)%n!=0 && marked[head-1]==0){
				q.push(head-1);
				sp[start][head-1]=sp[start][head]+1;
			}
			if(head-n>=0 && marked[head-n]==0){
				q.push(head-n);
				sp[start][head-n]=sp[start][head]+1;
			}
		}
		marked[head]=1;

	}
}

int main(){
	cin >> n >> q;
	vector <int> og(n*n);
	vector <int> marked(n*n);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			char c;
			cin >> c;
			if(c =='x'){
				g[i][j] = 1;
				og[conv(i,j)]=1;
			}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			vector <int> marked = og;
			bfs(conv(i,j),marked);
		}
	}
	for(int i=0;i<q;i++){
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		a--;b--;c--;d--;
		int ans =  sp[conv(a,b)][conv(c,d)];
		if(ans==0 && conv(a,b)!=conv(c,d))
			printf("%d \n",-1);
		else if(ans==0)
			printf("%d \n",0);
		else
			printf("%d \n",ans)
	}

}