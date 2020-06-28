#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int> 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector <int> d1,d2;
int n;
string s;

// d1[i] stores half the length of maximum palindrome with i as center for odd legnthed palindromes (length = ((d1[i]-1)*2 + 1)) 
// d2[i] stores half the length of maximum palindrome with i as center for odd legnthed palindromes (length = ((d1[i])*2 ))
// Maximum of d1 and d2 will give longest substring

void Manacher(){
	for(int i=0 ,l=0,r=-1;i<n;i++){
		int k = (i>r) ? 1 : min(d1[l+r-i],r-i+1);
		while( i-k>=0 && i+k<n && s[i-k]==s[i+k])
			k++;
		d1[i]=k;
		k--;
		while(i+k>r){
			l = i-k;
			r = i+k;
		}
	}

	for(int i=0 ,l=0,r=-1;i<n;i++){
		int k = (i>r) ? 0 : min(d2[l+r-i+1],r-i+1);
		while( (i-k-1)>=0 && i+k<n && s[i-k-1]==s[i+k])
			k++;
		d2[i]=k;
		k--;
		while(i+k>r){
			l = i-k-1;
			r = i+k;
		}
	}
}


int32_t main(){
	cin >> s;
	n  = s.size();
	d2 = d1 = vector<int>(n);
	Manacher();
	// for(auto it : d1)
	// 	cout << it << ' ';
	// cout << endl;
	// for(auto it : d2)
	// 	cout << it << ' ';
	// cout << endl;

	// Longest palindromic suffix is found here
	// Used to solve minimum number of characters to append to make string palindrome
	int maxv=-1;
	int maxi = 0;
	int arr = 0;
    for(int i=0;i<n;i++){
        if(d1[i]+i==n)
        {
            if(((d1[i]-1)*2 + 1) > maxv){
                maxv = ((d1[i]-1)*2 + 1);
                maxi = i;
                arr = 0;
            }
        }
        if(d2[i]+i==n){
            if(((d2[i])*2 ) > maxv){
                maxv = ((d2[i])*2);
                maxi = i;
                arr = 1;
            }            

        }
    }

    if(arr==0){
        string a = s.substr(0,maxi - d1[maxi]+1);
        string b = a;
        reverse(b.begin(),b.end());
        cout << a + s.substr(maxi - d1[maxi]+1,maxi+d1[maxi]) + b << endl;
    }
    else{
        // cout << s.substr(maxi - d2[maxi],maxi+d2[maxi]) << endl;
        // cout << maxv << " " << maxi;
        string a = s.substr(0,maxi - d2[maxi]);
        string b = a;
        reverse(b.begin(),b.end());
        cout << a + s.substr(maxi - d2[maxi],maxi+d2[maxi]) + b << endl;
        
    }

}