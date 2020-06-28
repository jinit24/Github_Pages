
// Converting Binary Search tree to Balanced Search tree. First find the inOrder traversal. Use the middle element as root and add elements on left and right recursively.
    TreeNode* balanceBST(TreeNode* root) {
        vector <int> arr;
        inOrder(root,arr);
        int n = arr.size();
        TreeNode *ans = add(arr,0,n-1);
        return ans;
        
    }
    
    void inOrder(TreeNode *root,vector <int> &arr){
        if(root==NULL)
            return;
        inOrder(root->left,arr);
        arr.push_back(root->val);
        inOrder(root->right,arr);
    }
    
    TreeNode* add(vector <int> arr,int l,int r){
        if(l>r)
            return NULL;
        int m = (r+l)/2;
        TreeNode* root = new TreeNode(arr[m]);
        root->left = add(arr,l,m-1);
        root->right = add(arr,m+1,r);
        return root;
    }

// BFS result stored as vector <vector <int> > layer wise
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> s;
        if(root==NULL)
            return s;
        queue <pair <TreeNode*,int> > q;
        vector <pair <TreeNode*,int> > v;
        q.push({root,0});
        int max=0;
        while(!q.empty()){
            TreeNode *front = q.front().first;
            int val = q.front().second;
            v. push_back(q.front());
            q.pop();
            // ans.push_back(front->val);
            if(front->left!=NULL){
                q.push( {front->left,val+1} );
            }
            if(front->right!=NULL){
                q.push( {front->right,val+ 1} );
            }
            max = val+1;
        }
        vector<vector<int>> a(max);
        
        for(int i=0;i<v.size();i++){
            // cout << v[i].second << " " << endl;
            a[v[i].second].push_back(v[i].first->val);
        }
        
        return a;
    }