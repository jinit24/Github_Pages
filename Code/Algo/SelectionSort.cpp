#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int arr[],int n){
	for(int i=0;i<n;i++){
		int min_index=i;
		for(int j=i;j<n;j++)
			if(arr[j]<arr[min_index])
				min_index=j;
		swap(arr[i],arr[min_index]);
	}
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i] ;
	SelectionSort(arr,n);
		// InsertionSort(arr,n,4,7);
	for(int i=0;i<n;i++)
		cout << arr[i] << " " ;
	cout << endl;
}