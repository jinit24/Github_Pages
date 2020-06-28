#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[],int n,int start,int end){
	int count = end - start + 1;
	for(int i=1;i<count;i++){
		int j = start+i-1;
		while(j>=start && arr[j]>=arr[j+1]){
			swap(arr[j],arr[j+1]);
			j--;
		}
	}

}


int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i] ;
	InsertionSort(arr,n,3,n-3);
	for(int i=0;i<n;i++)
		cout << arr[i] << " " ;
	cout << endl;
}