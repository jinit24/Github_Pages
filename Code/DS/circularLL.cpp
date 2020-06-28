#include <iostream>

using namespace std;

struct Node{
	int val;
	Node* next;
	// Node *prev;

	Node(int x){
		val = x;
		next = NULL;
	}

};

class circular{

	private:
		Node *head,*tail;
		int size;

	public:
		circular(){
			size=0;
			head=NULL;
			tail=NULL;
		}

		circular(int x){
			Node* t = new Node(x);
			head = t;
			tail = t;
			head->next = head;
			size=1;
		}

		void addFront(int x){
			if(head==NULL){
				Node* t = new Node(x);
				head = t;
				tail = t;
				head->next = head;
				size = 1;
				return;
			}

			Node* t = new Node(x);
			t->next = head;
			head = t;
			tail->next = head;
			size++;
			return;
		}

		void addLast(int x){
			if(head==NULL){
				Node* t = new Node(x);
				head = t;
				tail = t;
				head->next = head;
				size = 1;
				return;
			}

			Node* t = new Node(x);
			tail->next = t;
			tail = t;
			t->next = head;
			size++;
			return;
		}

		void print(){
			Node *temp = head;

			do{
				cout << temp->val << " " ;
				temp= temp->next;
			}
			while(temp!=head);

			cout << endl;
			cout << "The size is : " << size << endl;
		}



};

int main(){

	circular a(10);
	a.addFront(100);
	a.addFront(200);
	a.addFront(300);
	a.addFront(400);
	a.addLast(200);
	a.addLast(300);
	a.addLast(400);


	a.print();
}