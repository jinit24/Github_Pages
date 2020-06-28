#include <bits/stdc++.h>
using namespace std;

long long int num=0;
int insnum=0;

long long int Merge(long long int arr[],long long int n,long long int start,long long int end){
	long long int counts=0;
	long long int mid = (start + end)/2;
	long long int p = mid-start + 1;
	long long int q = end-mid;
	long long int L[p+1];
	long long int R[q+1];
	// cout << "Start is : " << start << " End is : " << end << endl;
	// cout << "The L is : ";
	for(long long int i=0;i<p;i++){
		L[i] = arr[start+i];
		// cout << L[i] << " ";
	}
	// cout << endl;
	L[p] = 2000000000;
	
	// cout << "The R is : ";
	for(long long int i=0;i<q;i++){
		R[i] = arr[i+1+mid];
		// cout << R[i] << " ";
	}
	// cout << endl;

	R[q] = 2000000000;

	long long int a = 0;
	long long int b = 0;
	for(long long int i=0;i<p+q;i++){
		if(L[a]>R[b]){
			arr[i+start] = R[b];
			b++;
		}
		else{
			arr[i+start] = L[a];
			a++;
		}
		if(L[a]!=2000000000 && R[b]!=2000000000)
			counts++;
	}

	return counts + 1 ;
}


void InsertionSort(long long int arr[],long long int n,long long int start,long long int end){
	long long int counts = end - start + 1;
	for(long long int i=1;i<counts;i++){
		long long int j = start+i-1;

		cout << "Start is : " << start << " " << end << endl;
		cout << arr[j] << " " << arr[j+1] << endl;
		insnum++;
		while(j>=start && arr[j]>=arr[j+1] && j+1<=end){
			swap(arr[j],arr[j+1]);
			j--;
			insnum++;
			cout << arr[j] << " " << arr[j+1] << " j" << endl;

		}
	}
	// cout << "Insert " << arr[start] <<  " " << arr[end] << " " << insnum << endl;

}

void Tim(long long int arr[],long long int n,long long int r,long long int start,long long int end)
{
	long long int mid = start + (end-start)/2;
	if(start<end && mid-start>r-1){
		// cout << start << " " << mid << " " << end << endl;
		Tim(arr,n,r,start,mid);
		Tim(arr,n,r,mid+1,end);
		num += Merge(arr,n,start,end);
	}
	if(mid-start<=r-1){
		InsertionSort(arr,n,start,mid);
		InsertionSort(arr,n,mid+1,end);
		num +=Merge(arr,n,start,end);
	}

}

int main(){
	long long int t,r;
	cin >> t >> r;
	while(t--){
		long long int n;
		cin >> n;
		long long int arr[n];
		for(long long int i=0;i<n;i++)
			cin >> arr[i] ;
		Tim(arr,n,r,0,n-1);
		// cout << insnum << endl;
		cout << insnum-1 << " " << num << endl;
		insnum = 0;
		num = 0;
		// InsertionSort(arr,n,4,7);
		for(long long int i=0;i<n;i++)
			cout << arr[i] << " " ;
		cout << endl;
	}
}