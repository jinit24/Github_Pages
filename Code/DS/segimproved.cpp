#include<bits/stdc++.h>
using namespace std;

// Bestleft is same as suffix sum and bestright is same as prefix sum
// Bestright is starting from 'starting index ' and moving forward to some index such that sum of contiguous elements is highest
// Bestleft is starting from 'ending index ' and moving backwards to some index such that sum of contiguous elements is highest

struct node{
	long long int sum;
	long long int bestleftsum;
	long long int bestrightsum;
	long long int bestsum;

	node(long long int val){
		sum = bestsum = bestrightsum = bestleftsum = val;
	}

};
// 1 based indexing,sum-tree
vector <node> tree;


node merge(node A,node B){

	struct node C = node(0);
	C.sum = A.sum + B.sum;
	C.bestleftsum = max(A.bestleftsum,A.sum+B.bestleftsum);
	C.bestrightsum = max(B.bestrightsum,A.bestrightsum + B.sum);
	C.bestsum = max(max(A.bestsum,B.bestsum),A.bestrightsum+B.bestleftsum);
	return C;

}

void build(){
	for(long long int i=tree.size()/2 - 1;i>0;i--)
		tree[i] = merge(tree[2*i],tree[2*i + 1]);
}

node range_sum(long long int node,long long int start,long long int end,long long int l,long long int r){

	if(l==start && end==r)
		return tree[node];

	long long int mid = (start+end)/2;
	if(l>mid)
		return range_sum(2*node+1,mid+1,end,l,r);

	if(r<=mid)
		return range_sum(2*node,start,mid,l,r);

		return merge(range_sum(2*node,start,mid,l,mid),range_sum(2*node+1,mid+1,end,mid+1,r));

}

int main(){
	long long int n;
	cin >> n;
	long long int tree_size;
	if(pow(2, (long long int) log2(n))==n)
		tree_size = 2*n;
	else
		tree_size = 2 * pow(2,(long long int) log2(n)+1);
		
	tree = vector <node>(tree_size,0);

		// If taking input for array
	for(long long int i=0;i<n;i++){
		long long int a;
		cin >> a;
		tree[tree_size/2 + i] = node(a);
	}

	build();

	// for(auto it : tree){
	// 	cout << it.sum << " ";
	// 	cout << it.bestsum << " ";
	// 	cout << it.bestrightsum << " ";
	// 	cout << it.bestleftsum << endl;

	// }
	long long int q;
	cin >> q;
	while(q--){
		long long int l,r;
		cin >> l >> r;
		cout << range_sum(1,1,tree_size/2,l,r).bestsum << endl;
	}



}