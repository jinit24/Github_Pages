#include <iostream>
#include "doubleLinkedList.hpp"

using namespace std;

class stack{

	private:
		dll a;

	public:
		stack(){};

		stack(int n){
			a.addFront(n);
		}

		void push(int n){
			a.addFront(n);
		}

		void pop(){
			a.removeFront();
		}

		int top(){
			return a.giveshead()->x;
		}

		void print(){
			a.print();
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
	stack s(10);
	s.push(30);
	s.push(20);
	s.push(5);
	s.push(1);
	cout << s.top() << endl;
	cout << s.back() << endl;


	s.print();
	s.pop();
	s.print();
}