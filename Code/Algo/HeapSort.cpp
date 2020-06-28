#include<bits/stdc++.h>
using namespace std;
vector <int> heap;
int n;

void heapify(int i,int k){
	int max = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if(l<k && heap[l]>heap[max])
		max = l;
	if(r<k && heap[r]>heap[max])
		max = r;
	if(max!=i){
		swap(heap[i],heap[max]);
		heapify(max,k);
	}
}

void heapSort(){
	for(int i=n/2-1;i>=0;i--)
		heapify(i,n);
	for(int i=n-1;i>0;i--){
		swap(heap[0],heap[i]);
		heapify(0,i);
	}
}


int main(){
	cin >> n;
	heap = vector <int>(n);
	for(int i=0;i<n;i++)
		cin >> heap[i];

	heapSort();
	for(auto it : heap)
		cout << it << " " ;
	cout << endl;
}