#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

struct node{
	int val;
	node* right;
	node* left;

	node(int x){
		val = x;
		right = NULL;
		left = NULL;
	}
};

class bst{

	public:
		node *root;
		int size;

		bst(){
			root=NULL;
			size=0;
		}

		void add(int x,node* head){
			node *temp = new node(x);
			if(root==NULL){
				root = temp;
				size++;
				return;
			}

			node *t = head;
			while(x>t->val){
				if(t->right==NULL){
					t->right = temp;
					size++;
					break;
				}
				return add(x,t->right);
			}

			while(x<=t->val){
				if(t->left==NULL){
					t->left = temp;
					size++;
					break;
				}
				return add(x,t->left);

			}

		}

		void print(node* head){
			node *temp = head;
			if(head==root)
				cout << "Root is : " << head->val << endl;
			else
				cout << temp->val << endl;

			if(temp->left!=NULL){
				cout << "Left of " << temp->val << " : ";
				print(temp->left);
			}

			if(temp->right!=NULL){
				cout << "Right of " << temp->val << " : ";
				print(temp->right);
			}

		}

		void search(int x,node* head,vector <int> &path){
			path.push_back(head->val);
			if(head->val == x)
				return;
			if(head->val>x)
				search(x,head->left,path);

			if(head->val<x)
				search(x,head->right,path);
		}

		int maximum(){
			node *temp =root;
			int a;
			while(temp){
				a = temp->val;
				temp = temp->right;
			}
			return a;
		}

		int minimum(){
			node *temp =root;
			int a;
			while(temp){
				a = temp->val;
				temp = temp->left;
			}
			return a;
		}

		node* minNode(node *A){
			node *temp = A;
			while(temp && temp->left){
				temp = temp->left;
			}
			return temp;
		}

		node* maxNode(node *A){
			node *temp = A;
			while(temp && temp->right){
				temp = temp->right;
			}
			return temp;
		}

		bool isleaf(node *A){
			if(A==NULL)
				return false;

			if(A->left==NULL && A->right==NULL)
				return true;
			return false;
		}

		void inorder(node *A){
			if(A==NULL)
				return;
			inorder(A->left);
			cout << A->val << " ";
			inorder(A->right);
		}

		void deleteNode(node *&A,int x){
			if(A==NULL)
				return;
			if(x>A->val)
				deleteNode(A->right,x);
			else if(x<A->val)
				deleteNode(A->left,x);
			else{

				// No children
				if(isleaf(A)){
					delete A;
					A = NULL;
				}
				// One Child
				else if(A->right==NULL){
					A = A->left;
					// delete(A->left);
					// A->left = NULL;
				}
				// One Child
				else if(A->left==NULL){
					A = A->right;
					// delete(A->right);
					// A->right = NULL;

				}
				else{
				// Two Children using inorder succesor

					node *temp = minNode(A->right);
					A->val = temp->val;
					deleteNode(A->right,temp->val);

				// Two Children using inorder predecessor
					// node *temp = maxNode(A->left);
					// A->val = temp->val;
					// deleteNode(A->left,temp->val);
				}


			}

		}

		int height(node *A){
			if(A==NULL)
				return 0;
			return 1 + max(height(A->left),height(A->right));
		}

		void print2DUtil(node *root, int space)  
		{  	int COUNT =10;
		    // Base case  
		    if (root == NULL)  
		        return;  
		  
		    // Increase distance between levels  
		    space += COUNT;  
		  
		    // Process right child first  
		    print2DUtil(root->right, space);  
		  
		    // Print current node after space  
		    // count  
		    cout<<endl;  
		    for (int i = COUNT; i < space; i++)  
		        cout<<" ";  
		    cout<<root->val<<"\n";  
		  
		    // Process left child  
		    print2DUtil(root->left, space);  
		}

};

int main(){
	bst a;
	a.add(20,a.root);
	a.add(10,a.root);
	a.add(30,a.root);
	a.add(24,a.root);
	a.add(40,a.root);
	a.add(25,a.root);
	a.add(29,a.root);
	a.add(1,a.root);
	a.add(12,a.root);
	a.add(20,a.root);
	a.add(1,a.root);
	a.add(9,a.root);
	a.add(27,a.root);
	a.add(28,a.root);
	a.add(29,a.root);
	a.add(4,a.root);
	a.add(23,a.root);
	a.deleteNode(a.root,24);
	cout << "Height is : " << a.height(a.root) << endl;
	vector <int> path;
	a.search(9,a.root,path);
	for(int i=0;i<path.size();i++)
		cout << path[i] << " ";
	cout << endl;
	cout << a.maximum() << endl;
	cout << a.minimum() << endl;
	a.inorder(a.root);
	cout << endl;
	// a.print(a.root);
	a.print2DUtil(a.root,0);
}

