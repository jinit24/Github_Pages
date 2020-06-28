#include <iostream>
#include "doubleLinkedList.hpp"

using namespace std;

class stack{

	private:
		dll a;

	public:
		int min;
		stack(){};

		stack(int n){
			min = n;
			a.addFront(n);
		}

		void push(int n){
			if(n<min){
				a.addFront(2*n-min);
				min = n;
				return;
			}
			a.addFront(n);
		}

		void pop(){
			if(top()<min){
				min = 2*min - top();
			}
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
	stack s(4);
	s.push(3);
	cout << "MIN IS : " << s.min << endl;

	s.push(20);
	cout << "MIN IS : " << s.min << endl;
	
	s.push(1);
	cout << "MIN IS : " << s.min << endl;
	
	s.pop();
	cout << "MIN IS : " << s.min << endl;

	cout << s.top() << endl;
	cout << s.back() << endl;
	cout << "MIN IS : " << s.min << endl;



	s.print();
	s.pop();
	s.print();
}