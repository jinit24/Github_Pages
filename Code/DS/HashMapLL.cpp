#include <iostream>
#include "doubleLinkedList.hpp"

using namespace std;

class HashMap{

	private:
		dll *arr;

	public:
		int size;
		int marked;

		HashMap(int n){
			arr = new dll[n];
			size = n;
			marked = 0;
		}

		int HashFunction(int n){
			return n%size;
		}

		void add(int num){
			int index = HashFunction(num);
			arr[index].addEnd(num);
		}

		int searchNum(int num){
			int index = HashFunction(num);
			if(arr[index].search(num))
				return index;
			return -1;
		}

		void print(){
			for(int i=0;i<size;i++)
				arr[i].print();		
		} 

		void deleteNum(int num){

			int index = searchNum(num);
			// cout << index << " for " << num << endl;
			if(index==-1){
				return;
			}
			else{
				arr[index].remove(num);
			}
		}

};


int main(){

	HashMap h(5);
	h.add(10);
	h.add(110);
	h.add(101);
	h.add(22);
	h.add(31);
	h.add(5);
	h.add(6);
	h.add(26);
	h.add(777);
	h.add(34);
	h.add(3);
	h.add(13);
	h.add(30903);
	h.deleteNum(10);
	h.add(90);
	cout << h.searchNum(34) << endl;
	h.print();

}