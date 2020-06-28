#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int checkBalanced(string s){

	stack <char> stack;
	for(int i=0;i<s.size();i++){
		if(stack.empty())
			stack.push(s[i]);
		else 
		{
			if(stack.top()=='(' && s[i]==')')
				stack.pop();
			else if (stack.top()=='{' && s[i]=='}')z
				stack.pop();
			else if (stack.top()=='[' && s[i]==']')
				stack.pop();
			else 
				stack.push(s[i]);

		}
	}

	return stack.size();
}


int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		// if(checkBalanced(s))
			// cout << "balanced" << endl;
		// else
			// cout << "not balanced" << endl;
		cout << checkBalanced(s) << endl;

	}

}