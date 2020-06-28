#include<bits/stdc++.h>
using namespace std;

struct node{

	int data;
	node* left;
	node* right;

	node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};


class tree{

	public:

		int size;
		node* root;
		vector < vector <int> > allPaths;
		tree(int x){
			root = new node(x);
			size = 1;
		}

		// Added such that all nodes in a level are filled first from the left end,then next level is added
		void addNode(int x,node* N){
			if(root==NULL){
				root = new node(x);
				size++;
				return;
			}

			node* t = N;
			queue <node*> q;
			q.push(t);
			while(!q.empty()){

				node *temp = q.front(); 
				q.pop();

				if(temp->left==NULL){
					temp->left = new node(x);
					size++;
					return;
				}
				else
					q.push(temp->left);
				

				if(temp->right==NULL){
					temp->right = new node(x);
					size++;
					return;
				}
				else
					q.push(temp->right);
				
			}
		}

		void print(node *N){
			node* temp = N;
			if(temp!=NULL){
				cout << "Node is " << temp->data ;
			}
			else{
				return;
			}
			if(temp->left!=NULL)
				cout << " left is : " << temp->left->data;
			if(temp->right!=NULL)
				cout << " Right is : " << temp->right->data;

			cout << endl;

			print(N->left);
			print(N->right);
		}

		void preorder(node *N){

			if(N!=NULL){
				cout << N->data << " ";
				preorder(N->left);
				preorder(N->right);
			}
		}

		void inorder(node *N){

			if(N!=NULL){
				inorder(N->left);
				cout << N->data << " ";
				inorder(N->right);
			}
			return;
		}

		void postorder(node *N){
			if(N!=NULL){
				postorder(N->left);
				postorder(N->right);
				cout << N->data << " ";
			}
			return;
		}

		void bfs(){
			queue <node*> q;
			q.push(root);
			while(!q.empty()){
				node *front = q.front();
				q.pop();
				cout << front->data << " ";
				if(front->left!=NULL)
					q.push(front->left);
				if(front->right!=NULL)
					q.push(front->right);
			}

			cout << endl;
		}

		// Returns if a path is possible between root and node containing x, array 'path' gives the path between them
		bool pathFind(int x,vector <int> &path,node* N){
			if(N==NULL)
				return false;

			path.push_back(N->data);

			if(N->data==x){
				return true;
			}

			if(pathFind(x,path,N->left)||pathFind(x,path,N->right))
				return true;

			path.pop_back();
			return false;

		}

		// Finds the paths from root node and takes the intersection to give the result
		int LeastCommonAncestor(int a,int b){
			vector <int> p1;
			vector <int> p2;
			bool p1_val = pathFind(a,p1,root);
			bool p2_val = pathFind(b,p2,root);

			if(p1_val && p2_val){
				int ans=-1;
				int i=0;
				while(p1[i]==p2[i]){
					ans = p1[i];
					i++;
				}
				return ans;
			}
			return -1;
		}
		
		void allPath(vector <int> &path,node *N){
			if(N==NULL)
				return;
			path.push_back(N->data);

			if(N->left==NULL && N->right==NULL){
				allPaths.push_back(path);
				return ;
			}
			else{
				allPath(path,N->left);
				allPath(path,N->right);

			}
		}

		int depthofNode(int a){
			vector <int> path;
			bool b = pathFind(a,path,root);
			return path.size() - 1;
		}

		//Maximum distance of path from root to leaf 
		int maxDepth(node *N){
			if(!N)
				return 0;
			return 1 + max(maxDepth(N->left),maxDepth(N->right));

		}

		//Minimum distance of path from root to leaf 
    	int minDepth(node* N) {
		    if(!N)
		        return 0;
		    if(N->left== NULL && N->right == NULL)
		        return 1;
		    if(N->left==NULL)
		        return minDepth(N->right)+1;
		    if(N->right==NULL)
		        return minDepth(N->left)+1;
		    return 1 + min(minDepth(N->left),minDepth(N->right));

		}

		bool isBalanced(node* root) {
        if(root==NULL)
            return true;
        
        if(abs(maxDepth(root->left)-maxDepth(root->right))<=1)
            return (isBalanced(root->left) && isBalanced(root->right));
        return false;
    	}

    	int ans;
	    int diameterOfBinaryTree(node* root) {
	        ans =1;
	        int i = depth(root);
	        return ans-1;
	        
	    }   
	    vector <int> EndPointsofDia;
		int depth(node *N){
				if(!N)
					return 0;
				int L = depth(N->left);
				int R = depth(N->right);
				if(L+R+1>ans){
					ans = L+R+1;
					cout << "ENDPOINT REACHED " << endl;
					EndPointsofDia.push_back(N->data);
				}
	            return max(L,R) + 1;

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
		    cout<<root->data<<"\n";  
		  
		    // Process left child  
		    print2DUtil(root->left, space);  
		}

};

int main(){
	tree t(1);
	t.addNode(2,t.root);
	t.addNode(3,t.root);
	t.addNode(4,t.root);
	t.addNode(5,t.root);
	t.addNode(6,t.root);
	t.addNode(7,t.root);
	// t.addNode(12,t.root);
	// t.addNode(13,t.root);
	// t.addNode(15,t.root);

	t.preorder(t.root);
	cout << endl;

	t.inorder(t.root);
	cout << endl;

	t.postorder(t.root);
	cout << endl;

	// t.bfs();
	t.print2DUtil(t.root,0);
	t.print(t.root);
	int ha = t.diameterOfBinaryTree(t.root);
	for(int i=0;i<t.EndPointsofDia.size();i++)
		cout << t.EndPointsofDia[i] << " ";
	cout << endl;
	cout << "depth is : " << t.ans << endl;
	cout << "The size is : " << t.size << endl;

	vector <int> path;

	bool a = t.pathFind(16,path,t.root);
	if(a){
		for(int i=0;i<path.size();i++)
			cout << path[i] << " ";
	}

	cout << (t.LeastCommonAncestor(1,7)) << endl;
	cout << t.depthofNode(13) << endl;
	cout << t.maxDepth(t.root) << endl;
	vector <int> news;
	t.allPath(news,t.root);
	for(int i=0;i<t.allPaths.size();i++){
		for(int j=0;j<t.allPaths[i].size();j++)
			cout << t.allPaths[i][j] << " ";
		cout << endl;
	}

	// int n;
	// cin >> n;
	// node* arr[n];
	// for(int i=0;i<n;i++)
	// 	arr[i] = new node(10);

	// // cout << arr[4]->data << endl;
	// int a,b;
	// char c;
	// for(int i=0;i<n-1;i++){
	// 	cin >> a >> b >> c;
	// 	if(c=='L'){
	// 		cout << "AAA" << endl;
	// 		arr[a-1]->left = arr[b-1];
	// 	}
	// 	else
	// 		arr[a-1]->right = arr[b-1];
	// }
	// for(int i=0;i<n;i++){
	// 	cin >> arr[i]->data;
	// }

	// for(int i=0;i<n;i++)
	// 	cout << arr[i]->data << "Left " << arr[i]->left->data << endl;






}