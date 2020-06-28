#include <bits/stdc++.h>
using namespace std;

// root is denoted by 0
// End of word is also denoted by 0

struct node{
	char val;
	int end;
	int size;
	vector <node*> next;
	vector <char> chars;
	node(char c){
		val = c;
		end = 0;
		size= 0;
	}
};

void insert(node* &root,string s){
	node* temp = root;
	for(int i=0;i<s.size();i++){
		auto it = find(temp->chars.begin(),temp->chars.end(),s[i]);
		if(it==temp->chars.end()){
			node* a = new node(s[i]);
			temp->next.push_back(a);
			temp->chars.push_back(s[i]);
			temp = a;
		}
		else{
			temp = temp->next[it-temp->chars.begin()];
		}
		temp->size++;
	}
	temp->end++;
}
int flag;
node* find(node* root,string s){
	node* temp = root;
	for(int i=0;i<s.size();i++){
		auto it = find(temp->chars.begin(),temp->chars.end(),s[i]);
		if(it==temp->chars.end()){
			flag=1;
			return temp;
		}
		temp = temp->next[it-temp->chars.begin()];
	}
	return temp;
}

void dfs(node* root){
	for(int i=0;i<root->chars.size();i++){
		cout << root->chars[i] << " " << root->next[i]->size << " " << root->next[i]->chars.size() << endl;
		dfs(root->next[i]);
	}
	if(root->chars.size()==0)
		cout << endl;
}

// This is used to find words which are prefix to other words
int main(){
	node* root = new node('0');
	int n;
	cin >> n;
	string arr[n];
	vector <string> words;

	for(int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		string b;
		cin >> b;
		flag=0;
		if(s == "add")
			insert(root,b);
		else{
			node *t = find(root,b);
			if(flag==0){
				printf("%d \n",t->size);
			}
			else{
				printf("0\n");
			}
		}
		// dfs(root);
	}

}