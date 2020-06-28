// You can directly use next_permutation in-built function of c++. It is an efficient and easier way to generate all possible permutations.

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main(){
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin >> arr[i];

		int pivot=-1;

		for(int i=0;i<n-1;i++)
			if(arr[i]<arr[i+1]){
				// cout << "HAA" << endl;
				pivot = i;
			}

		if(pivot==-1)
			cout << -1 << endl;
		else{
			int nextLargest=pivot+1;
			for(int i=pivot+1;i<n;i++)
				if(arr[pivot]<arr[i])
					nextLargest = i;
			swap(arr[pivot],arr[nextLargest]);
			sort(arr+pivot+1,arr+n);

			for(int i=0;i<n;i++)
				cout << arr[i];
			cout << endl;


		}
	}

}