#include<bits/stdc++.h>

using namespace std;

class HashMap{

	private:
		int *arr;

	public:
		int size;
		int marked;

		HashMap(int n){
			arr = new int[n];
			fill(arr,arr+n,-10000000);
			size = n;
			marked = 0;
		}

		int HashFunction(int n){
			return n%size;
		}

		void add(int num){
			int index = HashFunction(num);
			// cout << "Index is : " << index << endl;
			if( ( (arr[index]==-10000000) || (arr[index]==-20000000)) && marked<size){
				// cout << "Iterations : " << 0 << " and number is : " << num << endl;
				arr[index]=num;
				marked++;
				return;
			}
			else
				for(int i=0;i<size;i++)
					if(((arr[(index+i)%size]==-10000000) || (arr[(index+i)%size]==-20000000)) && marked<size){
						// cout << "Iterations : " << i << " and number is : " << num << endl;
						// cout << i << " " << num << endl;
						arr[(index+i)%size]=num;
						marked++;
						return;
					}
			cout << "CANNOT BE ENTERED "<< num << endl;
		}

		int search(int num){
			int index = HashFunction(num);
			// cout << "Index is : " << index << endl;
			if(arr[index]==num){
				return index;
			}
			else
				for(int i=0;i<size;i++)
					if(arr[(index+i)%size]==num)
						return (index+i)%size;
					else if(arr[(index+i)%size]==-10000000)
						return -1;
					

			// cout << "Iterations : " << size << " and number is : " << num << endl;
			return -1;
		}

		void print(){
			for(int i=0;i<size;i++)
				cout << arr[i] << " " ;
			cout << endl;
		} 

		void deleteNum(int num){

			int index = search(num);
			// cout << index << " for " << num << endl;
			if(index==-1){
				return;
			}
			else{
				arr[index]=-20000000;
			}
		}

};


int main(){
	HashMap h(20);
	h.add(100);
	h.add(120);
	h.add(15);
	h.add(35);
	h.add(45);
	h.add(135);
	h.add(11105);
	h.add(1203220);
	h.add(12033100);
	h.add(120160);
	h.add(12000);
	h.add(10240);
	h.add(1120);
	h.deleteNum(120);

	cout << h.search(120) << endl;
	cout << h.search(15) << endl;
	cout << h.search(1120) << endl;

	cout << "The number of marked elements are : " << h.marked << endl;

	h.print();
}

