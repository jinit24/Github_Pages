#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


// Indexing is here from 0 and ending generally n-1, where n is total number of elements
int binarySearch(int *arr,int start,int end,int num){
	int mid = (start + end)/2;

	if(mid==start || end==start)
		return -1;

	if(num == *(arr+start))
		return start;

	if(num == *(arr+end))
		return end;

	if(num == *(arr+mid)){
		return mid;
	}
	else if(num>*(arr+mid)){
		return binarySearch(arr,mid,end,num);
	}
	else if(num<*(arr+mid)){
		return binarySearch(arr,start,mid,num);
	}
}

int binarySearch(vector <int> arr,int start,int end,int num){
	int mid = (start + end)/2;

	if( mid==start || end==start )
		return -1;

	if( num == arr[start] )
		return start;

	if( num == arr[end] )
		return end;

	if( num == arr[mid] ){
		return mid;
	}
	else if( num>arr[mid] ){
		return binarySearch(arr,mid,end,num);
	}
	else if (num<arr[mid] ){
		return binarySearch(arr,start,mid,num);
	}
}

int main(){
	int n;
	int arr[] = {10,20,32,43,51,62,81,911};
	for(int i=0;i<8;i++)
		cout << binarySearch(&arr[0],0,8,211);

}