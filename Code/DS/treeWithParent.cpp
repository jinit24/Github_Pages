// Finds closest ancestor with same color
#include<bits/stdc++.h>
using namespace std;

struct node{

	int val;
	int color;
	node* parent;

	node(int x,int y){
		val = x;
		color = y;
		parent = NULL;
	}
};

int main(){
	int n,k;
	cin >> n >> k;
	node *arr[n];
	int values[n-1];
	for(int i=0;i<n-1;i++){
		cin >> values[i];
	}
	int a;
	for(int i=0;i<n;i++){
		cin >> a;
		arr[i] = new node(i+1,a);
	}

	for(int i=0;i<n-1;i++){
		arr[i+1]->parent = arr[values[i]-1];
	}


	int count=0;
	int flag=0;
	cout << -1 << " ";
	for(int i=1;i<n;i++){
		node *temp = arr[i];
		while(temp->parent!=NULL){
			temp = temp->parent;
		if(temp->color==arr[i]->color){
				cout << temp->val << " ";
				flag=1;
				break;
			}
		}
		if(flag==0)
			cout << -1 << " ";
		flag=0;
	}
	cout << endl;
}