#include <iostream>
#include <vector>
using namespace std;



int sumOfTree(int tree[],int node,int start_s,int end_s,int start_range,int end_range){

	if(start_s>end_range || end_s<start_range)
		return 0;
	if(start_s<=start_range && end_s>=end_range)
		return tree[node];

	int mid=(start_range+end_range)/2;
	int sum_left = sumOfTree(tree,2*node,start_s,end_s,start_range,mid);
	int sum_right = sumOfTree(tree,2*node+1,start_s,end_s,mid+1,end_range);
	return sum_left + sum_right;


}

void updateTree(int tree[],int node,int start_q,int end_q,int start_range,int end_range,int add){

	if(start_q>end_range || end_q<start_range)
		return ;

	if(start_range==end_range){
		tree[node]+=add;
		return;
	}

	int mid = (start_range+end_range)/2;
	updateTree(tree,node*2,start_q,end_q,start_range,mid,add);
	updateTree(tree,node*2 + 1,start_q,end_q,mid+1,end_range,add);
    tree[node] = tree[node*2] + tree[node*2+1];
}


int main() {

int n,k,i,j;
cin >>k;
int arr[2*k]={};

for(i=0;i<k;i++)
	cin >> arr[k+i];
for(i=k-1;i>0;i--)
	arr[i] = arr[2*i] + arr[2*i + 1];

updateTree(arr,1,0,7,0,7,10);

for(i=0;i<2*k;i++){
	cout << arr[i] << " ";

}


// Code for Sum
int l,r,sum=0;
cin >> l >> r;
sum = sumOfTree(arr,1,l-1,r-1,0,k-1);
cout << sum << endl;


}


// }
