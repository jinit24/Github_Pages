#include <bits/stdc++.h>
using namespace std;

// 1-indexed tree
vector<int> arr,tree;
int n;

// Time complexity O(n)
void buildTree(){
	for(int i=1;i<=n;i++){
		int p = i + (i & -i);
		if(p<=n)
			tree[p] += tree[i];
	}
}

// Time complexity O(log(n))
int sum(int i){
	int sum=0;
	while(i!=0){
		sum += tree[i];
		i-= (i & -i);
	}
	return sum;
}

// Sum from index i to j ,both included and indexed 1
int sumQueries(int i,int j){
	return sum(j) - sum(i-1);
}

// Time complexity O(log(n))
void pointAdd(int i,int x){
	while(i<=n){
		tree[i]+=x;
		i += (i&-i);
	}
}

// Can be better 
void rangeAdd(int l,int r,int x){
	for(int i=l;i<=r;i++)
		pointAdd(i,x);
}


int main(){
	cin >> n;
	arr = tree = vector<int>(n+1);
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		tree[i] = arr[i];
	}
	buildTree();
	for(auto i : tree)
		cout << i << " ";
	cout << endl;

	rangeAdd(1,4,5);
	for(auto i : tree)
		cout << i << " ";
	cout << endl;

	// pointAdd(3,10);
	cout << sumQueries(1,6);

}
