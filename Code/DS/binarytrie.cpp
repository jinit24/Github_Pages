#include <bits/stdc++.h>
using namespace std;

struct node{
	int val;
	int end;
	int size;
	node* next[2];
	node(){
		size=val=end=0;
		next[0]=next[1]=nullptr;
	}
};

node* root;

void insert(int x){
	node *temp = root;
	for(int i=31;i>=0;i--){
		bool t = (x & (1<<i));
		if(temp->next[t]==nullptr)
			temp->next[t]=new node();
		temp = temp->next[t];
		temp->size++;
	}
	temp->end++;
	temp->val = x;
}

void deleteWord(int x){
	node *temp = root;
	for(int i=31;i>=0;i--){
		bool t = (x & (1<<i));
		if(temp->next[t]==nullptr)
			break;
		temp = temp->next[t];
		temp->size--;
	}

	temp->end--;
	temp = root;
	for(int i=31;i>=0;i--){
		bool t = (x & (1<<i));
		if(temp->next[t]->size==0)
		{
			temp->next[t]=nullptr;
			return;
		}
		temp = temp->next[t];

	}
}

int maxXor(int x){
	node *temp = root;
	for(int i=31;i>=0;i--){
		bool t = (x & (1<<i));
		if(temp->next[1-t]!=nullptr)
			temp = temp->next[1-t];
		else
			temp = temp->next[t];
	}
	return temp->val;
}

int main(){
	root = new node();
	unordered_map <node*,int> hash;
	hash[root]++;
	if(hash[root])
		cout << root->val << endl;
	// hash[a]++;
	// int n;
	// cin >> n;
	// insert(0);
	// for(int i=0;i<n;i++){
	// 	char a;
	// 	int b;
	// 	cin >> a >> b;
	// 	if(a=='+')
	// 		insert(b);
	// 	else if(a == '-')
	// 		deleteWord(b);
	// 	else
	// 		cout << (b^maxXor(b)) << endl;
	// }


}