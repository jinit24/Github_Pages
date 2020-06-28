#include <bits/stdc++.h>
using namespace std;


int getM(int arr[],int n){

	if(n%2==0)
		return (arr[n/2] + arr[n/2-1])/2;

	return arr[n/2];
}


// Arrays are of equal size and sorted
int ans(int arr1[],int arr2[],int n){

	if(n==0)
		return 0;
	if(n==1)
		return ( arr1[0] + arr2[0] )/2;
	if(n==2)
		return (max(arr1[0],arr2[0]) + min(arr1[1],arr2[1]) )/2;


	int m1 = getM(arr1,n);
	int m2 = getM(arr2,n);

	if(m1==m2)
		return m1;

	if(m1<m2){
		if(n%2==0)
			return ans(arr1+n/2-1,arr2,n/2+1);
		else
			return ans(arr1+n/2,arr2,n/2+1);
	}
	else{
		if(n%2==0)
			return ans(arr1,arr2+n/2-1,n/2+1);
		else
			return ans(arr1,arr2+n/2,n/2+1);
	}
}


int ans2(int arr1[],int n1,int arr2[],int n2,int odd){


	cout << n1 << " " << n2 << endl;
	if(n1==0)
		return getM(arr2,n2);
	if(n2==0)
		return getM(arr1,n1);

	if(n1==1 && n2==1)
		return ( arr1[0] + arr2[0] )/2;
	


	if(n1==1 && n2==2){

		if(arr1[0]<=arr2[0])
			return arr2[0];
		else if(arr1[0]>=arr2[0] && arr1[0]<=arr2[0])
			return arr1[0];
		else
			return arr2[1];
	}

	if(n2==1 && n1==2){
		if(arr2[0]<=arr1[0])
			return arr1[0];
		else if(arr2[0]>=arr2[0] && arr2[0]<=arr1[0])
			return arr2[0];
		else
			return arr1[1];
	}


	int m1 = (arr1[(n1-1)/2]);
	int m2 = (arr2[(n2-1)/2]);

	if(n1==2 && n2==2){

		if(odd){
			vector <int> a;
			int i=0,j=0;
			while(i<2 && j<2){
				if(arr1[i]<arr2[j]){
					a.push_back(arr1[i]);
					i++;
				}
				else{
					a.push_back(arr2[j]);
					j++;
				}
			}

			for(int t=i;t<2;t++)
				a.push_back(arr1[t]);

			for(int t=j;t<2;t++)
				a.push_back(arr2[t]);

			return a[2];
		}

		return (max(arr1[0],arr2[0]) + min(arr1[1],arr2[1]) )/2;
	}




	cout << n1 << " " << n2 << " " << m1 << " " << m2 << endl;

	if(m1==m2)
		return m1;

	if(m1>m2)
	{
		if(n2%2==0)
			return ans2(arr1,n1/2+1,arr2+n2/2-1,n2/2+1,odd);
		else
			return ans2(arr1,n1/2+1,arr2+n2/2,n2/2+1,odd);
	}

	if(m1<m2){
		if(n1%2==0)
			return ans2(arr1+n1/2-1,n1/2+1,arr2,n2/2+1,odd);
		else
			return ans2(arr1+n1/2,n1/2+1,arr2,n2/2+1,odd);
	}



}




int main(){
	// int n;
	// cin >> n;
	// int arr1[n],arr2[n];
	// for(int i=0;i<n;i++)
	// 	cin >> arr1[i];
	// for(int i=0;i<n;i++)
	// 	cin >> arr2[i];

	// cout << ans(arr1,arr2,n) << endl;

	int n1,n2;
	cin >> n1 >> n2;
	int arr1[n1],arr2[n2];
	for(int i=0;i<n1;i++)
		cin >> arr1[i];
	for(int i=0;i<n2;i++)
		cin >> arr2[i];

	cout << ans2(arr1,n1,arr2,n2,(n1+n2)%2) << endl;


}