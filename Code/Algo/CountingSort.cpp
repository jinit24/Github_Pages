#include <bits/stdc++.h>
using namespace std;
#define N 10000
int counter[N];

int main(){
	int n;
	cin >> n;
	vector <int> arr(n);
	// Position of arr[i] in sorted_arr is given by order
	vector <int> order(n);
	// Position of sorted_arr[i] in arr is given by order
	vector <int> order2(n);
	vector <int> sorted_arr(n);
	// All input values must lie between 0 and N-1  
	for(auto &it : arr)
		cin >> it;

	for(auto it : arr)
		counter[it]++;

	for(int i=1;i<N;i++)
		counter[i] += counter[i-1];

	for(int i=n-1;i>=0;i--){
		counter[arr[i]]--;
		// order[counter[arr[i]]] = i;
		sorted_arr[counter[arr[i]]] = arr[i];
		order[i] = counter[arr[i]];
		order2[counter[arr[i]]] = i;
	}
	for(auto it : sorted_arr)
		cout << it << " ";
	cout << endl;

	for(auto it : order)
		cout << it << " ";
	cout << endl;
}