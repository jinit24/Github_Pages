#include <bits/stdc++.h>
using namespace std;

// Finds the floor and ceil of a given number in a sorted array.

int ceil(int arr[],int num,int start,int end){

	int mid = (start + end)/2;
	if(num>arr[end])
		return -1;

	if(num<=arr[start])
		return start;
	else if(num==arr[end])
		return end;
	else if(arr[mid]==num)
		return mid;

	if(mid==end)
		return mid;

	if(arr[mid]<num && arr[mid+1]>num)
		return mid+1;

	if(arr[mid]<num && arr[end]>num)
		return ceil(arr,num,mid+1,end);

	if(arr[mid]>num && arr[start]<num)
		return ceil(arr,num,start+1,mid);

}

int floor(int arr[],int num,int start,int end){

	int mid = (start + end)/2;
	if(num<arr[start])
		return -1;

	if(num>=arr[end])
		return end;
	else if(num==arr[end])
		return end;
	else if(arr[mid]==num)
		return mid;

	if(arr[mid]>num && arr[mid-1]<num)
		return mid-1;
	if(arr[mid]<num && arr[mid+1]>num)
		return mid;

	if(arr[mid]<num && arr[end]>num)
		return floor(arr,num,mid+1,end);

	if(arr[mid]>num && arr[start]<num)
		return floor(arr,num,start,mid-1);

}

int main(){
	int n,k;
	cin >> n >> k;
	int arr[n];

	for(int i=0;i<n;i++)
		cin >> arr[i];

cout << floor(arr,k,0,n-1) << " " << ceil(arr,k,0,n-1) << endl;

	// for(int i=0;i<n;i++)
	// 	cout <<  arr[i] << "  ";
	// cout << endl;
}