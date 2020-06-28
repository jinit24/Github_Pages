#include <bits/stdc++.h>
using namespace std;

int counter=0;
void Merge(int arr[],int n,int start,int end){
	int mid = (start + end)/2;
	int p = mid-start + 1;
	int q = end-mid;
	int L[p+1];
	int R[q+1];
	// cout << "Start is : " << start << " End is : " << end << endl;
	// cout << "The L is : ";
	for(int i=0;i<p;i++){
		L[i] = arr[start+i];
		// cout << L[i] << " ";
	}
	cout << endl;
	L[p] = 100000000;
	
	cout << "The R is : ";
	for(int i=0;i<q;i++){
		R[i] = arr[i+1+mid];
		cout << R[i] << " ";
	}
	cout << endl;

	R[q] = 1000000000;

	int a = 0;
	int b = 0;
	for(int i=0;i<p+q;i++)
		if(L[a]>R[b]){
			arr[i+start] = R[b];
			b++;
			counter+= (p-a);
			// cout << "The val of p is : " << p << endl;
			// cout << "Counter is : " << counter << endl;
		}
		else{
			arr[i+start] = L[a];
			a++;
		}

}

void MergeSort(int arr[],int n,int start,int end){
	int mid = (start + end)/2;
	if(start<end){
		MergeSort(arr,n,start,mid);
		MergeSort(arr,n,mid+1,end);
		Merge(arr,n,start,end);
	}

}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i] ;
	MergeSort(arr,n,0,n-1);
	for(int i=0;i<n;i++)
		cout << arr[i] << " " ;
	cout << endl;
	cout << counter << endl;
}
