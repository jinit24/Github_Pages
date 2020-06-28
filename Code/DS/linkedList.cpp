#include <iostream>
#include <algorithm>

using namespace std;


struct node{
	int x;
	node *next;

	node(){
		next = NULL;
		x = 0;
	}

	node(int y){
		next = NULL;
		x = y;
	}
};

class linkedList{

	public:
	 node *head,*tail;

	public:
		linkedList(){
			head = NULL;
			tail = NULL;
		}


		void addFront(int n){
			node *temp = new node;
			temp->x = n;
			temp->next = NULL;

			if(head==NULL){
				head = temp;
				tail = temp;
			}
			else{
				temp->next = head;
				head = temp;
			}
		}

		void addLast(int n){
			node *temp = new node;
			temp->x = n;
			temp->next = NULL;

			if(head==NULL){
				head = temp;
				tail = temp;
			}
			else{
				tail->next = temp;
				tail = tail->next;
			}
		}

		void remove(int n){
			node *temp = head;

			if(head->x==n)
				head = head->next;

			while(temp->next!=NULL)
			{
				if((temp->next)->x==n){

					if(temp->next == tail){
						temp->next = NULL;
						tail = temp;
						break;
					}
					else{
						temp->next = (temp->next)->next;
						// break;
					}
				}
				temp = temp->next;
			}

		}

		void reverse(){
			node *prev = NULL;
			node *current = head;
			node *Next = NULL;
			int count=0;
			while(current != NULL)
			{
				count++;
				// cout << "HAAAA" << endl;
				Next = current->next;
				current->next = prev;
				prev = current;
				current = Next;
			}
			head = prev;
		}
		void sortedInsert( int y)
		{
		    if(head==NULL)
		    {
		        node *temp = new node(y);
		        head = temp;
		        return;
		    }
		    
		    else if(y<head->x){
		        node *temp = new node(y);
		        temp->next = head;
		        head = temp;
		        cout << "HAA";
		        return;
		    }
		    
		    node *temp = head;
		    while(temp->next!=NULL && y>(temp->next)->x){
		        temp = temp->next;
		        cout << "HAA";

		    }
		    cout << "HLLA";

		    node *temp2 = new node(y);
		    if(temp->next ==NULL)
		        temp->next = temp2;
		    else{
		    node * i = temp->next ;
		    temp->next = temp2;
		    temp2->next = i;
			}
		}
    


		void print(){
			node *temp = head;
			while(temp!=NULL){
				cout << temp->x << " ";
				temp = temp->next;
			}
			cout << endl;
		}
};


int main(){

	linkedList a;

	// a.addFront(30);
	// a.addLast(0);
	// a.addLast(100);
	// a.addLast();
	// a.addLast(100);
	a.addFront(10);
	a.remove(10);
	// a.print();
	// a.reverse();
	a.print();
	a.sortedInsert(1);
	a.sortedInsert(100);
	a.sortedInsert(12);
	a.sortedInsert(1111);

	a.print();



}