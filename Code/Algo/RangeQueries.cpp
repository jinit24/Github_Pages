#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

int n;
int arr[n];
int sum[n];
sum[0]=arr[0];

for(int i=1;i<n;i++)
	sum[i] = sum[i-1] + arr[i];



}