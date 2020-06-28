#include<bits/stdc++.h>
using namespace std;

// 0 indexed minheap, children are given  2*i+1 and 2*i+2 where parent index is i
class heap{
	public:
		vector <int> h;
		unordered_map <int,int> hash;
		heap(){}
		heap(int x){
			h.push_back(x);
			hash[x] = 0;
		}

		void push(int x){
			h.push_back(x);
			int child = h.size()-1;
			int parent = (child-1)/2;
			hash[x]=child;

			// Bubbling 'up' the layers if parent node has a higher value
			while(parent>=0 && h[parent]>h[child]){
				swap(h[parent],h[child]);
				swap(hash[h[parent]],hash[h[child]]);
				child = parent;
				parent = (child-1)/2;
			}
		}

		int poll(){
			int ans = h[0];
			swap(h[0],h[h.size()-1]);
			h.pop_back();

			// Bubbling down the layers, selecting smaller child and swapping with it
			int parent = 0;
			int left_child  = 2*parent + 1;
			int right_child = 2*parent + 2;
			int smaller_child = left_child;
			if(right_child< h.size() && left_child<h.size() && h[left_child]>h[right_child])
				smaller_child = right_child;

			while(right_child< h.size() && left_child<h.size() && h[parent]>h[smaller_child]){
				swap(h[parent],h[smaller_child]);
				parent = smaller_child;
				left_child  = 2*parent + 1;
				right_child = 2*parent + 2;
				smaller_child = left_child;
				if(right_child< h.size() && left_child<h.size() && h[left_child]>h[right_child])
					smaller_child = right_child;
			}
			return ans;
		}

		void deleteNode(int x){
			// int index=0;
			// // Deletion happens in O(n)
			// // for(int i=0;i<h.size();i++)
			// // 	if(h[i]==x){
			// // 		index = i;
			// // 		break;
			// // 	}
			// Using HashMaps searching happens in O(n) but space complexity is O(n)
			int index = hash[x];
			swap(h[h.size()-1],h[index]);
			h.pop_back();

			// Bubbling down the layers, selecting smaller child and swapping with it
			int parent = index;
			int left_child  = 2*parent + 1;
			int right_child = 2*parent + 2;
			int smaller_child = left_child;
			if(right_child< h.size() && left_child<h.size() && h[left_child]>h[right_child])
				smaller_child = right_child;

			while(right_child< h.size() && left_child<h.size() && h[parent]>h[smaller_child]){
				swap(h[parent],h[smaller_child]);
				parent = smaller_child;
				left_child  = 2*parent + 1;
				right_child = 2*parent + 2;
				smaller_child = left_child;
				if(right_child< h.size() && left_child<h.size() && h[left_child]>h[right_child])
					smaller_child = right_child;
			}
		}

		void print(int i, int space)  
		{  	int COUNT =10;
			if(i>=h.size())
				return;
		    space += COUNT;  
		    print(2*i+2, space);  
		    cout<<endl;  
		    for (int i = COUNT; i < space; i++)  
		        cout<<" ";  
		    cout<<h[i]<<"\n";  
		    print(2*i+1, space);  
		}



		int getMin(){
			return h[0];
		}
};

int main(){
	heap h;
	h.push(20);
	h.push(30);
	h.push(5);
	h.push(45);
	h.push(15);
	h.push(95);
	h.push(16);
	h.push(3);
	h.push(7);
	h.push(77);
	h.print(0,10);
	h.deleteNode(5);
	h.print(0,10);

	// unordered_map<int, int>::iterator itr; 
 //    for (itr = h.hash.begin(); itr != h.hash.end(); itr++) 
 //        cout << itr->first << " " << itr->second << endl;
 //    cout << endl;

}