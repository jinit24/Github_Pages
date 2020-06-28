#include <iostream>
#include <algorithm>

using namespace std;

struct node 
{
	int x;
	node* next;
	node* previous;

};


class dll{

	private:
		node* head;
		node* tail;

	public:
		int size;
		dll(){
			head = NULL;
			tail = NULL;
			size = 0;
		}

		dll(int n){
			node *temp = new node;
			temp->x = n;
			temp->next = NULL;
			temp->previous = NULL;
			head = temp;
			tail = temp;
			size = 1;
		}

		void print(){
			node *temp = head;
			while(temp!=NULL){
				cout << temp->x << " ";
				temp = temp->next;
			}
			cout << endl;

			// node *temp2 = tail	;
			// while(temp2!=NULL){
			// 	cout << temp2->x << " ";
			// 	temp2 = temp2->previous;
			// }
			// cout << endl;
		}

		void addEnd(int n){
			if(size==0){
				node *temp = new node;
				temp->x = n;
				temp->next = NULL;
				temp->previous = NULL;
				head = temp;
				tail = temp;
				size = 1;
			}
			else{
				node *temp = new node;
				temp->x = n;
				temp->previous = tail;
				temp->next = NULL;
				tail->next = temp;
				tail = temp;
				size++;				
			}

		}

		void addFront(int n){
			if(size==0){
				node *temp = new node;
				temp->x = n;
				temp->next = NULL;
				temp->previous = NULL;
				head = temp;
				tail = temp;
				size = 1;

			}
			else{
				node *temp = new node;
				temp->x = n;
				temp->previous = NULL;
				temp->next = head;
				head->previous = temp;
				head = temp;
				size++;				
			}

		}

		void removeLast(){
			if(size==1){
				head=NULL;
				tail=NULL;
				size=0;
			}
			else if(size>1){
				node *h = tail->previous;
				h->next = NULL;
				tail = h;
				size--;
			}	
		}

		void removeFront(){
			if(size==1){
				head=NULL;
				tail=NULL;
				size=0;
			}
			else if(size>1){
				node *h = head->next;
				h->previous = NULL;
				head = h;
				size--;
			}
		}

		void remove(int n){
			if(size==1)
				removeFront();
			else if(head->x==n){
				removeFront();
			}
			else if(tail->x==n){
				removeLast();
			}
			else{
				node* temp = head;
				while(temp!=NULL){
					if(temp->x==n)
					{
						(temp->previous)->next = temp->next;
						(temp->next)->previous = temp->previous;
						size--;
						break;
					}
					temp = temp->next;
				}
			}

		}

		node* giveshead(){
			return head;
		}

		node* givestail(){
			return tail;
		}

};

