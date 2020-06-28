#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class stack{

private:
	queue <int> q1;
	queue <int> q2;
	int size;

public:

	stack(){
		size=0;
	}

	void add(int x){

		q1.push(x);
		for(int i=0;i<q2.size();i++){
			q1.push(q2.front());
			q2.pop();
		}

		swap(q1,q2);
		size++;
	}

	void printQueue()
	{
		//printing content of queue 
		while (!q2.empty()){
			cout<< q2.front() << " ";
			q2.pop();
		}
		cout<<endl;
	}
};

int main(){

	stack s;
	s.add(10);
	s.add(20);
	s.add(30);
	s.add(40);
	s.add(50);
	s.add(310);

	s.printQueue();
	s.printQueue();


}