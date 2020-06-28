#include <bits/stdc++.h>
using namespace std;

// Taking the last element as Pivot
int partitionL(int arr[],int n,int start,int end){
	int pivot = arr[end];
	int i = start;
	for(int j=start;j<end;j++)
		if(arr[j]<pivot){
			swap(arr[i],arr[j]);
			i++;
		}
	swap(arr[i],arr[end]);	
	return i;
}

// Taking the first element as Pivot
int partitionF(int arr[],int n,int start,int end){
	int pivot = arr[start];
	int i = end;
	for(int j=end;j>start;j--)
		if(arr[j]>pivot){
			swap(arr[i],arr[j]);
			i--;
		}
	swap(arr[i],arr[start]);	
	return i;
}

// Taking the Middle Element as Pivot
int partitionM(int arr[],int n,int start,int end){
	int pivot_loc = (start+end)/2;
	if(pivot_loc==start)
		return partitionM(arr,n,start,end);

	int a = partitionL(arr,n,start,pivot_loc);
	return partitionF(arr,n,a,end);

}

void QuickSort(int arr[],int n,int start,int end){
	
	if(start<end){
		int p = partitionR(arr,n,start,end);
		QuickSort(arr,n,start,p-1);
		QuickSort(arr,n,p+1,end);
	}
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i] ;
	QuickSort(arr,n,0,n-1);
	for(int i=0;i<n;i++)
		cout << arr[i] << " " ;
	cout << endl;
}