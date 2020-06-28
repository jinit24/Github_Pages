#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int prec(char c){

	if(c=='^')
		return 3;
	else if(c=='*' || c=='/')
		return 2;
	else if(c=='+'|| c=='-')
		return 1;
	else 
		return -1;
}

bool isOperand(char x) 
{ 
   return (x >= 'a' && x <= 'z') || 
          (x >= 'A' && x <= 'Z'); 
} 

string ItoPost(string s){
	string out="";
	stack <char> stack;
	if(s.length()==0)
		return "";

	int n = s.length();
	for(int i=0;i<n;i++){
		if(prec(s[i])!=-1){
			if(stack.empty() || stack.top()=='('){
				stack.push(s[i]);
			}
			else {
				if(prec(s[i])>prec(stack.top()))
				stack.push(s[i]);
				else{
					while(prec(stack.top())>=prec(s[i])){
						out += stack.top();
						// cout << stack.top();
						stack.pop();
						if(stack.empty())
							break;
					}
					stack.push(s[i]);

				}
			}

		}

		else if(s[i]=='(')
			stack.push(s[i]);

		else if(s[i]==')'){
			while(stack.top()!='('){
				out+=stack.top();
				// cout << stack.top();
				stack.pop();
			}
			if(!stack.empty())
			stack.pop();
		}

		else{
			out+=s[i];
			// cout << s[i];
		}
	}

	while(!stack.empty()){
		out+=stack.top();
		// cout << stack.top();
		stack.pop();
	}

	// cout << endl;
	return out;
}

string PosttoI(string s){
	stack <string> stack;
	int n = s.size();
	for(int i=0;i<n;i++){

		if(isOperand(s[i])){
			string c = "";
			c = s[i] + c;
			stack.push(c);
		}
		else{
			if(!stack.empty()){
				string s1 = stack.top();
				stack.pop();
				string s2 = stack.top();
				stack.pop();

				string out = "(" + s2 + s[i]  + s1 + ")";
				stack.push(out);
			}

		}
	}
	return stack.top();
	cout <<  stack.top() << endl;
}

string ItoPre(string s){
	reverse(s.begin(),s.end());
	string rev = "";
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==')')
			rev+="(";
		else if(s[i]=='(')
			rev+=")";
		else
			rev+=s[i];
	}
	string a = ItoPost(rev);
	reverse(a.begin(),a.end());
	return a;
}

string PretoI(string s){
	reverse(s.begin(),s.end());
	string a = PosttoI(s);
	reverse(a.begin(),a.end());
	string rev = "";
	for(int i=0;i<a.size();i++)
	{
		if(a[i]==')')
			rev+="(";
		else if(a[i]=='(')
			rev+=")";
		else
			rev+=a[i];
	}
	return rev;

}

int main(){

	string b = ItoPost("a+b*(c^d-e)^(f+g*h)-i");
	string a =  ItoPre("(a-b/c)*(a/k-l)");
	cout << PosttoI(b) << endl;
	cout << PretoI(a) << endl;
}