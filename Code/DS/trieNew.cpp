#include <bits/stdc++.h>
using namespace std;

struct node{
	int val;
	int size;
	int end;
	node* next[26];
	node(){
		size = 0;
		end = 0;
		val  = -1;
		for(int i=0;i<26;i++)
			next[i] = nullptr;
	}
};

node* root;

void insert(string x){
	node *temp = root;
	for(int i=0;i<x.size();i++){
		int t = x[i] - 'a';
		if(temp->next[t]==nullptr)
			temp->next[t]=new node();
		temp = temp->next[t];
		temp->size++;
	}
	temp->end++;
}

void deleteWord(string x){
	node *temp = root;
	for(int i=0;i<x.size();i++){
		int t = x[i] - 'a';
		if(temp->next[t]==nullptr)
			break;
		temp = temp->next[t];
		temp->size--;
	}

	temp->end--;
	temp = root;
	for(int i=0;i<x.size();i++){
		int t = x[i] - 'a';
		if(temp->next[t]->size==0)
		{
			temp->next[t]=nullptr;
			return;
		}
		temp = temp->next[t];

	}
}

// Finds Exact match
bool find(string x){
	node *temp = root;
	for(int i=0;i<x.size();i++){
		int t = x[i] - 'a';
		if(temp->next[t]==nullptr)
			return false;
		temp = temp->next[t];
	}
	return(temp->end);	
}

// Checks Prefix 
bool Pre(string x){
	node *temp = root;
	for(int i=0;i<x.size();i++){
		int t = x[i] - 'a';
		if(temp->next[t]==nullptr)
			return false;
		temp = temp->next[t];
	}
	return true;
}



int main(){
	root = new node();
	insert("Jinit");
	insert("Ji");
	insert("J");
	insert("Jaa");
	insert("aa");
	insert("cs");
	deleteWord("Jint");
	cout << find("Ji") << endl;
	cout << Pre("aa") << endl;
}