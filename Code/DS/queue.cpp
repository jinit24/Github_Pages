#include <iostream>
#include <algorithm>
#include "doubleLinkedList.hpp"
using namespace std;

class queue{

	private:
		dll a;

	public:

		queue(){}

		queue(int n){
			a.addFront(n);
		}

		void print(){
			a.print();
		}

		void push(int n){
			a.addEnd(n);
		}

		void pop(){
			a.removeFront();
		}

		int front(){
			return (a.giveshead()->x);
		}

		int back(){
			return (a.givestail()->x);

		}

		int size(){
			return a.size;
		}

		bool isEmpty(){
			if(!size())
				return true;

			return false;
		}

};

int main(){
	queue q;
	q.push(10);
	q.push(11);
	q.push(12);
	q.push(14);
	q.print();
	// q.pop();
	q.print();
	// cout << "Front is : " << q.front() << endl;
	// cout << "Back is : " << q.back() << endl;
	cout << q.isEmpty() << endl; 
	cout << "Size is : " << q.size() << endl;


}