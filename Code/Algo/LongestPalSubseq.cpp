#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NUdp);cout.tie(NUdp)
#define int long long
int n;
string s;
vector <vector <int> > tp,dp,marked;
int maxval;
int ans(int start,int end){
	cout << start << " " << end << endl;
	if(end<0 || start>=n || start>end)
		return 0;

	if(marked[start][end]==1){
		cout << "YES" << endl;
		return dp[start][end];
	}

	marked[start][end]=1;
	if(start==end)
		return dp[start][end] = 1;

	if(s[start]==s[end]){
		return dp[start][end] = ans(start+1,end-1)+2;
	}

	return dp[start][end] = max(ans(start,end-1),ans(start+1,end));

}


int32_t main(){
	cin >> s;
	n = s.size();
	tp = dp = vector < vector <int> >(n, vector <int>(n,1));
	marked = vector < vector <int> >(n, vector <int>(n));
	// ans(0,n-1);

	// cout << " M "  << endl;
	// for(auto it : marked){
	// 	for(auto i : it)
	// 		cout << i << " ";
	// 	cout << endl;
	// }

    // for (int cl=2; cl<=n; cl++) 
    // { 
    //     for (int i=0; i<n-cl+1; i++) 
    //     { 
    //         int j = i+cl-1; 
    //         if (s[i] == s[j] && cl == 2) 
    //            dp[i][j] = 2; 
    //         else if (s[i] == s[j]) 
    //            dp[i][j] = dp[i+1][j-1] + 2; 
    //         else
    //            dp[i][j] = max(dp[i][j-1], dp[i+1][j]); 
    //     } 
    // } 

    for(int i=n-1;i>=0;i--)
    	for(int j=i+1;j<n;j++)
    	{
    		cout << i << " " << j << endl;
    		if(s[i]==s[j] && j-i==1)
    			dp[i][j] = 2;
    		else if(s[i]==s[j])
    			dp[i][j] = dp[i+1][j-1] + 2;
    		else 
    			dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
    	}

 //    for(auto it : dp){
	// 	for(auto i : it)
	// 		cout << i << " ";
	// 	cout << endl;
	// }

	cout << dp[0][n-1] << endl;
}