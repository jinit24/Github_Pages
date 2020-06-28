#include <bits/stdc++.h>

using namespace std;

class queues{

public:
	int head,rear,size;
	int *arr;
	int maxSize;

	queues(int n){
		head=-1;
		rear=-1;
		size = 0;
		maxSize = n;
		arr = new int[n];	
	}

	bool isempty(){

		return (head==-1 && rear==-1);
	}

	void add(int x){
		if(isempty()){
			head++;
			rear++;
			arr[rear]=x;
			size++;
			// cout << "HAA";
			return;
		}


		if((rear+1)%maxSize==head){
			cout << "Queue is full! Cannot add " << x  << "." << endl;
			return;
		}

			rear++;
			rear = rear%maxSize;
			arr[rear] = x;
			size++;
			return;
	}

	void pop(){

		if(isempty()){
			cout << "Queue is Empty! " << endl;
			return;
		}

		if(size==1){
			size--;
			head =-1;
			rear=-1;
			return;
		}

		head++;
		head = head%maxSize;
		size--;

	}

	void print(){
		if(head>rear){
			for(int i=head;i%maxSize!=rear;i++)
				cout << arr[i%maxSize] << " " ;
			cout << arr[rear];
		cout << endl;

		}
		else{
			for(int i=head;i<=rear;i++)
				cout << arr[i] << " " ;
			cout << endl;
		}

		cout << "The Size is : " << size << endl;
	}
};
